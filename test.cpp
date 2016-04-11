#include <iostream>
#include "cube.h"

#define SUCCESS 0
#define FAIL 1

using namespace std;

int main(int argc, char* argv[]) {
  cube c;
  c.printCube();
  c.R();
  c.printCube();
  return SUCCESS;
}
