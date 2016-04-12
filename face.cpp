#include <iostream>
#include "face.h"

using namespace std;

int solved[54] = {
  'a', 'A', 'b', 'D', '0', 'B', 'd', 'C', 'c',
  'e', 'E', 'f', 'H', '1', 'F', 'h', 'G', 'g',
  'i', 'I', 'j', 'L', '2', 'J', 'l', 'K', 'k',
  'm', 'M', 'n', 'P', '3', 'N', 'p', 'O', 'o',
  'q', 'Q', 'r', 'T', '4', 'R', 't', 'S', 's',
  'u', 'U', 'v', 'X', '5', 'V', 'x', 'W', 'w'
};

face::face(int start_state[9], char face) {
  cout << face << endl;
  int i;

  //set the initial state
  if (start_state == NULL) {
    face = (face - '0')*9;
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
