//arraysort.cpp
#include "arraysort.h"

// Default constructor
template <class T>
myarray<T>::myarray()
{
    lb = 0;
    ub = -1;
}

// Parameterized constructor
template <class T>
myarray<T>::myarray(int l, int u)
{
    lb = l;
    ub = u;
}

// Create array
template <class T>
void myarray<T>::create()
{
    int i;

    cout << "Enter lower bound: ";
    cin >> lb;

    cout << "Enter upper bound: ";
    cin >> ub;

    cout << "Enter the elements: ";

    for (i = lb; i <= ub; i++)
    {
        cin >> a[i];
    }
}

// Bubble Sort
template <class T>
void myarray<T>::bubblesort()
{
    int i, j;
    T temp;

    for (i = lb; i <= ub - 1; i++)
    {
        for (j = lb; j <= ub - 1 - (i - lb); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
template <class T>
void myarray<T>::selectionsort()
{
    int i, j, min;
    T temp;

    for (i = lb; i <= ub - 1; i++)
    {
        min = i;

        for (j = i + 1; j <= ub; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Insertion Sort
template <class T>
void myarray<T>::insertionsort()
{
    int i, j;
    T key;

    for (i = lb + 1; i <= ub; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= lb && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Quick Sort
template <class T>
void myarray<T>::quicksort()
{
    if (lb < ub)
    {
        int pivot = partition();

        // Save original bounds
        int old_lb = lb;
        int old_ub = ub;

        // Sort left part
        lb = old_lb;
        ub = pivot - 1;
        if (lb < ub)
            quicksort();

        // Sort right part
        lb = pivot + 1;
        ub = old_ub;
        if (lb < ub)
            quicksort();

        // Restore original bounds
        lb = old_lb;
        ub = old_ub;
    }
}

// Lomuto Partition
template <class T>
int myarray<T>::partition()
{
    T pivot = a[ub];
    int i = lb - 1;
    T temp;

    for (int j = lb; j < ub; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[ub];
    a[ub] = temp;

    return i + 1;
}

// Merge Sort
template <class T>
void myarray<T>::mergesort()
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        myarray<T> left(lb, mid);
        myarray<T> right(mid + 1, ub);

        // Copy elements into left array
        for (int i = lb; i <= mid; i++)
        {
            left.a[i] = a[i];
        }

        // Copy elements into right array
        for (int i = mid + 1; i <= ub; i++)
        {
            right.a[i] = a[i];
        }

        // Sort both halves
        left.mergesort();
        right.mergesort();

        // Merge both halves
        merge(left, right);
    }
}

// Merge two sorted arrays
template <class T>
void myarray<T>::merge(myarray<T> left, myarray<T> right)
{
    int i = left.lb;
    int j = right.lb;
    int k = lb;

    // Compare elements from both arrays
    while (i <= left.ub && j <= right.ub)
    {
        if (left.a[i] <= right.a[j])
        {
            a[k] = left.a[i];
            i++;
        }
        else
        {
            a[k] = right.a[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left array
    while (i <= left.ub)
    {
        a[k] = left.a[i];
        i++;
        k++;
    }

    // Copy remaining elements from right array
    while (j <= right.ub)
    {
        a[k] = right.a[j];
        j++;
        k++;
    }
}

// Linear Search
template <class T>
void myarray<T>::linearsearch(T key)
{
    int i;

    for (i = lb; i <= ub; i++)
    {
        if (a[i] == key)
        {
            cout << "Element found at position " << i << endl;
            return;
        }
    }

    cout << "Element not found" << endl;
}

// Binary Search
template <class T>
void myarray<T>::binarysearch(T key)
{
    int low = lb;
    int high = ub;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            cout << "Element found at position " << mid << endl;
            return;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Element not found" << endl;
}

// Display array
template <class T>
void myarray<T>::display()
{
    for (int i = lb; i <= ub; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}