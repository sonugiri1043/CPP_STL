/* Compile using 'g++ RangeBasedForLoop.cpp -o RangeBasedForLoop --std=c++14' */

/* Range Based For Loop

  To loop through things in a container ( array, stack, list, vector, etc ),
  we typically write a for loop like the following:

  for( int i=0; i<n; ++i ) doSomething;

  But, now, you have a for loop that could input the elements of some array,
  for other containers you could use: non member begin() and end().

  for( int& i: someDataStructure ) { doSomething(); }

  for( int i: someDataStructure) { doSomething() };

  In the above two for loops, the first is using the reference, and the second
  enables the access by value. First way allow the modification of elements within
  a data structure and the second will not enable you to modify the elements in
  container you are using.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector< int > testVector;
  for( int i = 0; i < 100; i++ )
    testVector.push_back( i );

  for( int &i : testVector )
    cout<< i << " ";
  cout<< endl;

  for( int i : testVector )
    cout<< i << " ";
  cout<< endl;
  return 0;
}
