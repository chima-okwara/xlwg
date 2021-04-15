////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Header file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 15 April 2021 12:05
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <stdlib.h>
#include "xlwgDefinitions.hpp"



#define GENERATOR_HPP
#define BINLENGTH 100

class Generator
{
private:
  const int8_t letterCount;
  const static char *const alphabets;
  const static char vowels[7];
  char *word;
  bool wordExists {false};


  int correctWordCount;
  char *wordBin[BINLENGTH];

  char generateLetter() const;
  bool checkVowel() const;

public:
  Generator(const uint8_t &xLetters);
  char getAlphabet(uint8_t index) const { return (alphabets[index]); }
  void generateWord();
  void verifyWord(bool state);
  void storeWord();


  const char *getWord() const { return (word); }

  const char *getWord(uint8_t index) const { return wordBin[index]; }
};


#endif
