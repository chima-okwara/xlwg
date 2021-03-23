#ifndef GEN_DEFS
#define GEN_DEFS

#include <time.h>

//Variables:
    #define A alphabets[0]
    #define E alphabets[1]
    #define I alphabets[2]
    #define O alphabets[3]
    #define U alphabets[4]
    #define Y alphabets[5]


//Types:
    typedef unsigned char uint8_t;
    typedef unsigned long ulong;


//Methods:
namespace xlwg
{
  void delay(const ulong &usec)
  {
    time_t end = time(nullptr) + ((long)(usec/1000));
    while (time(nullptr)<end);
  }
}


#endif
