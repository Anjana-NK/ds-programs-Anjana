// array.h
// Declaration of a generic (template) array class that supports
// insertion/deletion at the beginning, end, and a given position.
// NOTE: "using namespace std;" is deliberately NOT used here.
// Reason: std::array (from <tuple>/<array>) would collide with our
// own class name "array", making array<T> ambiguous to the compiler.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <ostream>
 
template <class T>
class array
{
    int lb, ub;   // lb = lower bound (first valid index), ub = upper bound (last used index)
    T a[100];     // fixed-size backing storage (max 100 elements)
 
    public:
    array();                              // constructor: sets up an empty array
    void setLB(int x);                    // set the lower bound
    void setUB(int x);                    // set the upper bound
    int  getLB();                         // get the lower bound
    int  getUB();                         // get the upper bound
    void create();                        // read lb..ub elements from the user
    void insert_at_end(T key);            // append key after ub
    void insert_at_beginning(T key);      // insert key before lb, shifting everything right
    void insert_at_position(int, T key);  // insert key at a given index, shifting right
    void delete_at_end();                 // remove the last element
    void delete_at_beginning();           // remove the first element, shifting everything left
    void delete_at_position(int);         // remove the element at a given index
 
    // Overloaded stream insertion operator (operator<<).
    // Declared as a "friend" template so it can access the private
    // members (lb, ub, a) of array<U> directly, for ANY type U.
    // See the accompanying write-up for a full explanation of why
    // this must be a non-member (friend) function rather than a
    // regular member function.
    template<class U> friend ostream& operator<<(ostream&, const array<U>&);
};