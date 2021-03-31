#include <time.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"

const char Generator::alphabets[27] = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;

Generator::Generator(const uint8_t &xLetters) :letterCount(xLetters+1)
{

}

bool Generator::checkVowel() const //Checks for vowel in word, returns false if none.
{
  bool status = (strpbrk(word, vowels) != nullptr) ? (true) : (false);
  return (status);
}


char Generator::generateLetter(void)  //Generates a single letter from the alphabet
{
  srand((uint)time(nullptr));
  uint8_t x = rand()%26;
  xlwg::delay(1);
  return (alphabets[x]);
}

void Generator::generateWord(void)
{
  do
  {
    for (int8_t i = 0; i<(letterCount-1); ++i)
    {
      word[i] = generateLetter();
      xlwg::delay(2);
    }


    word[letterCount-1] = '\0';
  } while(!checkVowel());
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
