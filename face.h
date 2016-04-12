
//face contains a main state array as well
//as a set of rotated arrays. Why? because
//L and R are opposite, so you can't index them
//like arrays, you have to rotate one.
//This allows you to index every rotation of a
//face as an array, making for looping things
//a hell of a lot easier
//
//The state contains a speffz letter for each
//piece in "number pad" order.
class face {
  //the user should not be able to directly influence the state
  char state[9];

  public:
    //constructor
    //face is A-F as per our lettering scheme
    face(int start_state[9] = NULL, char face='A');
    //int* getState();
    
    //default speffz orientation
    char* AState[9];

    //rotated cw once
    char* BState[9];
    //twice
    char* CState[9];
    //rotated ccw once/cw thrice
    char* DState[9];
};
