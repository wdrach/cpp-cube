#include <iostream>
#include "cube.h"

#define SUCCESS 0
#define FAIL 1

#define U c.U();
#define Ui c.Ui();
#define D c.D();
#define Di c.Di();
#define R c.R();
#define Ri c.Ri();
#define L c.L();
#define Li c.Li();
#define F c.F();
#define Fi c.Fi();
#define B c.B();
#define Bi c.Bi();
#define M c.M();
#define Mi c.Mi();

using namespace std;

int main(int argc, char* argv[]) {
  cube c;
  c.printCube();
  //T perm
  R U Ri Ui Ri F R R Ui Ri Ui R U Ri Fi
  cout << "-------------------" << endl << endl;
  c.printCube();
  //undo
  R U Ri Ui Ri F R R Ui Ri Ui R U Ri Fi
  cout << "-------------------" << endl << endl;
  c.printCube();
  //M perm
  Mi Mi U Mi Mi U U Mi Mi U Mi Mi
  cout << "-------------------" << endl << endl;
  c.printCube();
  //undo
  Mi Mi U Mi Mi U U Mi Mi U Mi Mi
  cout << "-------------------" << endl << endl;
  c.printCube();
  //random scramble
  Ui L L D D L L Bi U U B R R U U F F L L U U Ri F D Li Ri Fi Li Di Bi
  cout << "-- Rand Scramble --" << endl << endl;
  c.printCube();
  return SUCCESS;
}
