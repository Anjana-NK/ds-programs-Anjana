#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insert_beginning(int value) {
    Node* Newnode = new Node();
    Newnode->data = value;
    Newnode->next = head;
    head = Newnode;
}

// Insert at end
void insert_end(int value) {
    Node* Newnode = new Node();
    Newnode->data = value;
    Newnode->next = NULL;

    if (head == NULL) {
        head = Newnode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = Newnode;
}

// Insert at position
void insert_pos(int value, int position) {
    if (position == 1) {
        insert_beginning(value);
        return;
    }

    Node* Newnode = new Node();
    Newnode->data = value;

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;
}

// Delete from beginning
void delete_beginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void delete_end() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete from position
void delete_pos(int position) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (position == 1) {
        delete_beginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

// Display
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


int main() {

    int choice, value, position;

    do {
        cout << "\n--- LINKED LIST ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            insert_beginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insert_end(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            insert_pos(value, position);
            break;

        case 4:
            delete_beginning();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;

            delete_pos(position);
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 8);

    return 0;
}
