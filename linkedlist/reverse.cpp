#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head;

    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, value;
    Node* head = NULL;
    Node* temp = NULL;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;

        Node* newNode = new Node{value, NULL};

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    cout << "Original: ";
    print(head);

    head = reverse(head);

    cout << "Reversed: ";
    print(head);

    return 0;
}
