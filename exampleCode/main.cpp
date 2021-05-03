/*************************************************************************************************
****This is an example program for the xlwg word generator library.
****It should come included as an optional part of the above-mentioned project.
****Author: Chimaroke Roland Okwara
****Contributor(s): -The Eichen Group
                 -Other
****Copyright (c) 2021, The Eichen Group.
****License:    Academic Free License v3.1
****Last modified: Thursday, 1 April 2021 13:50.
*************************************************************************************************/


#include <iostream>
#include "../xlwg.hpp"
using namespace std;

int main()
{
  Generator gen(5);    //Creates an object to generate three-letter words.
  uchar ans, again;

  do
  {
    gen.generateWord();
    cout<<endl<<gen.getWord()<<endl;
    cout<<"Does the word exist?\nY/N\n";
    cin>>ans;
    ans = toupper(ans);


    switch (ans)
    {
      case 'Y':
      {
        gen.verifyWord(1);
        gen.storeWord();
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
    if(!gen.getCorrectWordCount())
      cout<<"\nThere are no correct words saved.\n";
    cout<<"\nHere are the correct words: \n";
    for(size_t i = 0; i<gen.getCorrectWordCount()+1; ++i)
    {
      cout<<gen.getWord(i)<<endl;
    }
  }

  exit(0);
}
