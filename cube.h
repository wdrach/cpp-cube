/* The state is in the following format:
 * It's an array with each cube face taking up 9 consecutive units
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
 * care about centers and we do, so we label those A-F in the order above,
 * so a solved cube will have a state like this:
 *[
 * a, A, b,
 * D, A, B,
 * d, C, c,
 *
 * e, E, f,
 * H, B, F,
 * h, G, g,
 *
 * i, I, j,
 * L, C, J,
 * l, K, k,
 *
 * m, M, n,
 * P, D, N,
 * p, O, o,
 *
 * q, Q, r,
 * T, E, R,
 * t, S, s,
 *
 * u, U, v,
 * X, F, V,
 * x, W, w
 *]
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

  public:
    //constructor
    cube(int start_state[54] = NULL);
    //int* getState();
    void printCube();

    //R&L
    void R();
/*  bool r();
    bool Ri();
    bool ri();
    bool L();
    bool l();
    bool Li();
    bool li();
    
    //U&D
    bool U();
    bool u();
    bool Ui();
    bool ui();
    bool D();
    bool d();
    bool Di();
    bool di();

    //F&B
    bool F();
    bool f();
    bool Fi();
    bool fi();
    bool B();
    bool b();
    bool Bi();
    bool bi();

    //M slices
    bool M();
    bool Mi();
    bool E();
    bool Ei();
    bool S();
    bool Si();

    //rotations
    bool Y();
    bool Yi();
    bool X();
    bool Xi();
    bool Z();
    bool Zi();*/

    //helpers
};
