// #include <Arduino.h>
#include <time.h>
#include <math.h>
// #include <iostream>
// #include <avr/io.h>
#include "xlwg.hpp"

const char Generator::alphabets[27] = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;

Generator::Generator(const uint8_t &xLetters)
{

}

char Generator::generateLetter(void)  //Generates a single letter from the alphabet
{
  //Generate random number 'x':
  srand(100ul);
  register uint8_t x = rand()%26;

  return (alphabets[x]);
}

void Generator::generateWord(void) //Generates a three letter word
{
  do
  {
    for (size_t i = 0; i<3; ++i)
    {
      word[i] = generateLetter();
    }
    word[4] = '\0';
    std::cout<<"No vowel yet!\n";
  } while(!checkVowel(word));                     //...regenerate word.
}


bool Generator::checkVowel(const char *str) //Checks for vowel in word.
{
  static bool position;
  for (uint8_t i = 0; i<3; ++i)
  {
    for (uint8_t j =0; j<7; ++j)
    {
      if (str[i] == vowels[j])
      {
        position=true;
        break;
      }
    }
  }

  return (position);
}     //TODO: Re-implement using strpbrk(*, *) function.


void Generator::storeWord()
{
  if(wordExists)
  {
    wordBin[correctWordCount] = word;
    ++correctWordCount;
  }
}


void Generator::verifyWord(const uint8_t &button, const uint8_t &state)
{
  // pinMode(button, INPUT);
  wordExists = (button == state) ? true : false;
}
