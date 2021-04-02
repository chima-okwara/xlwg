#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <vector>
#include <stdlib.h>
#include "xlwgDefinitions.hpp"



#define GENERATOR_HPP

class Generator
{
private:
  const int8_t letterCount;
  const static char *const alphabets;
  const static char vowels[7];
  const char *word;                     //TODO: Reimplement using a smart pointer or a vector container.
  bool wordExists {false};


  int correctWordCount;
  std::vector<char*> wordBin;


  char *generateLetter();
  bool checkVowel() const;

public:
  Generator(const uint8_t &xLetters);
  const char *const getAlphabet(uint8_t index) const { return &(alphabets[index]); }
  void generateWord();
  void verifyWord(bool state);
  void storeWord();


  const char *getWord() const { return (word); }

  const char *getWord(uint8_t index) const { return wordBin[index]; }
};


#endif
