#include "array.h"

template <class T>
array<T>::array() {
    head = nullptr;
}

template <class T>
void array<T>::insert_at_beginning(T key) {
    Node<T>* newNode = new Node<T>();
    newNode->data = key;
    newNode->next = head;
    head = newNode;
}

template <class T>
void array<T>::insert_at_end(T key) {
    Node<T>* newNode = new Node<T>();
    newNode->data = key;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <class T>
void array<T>::insert_at_position(int pos, T key) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) {
        insert_at_beginning(key);
        return;
    }

    Node<T>* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node<T>* newNode = new Node<T>();
    newNode->data = key;
    newNode->next = temp->next;
    temp->next = newNode;
}

template <class T>
void array<T>::delete_at_beginning() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
    cout << "Element deleted from beginning." << endl;
}

template <class T>
void array<T>::delete_at_end() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Element deleted from end." << endl;
        return;
    }

    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    cout << "Element deleted from end." << endl;
}

template <class T>
void array<T>::delete_at_position(int pos) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) {
        delete_at_beginning();
        return;
    }

    Node<T>* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node<T>* target = temp->next;
    temp->next = target->next;
    delete target;
    cout << "Element deleted from position " << pos << "." << endl;
}

template <class T>
void array<T>::display() const {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}