#include <iostream>
#include "face.h"

using namespace std;

int solved[54] = {
  'a', 'A', 'b', 'D', 'A', 'B', 'd', 'C', 'c',
  'e', 'E', 'f', 'H', 'B', 'F', 'h', 'G', 'g',
  'i', 'I', 'j', 'L', 'C', 'J', 'l', 'K', 'k',
  'm', 'M', 'n', 'P', 'D', 'N', 'p', 'O', 'o',
  'q', 'Q', 'r', 'T', 'E', 'R', 't', 'S', 's',
  'u', 'U', 'v', 'X', 'F', 'V', 'x', 'W', 'w'
};

face::face(int start_state[9], char face) {
  int i;

  //set the initial state
  if (start_state == NULL) {
    face = (face - 'A')*9;
    for (i=0; i<9; i++) state[i] = solved[face + i];
  }
  else {
    for (i=0; i<9; i++) state[i] = start_state[i];
  }

  //set the pointer arrays
  for (i=0; i<9; i++) AState[i] = &(state[i]);

  //the rotation of one side and how it switches
  //everything. Makes it easier to use fors
  const char rotate[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2};

  //rotate all of the sides using our rotate array
  for (i=0; i<9; i++) BState[i] = AState[rotate[i]];
  for (i=0; i<9; i++) CState[i] = BState[rotate[i]];
  for (i=0; i<9; i++) DState[i] = CState[rotate[i]];

  return;
}