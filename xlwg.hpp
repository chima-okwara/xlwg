////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Header file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Monday, 3 May 2021 10:27
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <stdint.h>
#include <string.h>
#include "xlwgDefinitions.hpp"



#define GENERATOR_HPP
#define BINLENGTH 100

class Generator
{
private:
  const int8_t wordArraySize;
  const static char *const alphabets;
  const static char vowels[7];
  char *word {nullptr};
  bool wordExists {false};
  size_t correctWordCount {0};


  char *wordBin[BINLENGTH] { };

  char generateLetter() const;
  bool checkVowel() const;

public:
  Generator(const uint8_t &xLetters);
  ~Generator();
  char getAlphabet(uint8_t index) const { return (alphabets[index]); }
  void generateWord();
  void storeWord();
  const size_t &getCorrectWordCount(void) const { return (correctWordCount); }


  const char *getWord() const { return (word); }

  const char *getWord(const size_t &index) const { return wordBin[index-1]; }
};


#endif
