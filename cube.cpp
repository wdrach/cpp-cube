#include <iostream>
#include "cube.h"

using namespace std;

int solved[54] = {
  'a', 'A', 'b', 'D', 'A', 'B', 'd', 'C', 'c',
  'e', 'E', 'f', 'H', 'B', 'F', 'h', 'G', 'g',
  'i', 'I', 'j', 'L', 'C', 'J', 'l', 'K', 'k',
  'm', 'M', 'n', 'P', 'D', 'N', 'p', 'O', 'o',
  'q', 'Q', 'r', 'T', 'E', 'R', 't', 'S', 's',
  'u', 'U', 'v', 'X', 'F', 'V', 'x', 'W', 'w'
};

cube::cube(int start_state[54]) {
  int i;
  if (start_state == NULL) {
    for (i=0; i<54; i++) state[i] = solved[i];
  }
  else {
    for (i=0; i<54; i++) state[i] = start_state[i];
  }
  return;
}

void cube::printCube() {
  int i, j;
  for (i=0; i<6*3; i++) {
    for (j=0; j<3; j++) {
      cout << "|" << state[3*i + j] << "|";
    }
    cout << endl;
    if (i%3 == 2) cout << endl;
  }
  cout << endl;
}

void cube::R() {
  char buffer[3] = {state[2], state[5], state[8]};

  //move F to U
  state[2] = state[20];
  state[5] = state[23];
  state[8] = state[26];

  //move D to F
  state[20] = state[47];
  state[23] = state[50];
  state[26] = state[53];

  //move B to D
  state[47] = state[42];
  state[50] = state[39];
  state[53] = state[36];

  //move U to B
  state[42] = buffer[0];
  state[39] = buffer[1];
  state[36] = buffer[2];

  //rotate R
  //corners
  buffer[0] = state[27];
  state[27] = state[33];
  state[33] = state[35];
  state[35] = state[29];
  state[29] = buffer[0];
  //edges
  buffer[0] = state[28];
  state[28] = state[30];
  state[30] = state[34];
  state[34] = state[32];
  state[32] = buffer[0];

  return;
}

//etc
