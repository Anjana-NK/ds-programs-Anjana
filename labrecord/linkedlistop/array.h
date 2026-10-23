#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class array {
private:
    Node<T>* head;

public:
    array();

    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_at_position(int pos, T key);

    void delete_at_beginning();
    void delete_at_end();
    void delete_at_position(int pos);

    void display() const;
};