#include <time.h>
#include <vector>
#include "xlwgDefinitions.hpp"
#include "xlwg.hpp"

const char Generator::alphabets[27] = "aeiouybcdfghjklmnpqrstvwxz";
const char Generator::vowels[7] = {A, E, I, O, U, Y ,'\0'};
bool wordExists = false;

Generator::Generator(const uint8_t &xLetters=3) :letterCount(xLetters)
{

}

bool Generator::checkVowel(const char *str) //Checks for vowel in word.
{
  bool status;
  for (uint8_t i = 0; i<3; ++i)
  {
    for (uint8_t j =0; j<7; ++j)
    {
      if (str[i] == vowels[j])
      {
        status=true;
        break;
      }
    }
  }

  return (status);
}     //TODO: Re-implement using strpbrk(*, *) function.

char Generator::generateLetter(void)  //Generates a single letter from the alphabet
{
  srand((unsigned int)time(nullptr));
  uint8_t x = rand()%26;

  return (alphabets[x]);
}

void Generator::generateWord(void)
{
  do
  {
    for (size_t i = 0; i<letterCount; ++i)
    {
      word[i] = generateLetter();
      xlwg::delay(200);
    }
    word[letterCount] = '\0';
  } while(!checkVowel(word));
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
