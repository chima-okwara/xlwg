#ifndef GENERATOR_HPP
#include <vector>
#include "xlwgDefinitions.hpp"
#define GENERATOR_HPP

class Generator
{
private:
  const uint8_t letterCount;
  const static char alphabets[27];
  const static char vowels[7];
  char *word;                     //TODO: Reimplement using a smart pointer or a vector container.
  bool wordExists {false};

  int correctWordCount;
  std::vector<char*> wordBin;


  char generateLetter();
  bool checkVowel(const char *str);

public:
  Generator(const uint8_t &xLetters);
  void generateWord();
  void verifyWord(bool state);
  void storeWord();


  const char *getWord() const { return (word); }

  const char *getWord(uint8_t index) const { return wordBin[index]; }
};


#endif
