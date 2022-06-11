////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Source file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Saturday, 11 June 2022 15:09
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"


const char *const Generator:: alphabets = "aeiouybcdfghjklmnpqrstvwxza";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;


Generator::Generator(const uint8_t &xLetters) :wordArraySize(xLetters+1)
{
  //Allocate memory for the word and the wordBin:
  word = new char[wordArraySize];
  for(int i = 0; i<BINLENGTH; ++i)
    wordBin[i] = new char[wordArraySize];

  //initialise the random number generator seed:
  auto seed = time(nullptr);
  srand(seed++);
}

Generator::~Generator()
{
  delete[] word;
  for(int i = 0; i<BINLENGTH; ++i)
    delete[] wordBin[i];
}

inline bool Generator::checkVowel() const        //Checks for vowel in word, returns false if none.
{
  return(strpbrk(word, vowels) != NULL) ? (true) : (false);
}

char Generator::generateLetter(void) const //Generates a single letter from the alphabet
{
  uint8_t index = rand()%26;              //Generates random number between 0 and 26
  return (getAlphabet(index));
}

void Generator::generateWord(void)
{
  do
  {
    for (int8_t i = 0; i<(wordArraySize-1); ++i)
    {
      word[i] = generateLetter();
    }

    word[wordArraySize-1] = '\0';
  } while(!checkVowel());
}


void Generator::storeWord()
{
  strcpy(wordBin[correctWordCount], word);
  ++correctWordCount;
}


void xlwg::delay(const ulong &sec)
{
    time_t wait = time(nullptr) + sec;
    while (time(nullptr) < wait);
}
