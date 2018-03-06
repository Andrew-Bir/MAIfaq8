//               testadec.cpp
#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Adec;
///////////////////////
//  Постоить автомат
  addrange(Adec,0,'1','9',1);
  addstr(Adec,0,".",2);
  addstr(Adec,0,"0",3);
  addstr(Adec,0,"+-",4);
  addrange(Adec,1,'0','9',1);
  addstr(Adec,1,".",7);
  addstr(Adec,1,"eE",5);
  addstr(Adec,2,"eE",5);
  addstr(Adec,3,".",7);
  addrange(Adec,2,'0','9',1);
  addstr(Adec,4,"0",3);
  addrange(Adec,4,'1','9',1);
  addstr(Adec,5,"+-",6);
  addrange(Adec,6,'0','9',6);
  addrange(Adec,7,'0','9',7);
  addstr(Adec,7,"eE",5);


//......................
 Adec.final(1);
 Adec.final(6);
 Adec.final(7);
//......................
///////////////////////
  cout << "*** svs Adec "
       << "size=" << Adec.size()
       << " ***\n";
  cout << endl;

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = Adec.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;
}

