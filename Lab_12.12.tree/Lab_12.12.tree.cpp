#include <iostream>

using namespace std;

struct Note {
    char surname[50];
    char name[50];
    char phoneNumber[20];
    int day;
    int month;
    int year;
    Note* left;
    Note* right;
};

void addNoteToBinaryTree(Note*& root, Note* newNode) {
    if (root == nullptr) {
        root = newNode;
        return;
    }

    int comparisonResult = strcmp(newNode->surname, root->surname);

    if (comparisonResult < 0) {
        addNoteToBinaryTree(root->left, newNode);
    }
    else {
        addNoteToBinaryTree(root->right, newNode);
    }
}

void addNote(Note*& root) {
    char surname[50], name[50], phoneNumber[20];
    int day, month, year;

    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter birthday (day month year): ";
    cin >> day >> month >> year;

    Note* newNote = new Note;

    int i;
    for (i = 0; surname[i] != '\0' && i < sizeof(newNote->surname) - 1; ++i) {
        newNote->surname[i] = surname[i];
    }
    newNote->surname[i] = '\0';

    for (i = 0; name[i] != '\0' && i < sizeof(newNote->name) - 1; ++i) {
        newNote->name[i] = name[i];
    }
    newNote->name[i] = '\0';

    for (i = 0; phoneNumber[i] != '\0' && i < sizeof(newNote->phoneNumber) - 1; ++i) {
        newNote->phoneNumber[i] = phoneNumber[i];
    }
    newNote->phoneNumber[i] = '\0';

    newNote->day = day;
    newNote->month = month;
    newNote->year = year;
    newNote->left = nullptr;
    newNote->right = nullptr;

    addNoteToBinaryTree(root, newNote);
}

void printByMonth(Note* root, int month) {
    if (root == nullptr) {
        return;
    }

    printByMonth(root->left, month);

    if (root->month == month) {
        cout << "Surname: " << root->surname << endl;
        cout << "Name: " << root->name << endl;
        cout << "Phone Number: " << root->phoneNumber << endl;
        cout << "Birthday: " << root->day << "." << root->month << "." << root->year << endl;
        cout << endl;
    }

    printByMonth(root->right, month);
}


void printAddressBook(Note* root) {
    if (root == nullptr) {
        return;
    }

    printAddressBook(root->left);

    cout << "Surname: " << root->surname << endl;
    cout << "Name: " << root->name << endl;
    cout << "Phone Number: " << root->phoneNumber << endl;
    cout << "Birthday: " << root->day << "." << root->month << "." << root->year << endl;
    cout << endl;

    printAddressBook(root->right);
}

int main() {
    Note* addressBook = nullptr;
    int numMonth;


    int choice;
    do {
        cout << "========== Menu ==========" << endl;
        cout << "1. Add Note" << endl;
        cout << "2. Sort Alphabetically" << endl;
        cout << "3. Search By Month" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            addNote(addressBook);
            break;
        }
        case 2:
        {
            printAddressBook(addressBook);
            break;
        }
        case 3: {
            cout << "Enter the month: ";
            cin >> numMonth;

            printByMonth(addressBook, numMonth);
            break;
        }
        case 4: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
