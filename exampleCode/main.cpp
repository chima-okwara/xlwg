#include <iostream>
#include "../xlwg.hpp"
using namespace std;

int main()
{
  Generator gen(3);
  char ans, again;

  do
  {
    gen.generateWord();
    cout<<"Does the word exist?\nY/N\n";
    cin.get(ans);
    ans = toupper(ans);


    switch (ans)
    {
      case 'Y':
      {
        gen.verifyWord(1, 1);
        gen.storeWord();
      }

      default:
      {
        cout<<"\nWord does not exist.\n";
      }
    }
    cout<<"Generate another word?\nY/N\n";
    cin.get(again);
    again = toupper(again);
  } while(again == 'Y');

  exit(0);
}
