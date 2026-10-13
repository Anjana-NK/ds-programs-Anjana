#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void insertFront(int x) {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1)) {
            cout << "Deque Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        arr[front] = x;
    }

    void insertRear(int x) {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1)) {
            cout << "Deque Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (front == -1) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, x;

    do {
        cout << "\n1. Insert Front";
        cout << "\n2. Insert Rear";
        cout << "\n3. Delete Front";
        cout << "\n4. Delete Rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                d.insertFront(x);
                break;

            case 2:
                cout << "Enter element: ";
                cin >> x;
                d.insertRear(x);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
