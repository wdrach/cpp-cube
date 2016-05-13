#include <iostream>
#include "cube.h"

using namespace std;

//solved state
const char solved[54] = {
  'a', 'A', 'b', 'D', '0', 'B', 'd', 'C', 'c',
  'e', 'E', 'f', 'H', '1', 'F', 'h', 'G', 'g',
  'i', 'I', 'j', 'L', '2', 'J', 'l', 'K', 'k',
  'm', 'M', 'n', 'P', '3', 'N', 'p', 'O', 'o',
  'q', 'Q', 'r', 'T', '4', 'R', 't', 'S', 's',
  'u', 'U', 'v', 'X', '5', 'V', 'x', 'W', 'w'
};

cube::cube(char start_state[54]) {
  int i;
  if (start_state != NULL) {
    for (i=0; i<54; i++) state[i] = start_state[i];
  }
  else {
    for (i=0; i<54; i++) state[i] = solved[i];
  }

  return;
}

void cube::printColor(char c) {
  //lowercase
  if (c > 'Z') c -= 'z' - 'Z';
  if ((c < 'E' && c >= 'A') || c == '0') cout << "\x1b[37m" << "[" << c << "]";
  else if ((c < 'I' && c >= 'A') || c == '1') cout << "\x1b[35m" << "[" << c << "]";
  else if ((c < 'M' && c >= 'A') || c == '2') cout << "\x1b[32m" << "[" << c << "]";
  else if ((c < 'Q' && c >= 'A') || c == '3') cout << "\x1b[31m" << "[" << c << "]";
  else if ((c < 'U' && c >= 'A') || c == '4') cout << "\x1b[34m" << "[" << c << "]";
  else cout << "\x1b[33m" << "[" << c << "]";
}

void cube::printCube() {
  //todo add this with printColor
  return;
}

void cube::mapper(char map[54]) {
  char tmpState[54]
  int i;
  for (i=0; i<54; i++) tmpState[i] = state[map[i]];
  for (i=0; i<54; i++) state[i] = tmpState[i];
  return;
}
