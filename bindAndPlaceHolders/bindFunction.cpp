/*
 * Compile using
 * g++ bindFunction.cpp -o bindFunction --std=c++11
 *
 * code to demonstrate bind and placeholders
 * std::bind act as a functional adaptor. It takes a function as input
 * and returns a new function Object as an output with with one or more
 * of the arguments of passed function bound or rearranged.
 */

#include <iostream>
#include <functional> /* for placeholders */

using namespace std;

void func( int a, int b, int c ) {
  cout<< "a: " << a << " b: " << b << " c: " << c << endl;
}

int main() {
  // bound fn1 with func with 1, 2, 3 as arguments.
  function <void ()> fn1 = bind( func, 1, 2, 3 );
  fn1();

  function <void( int ) > fn2 = bind( func, 1, 2, placeholders::_1 );
  fn2( 4 );
  
  // rearranged argments
  function <void (int, int, int)> fn3 = bind( func,
					      placeholders::_3,
					      placeholders::_2,
					      placeholders::_1 );
  fn3( 1, 2, 3 );
  return 0;
}
