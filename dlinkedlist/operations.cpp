#include <iostream>
using namespace std;


// ======================================================
// NODE CLASS
// ======================================================

class Node {
public:

    int data;

    // Pointer to the previous node
    Node* prev;

    // Pointer to the next node
    Node* next;


    // Constructor
    Node(int value) {

        data = value;

        // Initially, there is no previous node
        prev = NULL;

        // Initially, there is no next node
        next = NULL;
    }
};


// ======================================================
// DOUBLY LINKED LIST CLASS
// ======================================================

class DoublyLinkedList {
private:

    // head points to the first node
    Node* head;


public:

    // ==================================================
    // CONSTRUCTOR
    // ==================================================

    DoublyLinkedList() {

        // Initially the list is empty
        head = NULL;
    }


    // ==================================================
    // 1. CREATE LIST
    // ==================================================

    void create() {

        int n;
        int value;

        cout << "Enter number of nodes: ";
        cin >> n;

        for (int i = 0; i < n; i++) {

            cout << "Enter value: ";
            cin >> value;

            insertAtEnd(value);
        }
    }


    // ==================================================
    // 2. DISPLAY FORWARD
    // ==================================================

    void displayForward() {

        // Check if list is empty
        if (head == NULL) {

            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Forward: ";

        // Continue until temp becomes NULL
        while (temp != NULL) {

            cout << temp->data << " ";

            // Move to the next node
            temp = temp->next;
        }

        cout << endl;
    }


    // ==================================================
    // 3. DISPLAY BACKWARD
    // ==================================================

    void displayBackward() {

        if (head == NULL) {

            cout << "List is empty.\n";
            return;
        }


        // First move to the last node
        Node* temp = head;

        while (temp->next != NULL) {

            temp = temp->next;
        }


        // Now temp points to the last node

        cout << "Backward: ";

        while (temp != NULL) {

            cout << temp->data << " ";

            // Move backwards using prev
            temp = temp->prev;
        }

        cout << endl;
    }


    // ==================================================
    // 4. INSERT AT BEGINNING
    // ==================================================

    void insertAtBeginning(int value) {

        // Create a new node
        Node* newNode = new Node(value);


        // Case 1: List is empty
        if (head == NULL) {

            head = newNode;

            return;
        }


        /*
            Suppose the list is:

            NULL <- 10 <-> 20 <-> 30 -> NULL

            We want to insert 5.

            New node:

            [5]

            We need:

            5 -> 10

            and

            10 -> 5
        */


        // New node's next points to current head
        newNode->next = head;


        // Current head's prev points to new node
        head->prev = newNode;


        // Make new node the head
        head = newNode;
    }


    // ==================================================
    // 5. INSERT AT END
    // ==================================================

    void insertAtEnd(int value) {

        // Create a new node
        Node* newNode = new Node(value);


        // Case 1: List is empty
        if (head == NULL) {

            head = newNode;

            return;
        }


        // Start from the first node
        Node* temp = head;


        // Move until the last node
        while (temp->next != NULL) {

            temp = temp->next;
        }


        /*
            Suppose:

            10 <-> 20 <-> 30

            temp is currently at 30.

            New node = 40.

            We need:

            30 -> 40

            and

            40 -> 30
        */


        // Last node points to new node
        temp->next = newNode;


        // New node points back to last node
        newNode->prev = temp;
    }


    // ==================================================
    // 6. INSERT AT A SPECIFIC POSITION
    // ==================================================

    void insertAtPosition(int value, int position) {

        // Position must be at least 1
        if (position < 1) {

            cout << "Invalid position.\n";
            return;
        }


        // If position is 1, insert at beginning
        if (position == 1) {

            insertAtBeginning(value);

            return;
        }


        // Create the new node
        Node* newNode = new Node(value);


        /*
            We need to find the node just BEFORE
            the required position.

            Example:

            10 <-> 20 <-> 30 <-> 40

            Insert 25 at position 3.

            We need temp to point to 20.

            Then:

            20 <-> 30

            becomes:

            20 <-> 25 <-> 30
        */


        Node* temp = head;


        // Move to the node before the position
        for (int i = 1; i < position - 1; i++) {

            if (temp == NULL) {

                cout << "Invalid position.\n";

                delete newNode;

                return;
            }

            temp = temp->next;
        }


        // If temp is NULL, position is invalid
        if (temp == NULL) {

            cout << "Invalid position.\n";

            delete newNode;

            return;
        }


        /*
            Suppose:

            temp              temp->next
              ↓                    ↓
            [20] <-------------> [30]

            New node = [25]

            We need:

            [20] <-> [25] <-> [30]
        */


        // New node points to the node after temp
        newNode->next = temp->next;


        // New node points back to temp
        newNode->prev = temp;


        // If there is a node after temp,
        // make its prev point to newNode
        if (temp->next != NULL) {

            temp->next->prev = newNode;
        }


        // Make temp point forward to newNode
        temp->next = newNode;
    }


    // ==================================================
    // 7. DELETE FROM BEGINNING
    // ==================================================

    void deleteFromBeginning() {

        // Check if list is empty
        if (head == NULL) {

            cout << "List is empty. Cannot delete.\n";

            return;
        }


        /*
            Suppose:

            NULL <- 10 <-> 20 <-> 30 -> NULL

            We want to delete 10.

            New list:

            NULL <- 20 <-> 30 -> NULL
        */


        Node* temp = head;


        // Move head to the second node
        head = head->next;


        // If the new head exists,
        // it should not point back to the deleted node
        if (head != NULL) {

            head->prev = NULL;
        }


        // Delete the old first node
        delete temp;
    }


    // ==================================================
    // 8. DELETE FROM END
    // ==================================================

    void deleteFromEnd() {

        // Check if list is empty
        if (head == NULL) {

            cout << "List is empty. Cannot delete.\n";

            return;
        }


        // Case: only one node
        if (head->next == NULL) {

            delete head;

            head = NULL;

            return;
        }


        /*
            Move to the last node.
        */

        Node* temp = head;

        while (temp->next != NULL) {

            temp = temp->next;
        }


        /*
            Suppose:

            10 <-> 20 <-> 30

            temp points to 30.

            temp->prev points to 20.

            We make:

            20->next = NULL

            Then delete 30.
        */


        temp->prev->next = NULL;

        delete temp;
    }


    // ==================================================
    // 9. DELETE FROM A SPECIFIC POSITION
    // ==================================================

    void deleteFromPosition(int position) {

        // Check if list is empty
        if (head == NULL) {

            cout << "List is empty. Cannot delete.\n";

            return;
        }


        // Position must be positive
        if (position < 1) {

            cout << "Invalid position.\n";

            return;
        }


        // If position is 1
        if (position == 1) {

            deleteFromBeginning();

            return;
        }


        /*
            Find the node at the required position.

            Example:

            10 <-> 20 <-> 30 <-> 40

            Delete position 3.

            temp should point to 30.
        */


        Node* temp = head;


        for (int i = 1; i < position; i++) {

            if (temp == NULL) {

                cout << "Invalid position.\n";

                return;
            }

            temp = temp->next;
        }


        // If position doesn't exist
        if (temp == NULL) {

            cout << "Invalid position.\n";

            return;
        }


        /*
            Suppose:

            20 <-> [30] <-> 40

            temp = 30

            We need to connect:

            20 <-> 40

            Therefore:

            temp->prev->next = temp->next

            and

            temp->next->prev = temp->prev
        */


        // Connect previous node to next node
        temp->prev->next = temp->next;


        // Connect next node to previous node
        if (temp->next != NULL) {

            temp->next->prev = temp->prev;
        }


        // Delete the required node
        delete temp;
    }


    // ==================================================
    // 10. SEARCH
    // ==================================================

    void search(int value) {

        Node* temp = head;

        int position = 1;


        while (temp != NULL) {

            if (temp->data == value) {

                cout << "Element found at position "
                     << position << ".\n";

                return;
            }

            temp = temp->next;

            position++;
        }


        cout << "Element not found.\n";
    }
};


// ======================================================
// MAIN FUNCTION
// ======================================================

int main() {

    DoublyLinkedList list;

    int choice;
    int value;
    int position;


    do {

        cout << "\n========== DOUBLY LINKED LIST ==========\n";

        cout << "1. Create List\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Insert at Beginning\n";
        cout << "5. Insert at End\n";
        cout << "6. Insert at Position\n";
        cout << "7. Delete from Beginning\n";
        cout << "8. Delete from End\n";
        cout << "9. Delete from Position\n";
        cout << "10. Search\n";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {

            case 1:

                list.create();

                break;


            case 2:

                list.displayForward();

                break;


            case 3:

                list.displayBackward();

                break;


            case 4:

                cout << "Enter value: ";
                cin >> value;

                list.insertAtBeginning(value);

                break;


            case 5:

                cout << "Enter value: ";
                cin >> value;

                list.insertAtEnd(value);

                break;


            case 6:

                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> position;

                list.insertAtPosition(value, position);

                break;


            case 7:

                list.deleteFromBeginning();

                break;


            case 8:

                list.deleteFromEnd();

                break;


            case 9:

                cout << "Enter position: ";
                cin >> position;

                list.deleteFromPosition(position);

                break;


            case 10:

                cout << "Enter value to search: ";
                cin >> value;

                list.search(value);

                break;


            case 11:

                cout << "Program ended.\n";

                break;


            default:

                cout << "Invalid choice.\n";
        }

    } while (choice != 11);


    return 0;
}
