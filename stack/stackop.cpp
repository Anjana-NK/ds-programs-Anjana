
#include <iostream>
using namespace std;

template <class T>
class Stack {
    T arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    // PUSH
    void push(T value) {
        if (top == 99) {
            cout << "Stack Overflow\n";
        }
        else {
            top++;
            arr[top] = value;
            cout << value << " pushed\n";
        }
    }

    // POP
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        }
        else {
            cout << arr[top] << " popped\n";
            top--;
        }
    }

    // PEEK
    void peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // DISPLAY
    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack<int> s;
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
