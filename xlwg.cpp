////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Source file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 15 April 2021 12:05
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"

const char *const Generator:: alphabets = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;

Generator::Generator(const uint8_t &xLetters) :letterCount(xLetters+1)
{

}

bool Generator::checkVowel() const//Checks for vowel in word, returns false if none.
{
  auto status = (strpbrk(word, vowels) != NULL) ? (true) : (false);
  return (status);
}

char Generator::generateLetter(void) const //Generates a single letter from the alphabet
{
  auto seed = time(nullptr);
  srand(seed++);
  uint8_t x = rand()%26+1;
  xlwg::delay(1);
  return (getAlphabet(x));
}

void Generator::generateWord(void)
{
  do
  {
    for (int8_t i = 0; i<(letterCount); ++i)
      *(word+i) = generateLetter();

    word[letterCount-1] = '\0';
  } while(!checkVowel());
}



void Generator::storeWord()
{
  if(wordExists)
  {
    wordBin[correctWordCount] = word;
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
