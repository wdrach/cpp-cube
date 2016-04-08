class cube {
  char state[54];
  public:
    cube(int start_state[54]);
    int* getState();

    //R&L
    bool R();
    bool r();
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
    bool Zi();
};
