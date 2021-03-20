// #include <Arduino.h>
// #include <time.h>

#ifndef GENERATOR_HPP
#include "xlwgDefinitions.hpp"
#define GENERATOR_HPP

class Generator
{
private:
  const static uint8_t letterCount;
  const static char alphabets[27];
  const static char vowels[7];
  char *word;                     //TODO: Reimplement using a smart pointer or a vector container.

  bool wordExists;
  int correctWordCount;
  char *wordBin[15] {}; //TODO: Reimplement using a smart pointer or a vector container.


  char generateLetter();
  bool checkVowel(const char *str);

public:
  Generator(const uint8_t &xLetters); //TODO: Make constructor assign size of word.
  void generateWord();
  void verifyWord(const uint8_t &button, const uint8_t &state);
  void storeWord();     //TODO: Implement the method suint8_t that it makes use of the buffer


  const char *getWord() const { return (word); }

  char *getWord(uint8_t index) const { return wordBin[index]; }
      //NOTE: If unable to get word, change line 25 to wordBin [4][15]
};


#endif
