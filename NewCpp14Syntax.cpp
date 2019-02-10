/*
  Compile using 'g++ NewCpp14Syntax.cpp -o NewCpp14Syntax --std=c++14'
*/

#include <iostream>

using namespace std;

auto sum( int x, int y ) {
  return x+y;
}

/*  Illustrates some C++14 features */
int main() {
  int a{0};
  cout<< a << endl;

  /*1. Generic lambdas
    C++14 generic lambdas make it possible to write:

    auto lambda = []( auto x, auto y ) { return x + y; };

    On the other hand, C++11 requires that lambda parameters be declared
    with concrete types, e.g:
    
    auto lambda = [](int x, int y) {return x + y;};
    
    Using auto for parameters effectively makes the function call operator templated. */

  auto fn = [] ( auto x, auto y ) { return x + y; };  
  cout<< fn( 1, 2 ) << endl;
  
  /*
    Return type deduction for functions

    auto square(int n) 
    {
       return n * n;
    }
 */
  cout<< sum( 3, 5 ) << endl;
  return 0;
}
