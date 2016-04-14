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
  //sorry this is confusing AF, but it works
  int i;
  int j;

  cout << "          ";
  for (j=0; j<9; j++) {
    printColor(*(state[4].CState[j]));
    if (j%3 == 2) cout << endl << "          ";
  }
  cout << endl;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) printColor(*(state[1].BState[j + 3*i]));
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
      for (i=0; i<9; i++) rBuffer[i] = *(state[1].DState[i]);
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

void cube::Li() {
  vSlice(0);
  return;
}

void cube::li() {
  vSlice(0);
  vSlice(1);
  return;
}

void cube::Mi() {
  vSlice(1);
  return;
}

void cube::ivSlice(char layer) {
  int i;
  char buffer[9];

  //drop U into the buffer
  for (i=layer; i<9; i+=3) buffer[i] = *(state[0].AState[i]);

  //move B to U
  for (i=layer; i<9; i+=3) *(state[0].AState[i]) = *(state[4].CState[i]);

  //move D to B
  for (i=layer; i<9; i+=3) *(state[4].CState[i]) = *(state[5].AState[i]);

  //move F to D
  for (i=layer; i<9; i+=3) *(state[5].AState[i]) = *(state[2].AState[i]);

  //move U to F
  for (i=layer; i<9; i+=3) *(state[2].AState[i]) = buffer[i];


  char rBuffer[9];
  switch (layer) {
    case 0:
      for (i=0; i<9; i++) rBuffer[i] = *(state[1].BState[i]);
      for (i=0; i<9; i++) *(state[1].AState[i]) = rBuffer[i];
      break;
    case 2:
      for (i=0; i<9; i++) rBuffer[i] = *(state[3].DState[i]);
      for (i=0; i<9; i++) *(state[3].AState[i]) = rBuffer[i];
      break;
  }
}

void cube::Ri() {
  ivSlice(2);
  return;
}

void cube::ri() {
  ivSlice(2);
  ivSlice(1);
  return;
}

void cube::L() {
  ivSlice(0);
  return;
}

void cube::l() {
  ivSlice(0);
  ivSlice(1);
  return;
}

void cube::M() {
  ivSlice(1);
  return;
}

void cube::hSlice(char layer) {
  int i;
  char buffer[9];

  //drop F into the buffer
  for (i=layer; i<9; i+=3) buffer[i] = *(state[2].BState[i]);

  //move R to F
  for (i=layer; i<9; i+=3) *(state[2].BState[i]) = *(state[3].BState[i]);

  //move B to R
  for (i=layer; i<9; i+=3) *(state[3].BState[i]) = *(state[4].BState[i]);

  //move L to B
  for (i=layer; i<9; i+=3) *(state[4].BState[i]) = *(state[1].BState[i]);

  //move F to L
  for (i=layer; i<9; i+=3) *(state[1].BState[i]) = buffer[i];


  char rBuffer[9];
  switch (layer) {
    case 0:
      for (i=0; i<9; i++) rBuffer[i] = *(state[5].DState[i]);
      for (i=0; i<9; i++) *(state[5].AState[i]) = rBuffer[i];
      break;
    case 2:
      for (i=0; i<9; i++) rBuffer[i] = *(state[0].BState[i]);
      for (i=0; i<9; i++) *(state[0].AState[i]) = rBuffer[i];
      break;
  }
}

void cube::U() {
  hSlice(2);
  return;
}

void cube::u() {
  hSlice(2);
  hSlice(1);
  return;
}

void cube::Di() {
  hSlice(0);
  return;
}

void cube::di() {
  hSlice(0);
  hSlice(1);
  return;
}

void cube::Ei() {
  hSlice(1);
  return;
}


void cube::ihSlice(char layer) {
  int i;
  char buffer[9];

  //drop F into the buffer
  for (i=layer; i<9; i+=3) buffer[i] = *(state[2].BState[i]);

  //move L to F
  for (i=layer; i<9; i+=3) *(state[2].BState[i]) = *(state[1].BState[i]);

  //move B to L
  for (i=layer; i<9; i+=3) *(state[1].BState[i]) = *(state[4].BState[i]);

  //move R to B
  for (i=layer; i<9; i+=3) *(state[4].BState[i]) = *(state[3].BState[i]);

  //move F to R
  for (i=layer; i<9; i+=3) *(state[3].BState[i]) = buffer[i];


  char rBuffer[9];
  switch (layer) {
    case 0:
      for (i=0; i<9; i++) rBuffer[i] = *(state[5].BState[i]);
      for (i=0; i<9; i++) *(state[5].AState[i]) = rBuffer[i];
      break;
    case 2:
      for (i=0; i<9; i++) rBuffer[i] = *(state[0].DState[i]);
      for (i=0; i<9; i++) *(state[0].AState[i]) = rBuffer[i];
      break;
  }
}

void cube::Ui() {
  ihSlice(2);
  return;
}

void cube::ui() {
  ihSlice(2);
  ihSlice(1);
  return;
}

void cube::D() {
  ihSlice(0);
  return;
}

void cube::d() {
  ihSlice(0);
  ihSlice(1);
  return;
}

void cube::E() {
  ihSlice(1);
  return;
}

void cube::mSlice(char layer) {
  int i;
  char buffer[9];

  //drop U into the buffer
  for (i=layer; i<9; i+=3) buffer[i] = *(state[0].DState[i]);

  //move L to U
  for (i=layer; i<9; i+=3) *(state[0].DState[i]) = *(state[1].AState[i]);

  //move D to L
  for (i=layer; i<9; i+=3) *(state[1].AState[i]) = *(state[5].BState[i]);

  //move R to D
  for (i=layer; i<9; i+=3) *(state[5].BState[i]) = *(state[3].CState[i]);

  //move U to R
  for (i=layer; i<9; i+=3) *(state[3].CState[i]) = buffer[i];


  char rBuffer[9];
  switch (layer) {
    case 0:
      for (i=0; i<9; i++) rBuffer[i] = *(state[4].DState[i]);
      for (i=0; i<9; i++) *(state[4].AState[i]) = rBuffer[i];
      break;
    case 2:
      for (i=0; i<9; i++) rBuffer[i] = *(state[2].BState[i]);
      for (i=0; i<9; i++) *(state[2].AState[i]) = rBuffer[i];
      break;
  }
}

void cube::F() {
  mSlice(2);
  return;
}

void cube::f() {
  mSlice(2);
  mSlice(1);
  return;
}

void cube::Bi() {
  mSlice(0);
  return;
}

void cube::bi() {
  mSlice(0);
  mSlice(1);
  return;
}

void cube::S() {
  mSlice(1);
  return;
}
