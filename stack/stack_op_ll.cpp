
#include <iostream>
using namespace std;

template <class T>
class Stack {
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // PUSH
    void push(T value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed\n";
    }

    // POP
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
        }
        else {
            Node* temp = top;
            cout << temp->data << " popped\n";
            top = top->next;
            delete temp;
        }
    }

    // PEEK
    void peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Top element: " << top->data << endl;
        }
    }

    // DISPLAY
    void display() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
        }
        else {
            Node* temp = top;

            cout << "Stack elements: ";

            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
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
