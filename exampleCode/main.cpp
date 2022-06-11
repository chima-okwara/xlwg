/*************************************************************************************************
****This is an example program for the xlwg word generator library.
****It should come included as an optional part of the above-mentioned project.
****Author: Chimaroke Roland Okwara
****Copyright (c) 2021 - present, The Eichen Group.
****License:    Academic Free License v3.1
****Last modified: Saturday, 11 June 2022 15:47
*************************************************************************************************/


#include <iostream>
#include "../xlwg.hpp"

using namespace std;

int main()
{
  // Generator word(5);    //Creates an object to generate three-letter words.
  uchar ans, again;
  int letters = 0;

  cout<<"How many letter words do you want to generate?\n";
  cin>>letters;

  Generator word {letters};

  do
  {
    word.generateWord();
    cout<<endl<<word.getWord()<<endl;
    cout<<"Does the word exist?\nY/N\n";
    cin>>ans;
    ans = toupper(ans);


    switch (ans)
    {
      case 'Y':
      {
        word.storeWord();
        cout<<"Word Stored"<<endl;
        break;
      }

      default:
      {
        cout<<"\nWord does not exist.\n";
        break;
      }
    }
    cout<<"Generate another word?\nY/N\n";
    cin>>again;
    again = toupper(again);
  } while(again == 'Y');

  cout<<"\nWant to view list of correct words?\nY/N\n";
  cin.sync();
  cin>>ans;   ans = toupper(ans);

  if(ans == 'Y')
  {
    if(!word.getCorrectWordCount())
    {
      cout<<"\nThere are no correct words saved.\n";
      exit(0);
    }

    cout<<"\nHere are the correct words: \n";
    for(size_t i = 0; i<word.getCorrectWordCount(); ++i)
    {
      cout<<word.getWord(i)<<endl;
    }
  }

  exit(0);
}
