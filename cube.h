#include "face.h"
/* The state is in the following format:
 * It's an array of face objects, whose face.AState is laid
 * out as a pointer to a char of in the following format:
 * [1, 2, 3, 4, 5, 6, 7, 8, 9] ==
 * [ 1, 2, 3,
 *   4, 5, 6
 *   7, 8, 9 ]
 *
 * so 1 in that array is the top left corner, and it is laid out
 * like a number pad.
 *
 * The order of faces is U, L, F, R, B, D, same order used for Speffz
 *
 * Oh, and by the way, that's how it works, with Speffz, but Speffz doesn't
 * care about centers and we do, so we label those 0-6 in the order above,
 * so a solved cube will have a state like this:
 * a, A, b,
 * D, 0, B,
 * d, C, c,
 *
 * e, E, f,
 * H, 1, F,
 * h, G, g,
 *
 * i, I, j,
 * L, 2, J,
 * l, K, k,
 *
 * m, M, n,
 * P, 3, N,
 * p, O, o,
 *
 * q, Q, r,
 * T, 4, R,
 * t, S, s,
 *
 * u, U, v,
 * X, 5, V,
 * x, W, w
 *
 * This makes it easy to catch things like cube rotations, which is easy
 * to handle for a human (you just look at it differently), but not easy
 * for a robot to handle, which is the end goal of this simulator
 *
 * Eventually this lib will be able to handle just taking colors, but
 * this is how it be for the time being (mostly because it's easier to
 * solve a cube using the PIECES instead of the colors)
 */

class cube {
  //the user should not be able to directly influence the state
  char state[54];

  //internal helpers
  void printColor(char c);

  //our mapper
  void mapper(char map[54]);

  public:
    //constructor
    cube(start_state[54] = NULL);
    //int* getState();
    void printCube();

    //R&L
    /*void R();
    void r();
    void Ri();
    void ri();
    void L();
    void l();
    void Li();
    void li();
    
    //U&D
    void U();
    void u();
    void Ui();
    void ui();
    void D();
    void d();
    void Di();
    void di();

    //F&B
    void F();
    void f();
    void Fi();
    void fi();
    void B();
    void b();
    void Bi();
    void bi();

    //M slices
    void M();
    void Mi();
    void E();
    void Ei();
    void S();
    void Si();*/

    //rotations
/*  void Y();
    void Yi();
    void X();
    void Xi();
    void Z();
    void Zi();*/
};
