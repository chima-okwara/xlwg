////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Macro definitions for xlwg library.
//*FILE VERSION:    0.70
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Monday, 3 May 2021 10:27
////////////////////////////////////////////////////////////////////////////////////////////////////
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
    using int8_t = signed char;
    using uint = unsigned int;
    using uint8_t = unsigned char;
    using ulong = unsigned long;
    using uchar = uint8_t;


//Methods:
namespace xlwg
{
  void delay(const ulong &sec);   //Delay for sec seconds
  void delay_ms(const ulong &msec);
}


#endif
