#include "array.cpp"

int main() {
    array<int> list;
    int choice, value, pos;

    do {
        cout << "\n\t\t Menu" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from Specific Position" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                list.insert_at_beginning(value);
                break;
            case 2:
                cout << "Enter the value: ";
                cin >> value;
                list.insert_at_end(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                list.insert_at_position(pos, value);
                break;
            case 4:
                list.delete_at_beginning();
                break;
            case 5:
                list.delete_at_end();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.delete_at_position(pos);
                break;
            case 7:
                cout << "Current List: ";
                list.display();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}