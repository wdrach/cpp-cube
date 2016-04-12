#include <iostream>
#include "cube.h"

using namespace std;

cube::cube(face start_state[6]) {
  int i;
  if (start_state != NULL) {
    for (i=0; i<6; i++) state[i] = start_state[i];
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
  //want to print like this
  //    4C
  //1B? 0A 3D?
  //    2A
  //    5A
  //
  //1B and 3D might be 1D and 3B
  int i;
  int j;

  cout << "          ";
  for (j=0; j<9; j++) {
    printColor(*(state[4].CState[j]));
    if (j%3 == 2) cout << endl << "          ";
  }
  cout << endl;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) printColor(*(state[1].DState[j + 3*i]));
    cout << " ";
    for (j=0; j<3; j++) printColor(*(state[0].AState[j + 3*i]));
    cout << " ";
    for (j=0; j<3; j++) printColor(*(state[3].DState[j + 3*i]));
    cout << endl;
  }

  cout << endl << "          ";
  for (j=0; j<9; j++) {
    printColor(*(state[2].AState[j]));
    if (j%3 == 2) cout << endl << "          ";
  }

  cout << endl << "          ";
  for (j=0; j<9; j++) {
    printColor(*(state[5].AState[j]));
    if (j%3 == 2) cout << endl << "          ";
  }

  cout << "\x1b[37m" << endl;

  return;
}

void cube::vSlice(char layer) {
  int i;
  char buffer[9];

  //drop U into the buffer
  for (i=layer; i<9; i+=3) buffer[i] = *(state[0].AState[i]);

  //move F to U
  for (i=layer; i<9; i+=3) *(state[0].AState[i]) = *(state[2].AState[i]);

  //move D to F
  for (i=layer; i<9; i+=3) *(state[2].AState[i]) = *(state[5].AState[i]);

  //move B to D
  for (i=layer; i<9; i+=3) *(state[5].AState[i]) = *(state[4].CState[i]);

  //move F to B
  for (i=layer; i<9; i+=3) *(state[4].CState[i]) = buffer[i];

  char rBuffer[9];
  switch (layer) {
    case 0:
      for (i=0; i<9; i++) rBuffer[i] = *(state[1].BState[i]);
      for (i=0; i<9; i++) *(state[1].AState[i]) = rBuffer[i];
      break;
    case 2:
      for (i=0; i<9; i++) rBuffer[i] = *(state[3].BState[i]);
      for (i=0; i<9; i++) *(state[3].AState[i]) = rBuffer[i];
      break;
  }
}

void cube::R() {
  vSlice(2);
  return;
}

void cube::r() {
  vSlice(2);
  vSlice(1);
  return;
}

void cube::L() {
  vSlice(0);
  return;
}

void cube::l() {
  vSlice(0);
  vSlice(1);
  return;
}

void cube::Mi() {
  vSlice(1);
  return;
}

