#include <time.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"

const char *const Generator:: alphabets = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;

Generator::Generator(const uint8_t &xLetters) :letterCount(xLetters)
{
  char word[letterCount+1] {};
  (this->word) = word;
}

bool Generator::checkVowel() const //Checks for vowel in word, returns false if none.
{
  bool status = (strpbrk(word, vowels) != NULL) ? (true) : (false);
  return (status);
}

#include <iostream> //TODO: remove

char Generator::*generateLetter(void)  //Generates a single letter from the alphabet
{
  std::cout << "entering generateLetter()" << '\n';   //TODO: remove
  auto seed = time(nullptr);
  srand(seed++);
  uint8_t x = rand()%26+1;
  xlwg::delay(1);
  char letter = getAlphabet(x);
  std::cout << "leaving generateLetter()" << '\n';    //TODO: remove
  return (letter);
}

void Generator::generateWord(void)
{
  std::cout << "entering generateWord()" << '\n';   //TODO: remove
  do
  {
    std::cout << "entering do while() loop" << '\n';    //TODO: remove
    for (int8_t i = 0; i<(letterCount-1); ++i)
    {
      std::cout << "entering for() loop" << '\n';       //TODO: remove
      word+i = generateLetter();
      xlwg::delay(2);
    }
    std::cout << "leaving for() loop" << '\n';      //TODO: remove

    word[letterCount-1] = '\0';
  } while(!checkVowel());
  std::cout << "leaving do while() loop" << '\n';   //TODO: remove
  std::cout << "leaving generateWord()" << '\n';    //TODO: remove
}



void Generator::storeWord()
{
  if(wordExists)
  {
    wordBin.push_back(word);
    ++correctWordCount;
  }
}

void Generator::verifyWord(bool state)
{
  wordExists = ( (state == true) ? true : false );
}


void xlwg::delay(const ulong &sec)
{
    time_t wait = time(nullptr) + sec;
    while (time(nullptr) < wait);
}


void xlwg::mdelay(const ulong &msec)    //TODO: Implement using a microsecond function from time.h
{

}
