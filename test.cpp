#include <iostream>
#include "cube.h"

#define SUCCESS 0
#define FAIL 1

using namespace std;

int main(int argc, char* argv[]) {
  cube c;
  c.printCube();
  cout << "---------" << endl << "performing R" << endl << "---------" << endl;
  c.R();
  c.printCube();
  cout << "---------" << endl << "performing M'" << endl << "---------" << endl;
  c.Mi();
  c.printCube();
  cout << "---------" << endl << "performing L" << endl << "---------" << endl;
  c.L();
  c.printCube();

  return SUCCESS;
}
