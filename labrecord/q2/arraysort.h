// arraysort.h

#include <iostream>
using namespace std;

template <class T>
class myarray
{
    int lb, ub;
    T a[100];

public:
    myarray();
    myarray(int l, int u);

    void create();
    void bubblesort();
    void selectionsort();
    void insertionsort();
    void quicksort();
    void mergesort();

    void linearsearch(T key);
    void binarysearch(T key);

    void display();

private:
    int partition();
    void merge(myarray<T> left, myarray<T> right);
};