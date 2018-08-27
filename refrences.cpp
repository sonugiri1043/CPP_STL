#include <iostream>

/*
  When a variable is declared as reference, it becomes an alternative
  name for an existing variable. A variable can be declared as reference
  by putting ‘&’ in the declaration.

  Once a reference is created, it cannot be later made to reference
  another object.
  References cannot be NULL.
  A reference must be initialized when declared.
  
  There are few places like copy constructor argument where pointer
  cannot be used. Reference must be used pass the argument in copy
  constructor. Similarly references must be used for overloading some
  operators like ++.
 */

using namespace std;

void swap( int &a, int &b ) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  return;
}

int main() {
  int x = 10;
  int &ref = x;
  ref = 20;
  cout<< "x = " << x << endl;
  x = 30;
  cout<< "ref = " << ref << endl;

  int p = 10;
  int q = 20;
  swap( p, q );
  cout<< "p = " << p << " q = " << q << endl;
  return 0;
}
