////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Header file for xlwg library.
//*FILE VERSION:    0.70.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Saturday, 11 June 2022 15:09
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#define BINLENGTH 100

#include <stdint.h>
#include <string.h>
#include "xlwgDefinitions.hpp"

class Generator
{
private:
  //Variables:
  const uint8_t wordArraySize;
  const static char *const alphabets;
  const static char vowels[7];
  char *word { };
  bool wordExists { };
  size_t correctWordCount { };
  char *wordBin[BINLENGTH] { };

  //Methods:
  inline bool checkVowel() const;
  char generateLetter() const;
  char getAlphabet(const uint8_t &index) const { return (alphabets[index]); }

public:
  //Constructor(s) and Destructor(s):
  Generator(const uint8_t &xLetters);
  Generator() = default;
  ~Generator();

  void generateWord();
  void storeWord();

  //Accessor Mathods:
  const size_t &getCorrectWordCount(void) const { return (correctWordCount); }
  char *getWord() const { return (word); }
  char *getWord(const size_t &index) const { return wordBin[index]; }
};


#endif
