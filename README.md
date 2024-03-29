# Data Structures in C++
![sequence_containers](images/sequence_containers.png)

# Pairs
The std::pair template provides an easy means of grouping two items into a structure:
    
```c++
std::pair<int, char> p(1, ‘a‘);
std::cout << p.first << ‘ ‘ << p.second << std::endl; // 1 a
```

# Vector std::vector
Dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need to extend the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

Do not use for
* Insertion/deletion in the middle of the list
* Dynamically changing storage
* Non-integer indexing

Time Complexity
```
Operation	Time Complexity
Insert Head	O(n)
Insert Index	O(n)
Insert Tail	O(1)
Remove Head	O(n)
Remove Index	O(n)
Remove Tail	O(1)
Find Index	O(1)
Find Object	O(n)
```

```c++
std::vector<int> v;

// Size
unsigned int size = v.size();

// Insert head, index, tail
v.insert(v.begin(), value);             // head
v.insert(v.begin() + index, value);     // index
v.push_back(value);                     // tail

// Access head, index, tail
int head = v.front();       // head
head = v[0];                // or using array style indexing

int value = v.at(index);    // index
value = v[index];           // or using array style indexing

int tail = v.back();        // tail
tail = v[v.size() - 1];     // or using array style indexing

// Iterate
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Iteration in reverse is done via a reverse iterator:
//...
for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
    // ... *it ... (*it is the current vector element)
}

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Clear
v.clear();
```
![vector](images/vector.png)

# Deque std::deque
Stands for Double Ended Queue. std::vector with efficient push_front and pop_front.

The std::deque template provides a double-ended queue. Deques offer a similar interface to vectors, but additionally provide efficient insertion and deletion at the front of the data structure, as well as at the back. Thus, in addition to vector‘s push back and pop back, deques offer
push front and pop front. Most vector operations are also available for deques, but be aware that deques are not guaranteed to be implemented internally as contiguous arrays.

Do not use for
* C-style contiguous storage (not guaranteed)

```
Time Complexity

Operation	Time Complexity
Insert Head	O(1)
Insert Index	O(n) or O(1)
Insert Tail	O(1)
Remove Head	O(1)
Remove Index	O(n)
Remove Tail	O(1)
Find Index	O(1)
Find Object	O(n)
```

```c++
std::deque<int> d;

// Insert head, index, tail
d.push_front(value);                    // head
d.insert(d.begin() + index, value);     // index
d.push_back(value);                     // tail

// Access head, index, tail
int head = d.front();       // head
int value = d.at(index);    // index
int tail = d.back();        // tail

// Size
unsigned int size = d.size();

// Iterate
for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
d.pop_front();                  // head
d.erase(d.begin() + index);     // index
d.pop_back();                   // tail

// Clear
d.clear();
```
![deque](images/deque.png)

# List std::list
Use for
* Insertion into the middle/beginning of the list
* Efficient sorting (pointer swap vs. copying)

Do not use for
* Direct access

Time Complexity

```
Operation	Time Complexity
Insert Head	O(1)
Insert Index	O(n)
Insert Tail	O(1)
Remove Head	O(1)
Remove Index	O(n)
Remove Tail	O(1)
Find Index	O(n)
Find Object	O(n)
```

```c++
std::list<int> l;

// Insert head, index, tail
l.push_front(value);                    // head
l.insert(l.begin() + index, value);     // index
l.push_back(value);                     // tail

// Access head, index, tail
int head = l.front();                                           // head
int value = std::next(l.begin(), index);		        // index
int tail = l.back();                                            // tail

// Size
unsigned int size = l.size();

// Iterate
for(std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
l.pop_front();                  // head
l.erase(l.begin() + index);     // index
l.pop_back();                   // tail

// Clear
l.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Splice: Transfer elements from list to list
//	splice(iterator pos, list &x)
//  	splice(iterator pos, list &x, iterator i)
//  	splice(iterator pos, list &x, iterator first, iterator last)
l.splice(l.begin() + index, list2);

// Remove: Remove an element by value
l.remove(value);

// Unique: Remove duplicates
l.unique();

// Merge: Merge two sorted lists
l.merge(list2);

// Sort: Sort the list
l.sort();

// Reverse: Reverse the list order
l.reverse();
```

![list](images/list.png)

# Map std::map and std::unordered_map
![associative_containers](images/associative_containers.png)

Use for
* Key-value pairs
* Constant lookups by key
* Searching if key/value exists
* Removing duplicates
* std::map
   Ordered map
* std::unordered_map
   Hash table

Do not use for
* Sorting

Notes
* Typically ordered maps (std::map) are slower than unordered maps (std::unordered_map)
* Maps are typically implemented as binary search trees

Time Complexity

```
std::map

Operation	Time Complexity
Insert	O(log(n))
Access by Key	O(log(n))
Remove by Key	O(log(n))
Find/Remove Value	O(log(n))
std::unordered_map

Operation	Time Complexity
Insert	O(1)
Access by Key	O(1)
Remove by Key	O(1)
Find/Remove Value	--
```

```c++
std::map<std::string, std::string> m;

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(std::pair<std::string, std::string>("key", "value"));

// Access by key
std::string value = m.at("key");

// Size
unsigned int size = m.size();

// Iterate
for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove by key
m.erase("key");

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");
```
![map](images/map.png)

![unordered_map](images/unordered_map.png)

# Set std::set

Use for
* Removing duplicates
* Ordered dynamic storage

Do not use for
* Simple storage
* Direct access by index

Notes
* Sets are often implemented with binary search trees

Time Complexity
```
Operation	Time Complexity
Insert	O(log(n))
Remove	O(log(n))
Find	O(log(n))
```

```c++
std::set<int> s;

//---------------------------------
// General Operations
//---------------------------------

// Insert
s.insert(20);

// Size
unsigned int size = s.size();

// Iterate
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove
s.erase(20);

// Clear
s.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(20) != s.end());

// Count the number of elements with a certain value
unsigned int count = s.count(20);
```

![set](images/set.png)

![unordered_set](images/unordered_set.png)

# Stack std::stack
Use for
* First-In Last-Out operations
* Reversal of elements

Time Complexity
```
Operation	Time Complexity
Push	O(1)
Pop	O(1)
Top	O(1)
```

```c++
std::stack<int> s;

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Push
s.push(20);

// Size
unsigned int size = s.size();

// Pop
s.pop();

// Top
int top = s.top();
```

# Queue std::queue

Use for
* First-In First-Out operations
* Ex: Simple online ordering system (first come first served)
* Ex: CPU scheduling (FCFS)


```c++
std::queue<int> q;

//---------------------------------
// General Operations
//---------------------------------

// Insert
q.push(value);

// Access head, tail
int head = q.front();       // head
int tail = q.back();        // tail

// Size
unsigned int size = q.size();

// Remove
q.pop();
```

# Heap, Priority Queue std::priority_queue

Use for
* First-In First-Out operations where priority overrides arrival time
* Ex: CPU scheduling (smallest job first, system/user priority)
* Ex: Medical emergencies (gunshot wound vs. broken arm)

Notes
* A heap is essentially an instance of a priority queue
* A min heap is structured with the root node as the smallest and each child subsequently larger than its parent
* A max heap is structured with the root node as the largest and each child subsequently smaller than its parent
* A min heap could be used for Smallest Job First CPU Scheduling
* A max heap could be used for Priority CPU Scheduling

```c++
std::priority_queue<int> p;

//---------------------------------
// General Operations
//---------------------------------

// Insert
p.push(value);

// Access
int top = p.top();  // 'Top' element

// Size
unsigned int size = p.size();

// Remove
p.pop();
```
