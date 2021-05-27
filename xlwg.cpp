////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Source file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Monday, 3 May 2021 10:27
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"


const char *const Generator:: alphabets = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;


Generator::Generator(const uint8_t &xLetters) :wordArraySize(xLetters+1), word(new char[wordArraySize])
{
  auto seed = time(nullptr);
  srand(seed++);
}

Generator::~Generator()
{
  delete[] word;
}

bool Generator::checkVowel() const        //Checks for vowel in word, returns false if none.
{
  auto status = (strpbrk(word, vowels) != NULL) ? (true) : (false);
  return (status);
}

char Generator::generateLetter(void) const //Generates a single letter from the alphabet
{
  uint8_t x = rand()%26+1;
  return (getAlphabet(x));
}

void Generator::generateWord(void)
{
  do
  {
    for (int8_t i = 0; i<(wordArraySize-1); ++i)
      word[i] = generateLetter();

    word[wordArraySize-1] = '\0';
  } while(!checkVowel());
}


void Generator::storeWord()
{
    char temp[wordArraySize] { };
    strcpy(temp, word);
    strcpy(wordBin[correctWordCount], temp);
    // wordBin[correctWordCount] = word;
    ++correctWordCount;
}


void xlwg::delay(const ulong &sec)
{
    time_t wait = time(nullptr) + sec;
    while (time(nullptr) < wait);
}
