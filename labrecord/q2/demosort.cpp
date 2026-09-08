#include "arraysort.cpp"

int main()
{
    int choice;
    int ele;

    myarray<int> arr;

    // Array input is mandatory
    arr.create();

    do
    {
        cout << "\n\t\tMenu" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Bubble sort" << endl;
        cout << "2. Selection sort" << endl;
        cout << "3. Insertion sort" << endl;
        cout << "4. Quick sort" << endl;
        cout << "5. Merge sort" << endl;
        cout << "6. Linear search" << endl;
        cout << "7. Binary search" << endl;
        cout << "8. Display the array elements" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                arr.bubblesort();
                cout << "Array after bubble sort: ";
                arr.display();
                break;

            case 2:
                arr.selectionsort();
                cout << "Array after selection sort: ";
                arr.display();
                break;

            case 3:
                arr.insertionsort();
                cout << "Array after insertion sort: ";
                arr.display();
                break;

            case 4:
                arr.quicksort();
                cout << "Array after quick sort: ";
                arr.display();
                break;

            case 5:
                arr.mergesort();
                cout << "Array after merge sort: ";
                arr.display();
                break;

            case 6:
                cout << "Enter the element to be searched: ";
                cin >> ele;
                arr.linearsearch(ele);
                break;

            case 7:
                cout << "Enter the element to be searched: ";
                cin >> ele;
                arr.binarysearch(ele);
                break;

            case 8:
                cout << "Array elements: ";
                arr.display();
                break;

            case 9:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 9);

    return 0;
}