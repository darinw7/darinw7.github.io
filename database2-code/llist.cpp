#include "llist.h"
#include "record.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

llist::llist() : start(NULL) {
    #ifdef DEBUG
    cout << endl << "Debug mode activated." << endl;
    cout << endl << "[DEBUG] Constructor called" <<endl;
    #endif
    strcpy(filename, "data.txt");
    readfile();
}

llist::llist(char file[]): start(NULL) {
    #ifdef DEBUG
    cout << "[DEBUG] Constructor called with file name: " << file << endl;
    #endif
    strcpy(filename, file);
    readfile();
}

llist::~llist() {
    #ifdef DEBUG
    cout << "[DEBUG] Destructor called" << endl;
    #endif
    writefile();
    cleanup();
}

int llist::addRecord(int accountno, char name[], char address[]) {
    #ifdef DEBUG
    cout << endl << "[DEBUG]" << endl << "Calling addRecord with" << endl;
    cout << "accountno: " << accountno << endl;
    cout << "name: " << name << endl;
    cout << "address: " << address << endl;
    #endif

    record *current = start;
    while(current != NULL) {
        if(current->accountno == accountno) {
            return -1;
        }
        current = current->next;
    }

    record* newRecord = new record;
    newRecord->accountno = accountno;
    strcpy(newRecord->name, name);
    strcpy(newRecord->address, address);
    newRecord->next = NULL;

    if (start == NULL) {
        start = newRecord;
    } else {
        record*  current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRecord;
    }
    return 0;
}

int llist::findRecord(int accountno) {
    #ifdef DEBUG
    cout << endl << "[DEBUG] findRecord called with accountno: " << accountno << endl;
    #endif

    record *current = start;
    while (current != NULL) {
        if (current->accountno == accountno) {
            cout << "Account number: " << current->accountno << endl;
            cout << "Name: " << current->name << endl;
            cout << "Address: " << current->address << endl;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

void llist::printAllRecords() {
    #ifdef DEBUG
    cout << "[DEBUG] printAllRecords called" << endl;
    #endif

    cout << "Printing all records!";
    if(start == NULL) {
        std::cout << "No records to print." << std::endl;
    } else {
        record *current = start;
        while (current != NULL) {
            cout << endl << "Account number: " << current->accountno << endl;
            cout << "Name: " << current->name << endl;
            cout << "Address: " << endl << current->address << endl;
            current = current->next;
        }
    }
}

int llist::deleteRecord(int accountno) {
    #ifdef DEBUG
    cout << "[DEBUG] deleteRecord called with accountno: " << accountno << endl;
    #endif

    if (start == NULL) {
        cout << "No records to delete." << endl;
        return -1;
    }

    if (start->accountno == accountno) {
        record* temp = start;
        start = start->next;
        delete temp;
        cout << "ccount deleted successfully." << endl;
        return 0;
    }
        record* current = start;
        while(current != NULL && current->next != NULL) {
            if (current->next->accountno == accountno) {
                record *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return 0;
            }
        
        current = current->next;
    }

    cout << "Record with Account number: " << accountno << " not found." << endl;
    return -1;
}

int llist::readfile() {
    #ifdef DEBUG
    cout << "[DEBUG] readfile called with filename: " << filename << endl;
    #endif

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return -1;
    }

    int accountno;
    char name[100], address[500];
    while (infile >> accountno) {
        infile.ignore();
        infile.getline(name, 100);
        infile.getline(address, 500);

        addRecord(accountno, name, address);

    }
    infile.close();
    return 0;
}

int llist::writefile() {
    #ifdef DEBUG
    cout << "[DEBUG] writefile called with filename: " << filename << endl;
    #endif

    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cerr << "Error opening file " << filename << endl;
        return -1;
    }

    record *current = start;
    while (current != NULL) {
        outfile << current->accountno << endl;
        outfile << current->name << endl;
        outfile << current->address << endl;
        current = current->next;
    }

    outfile.close();
    return 0;
}

void llist::cleanup() {
    #ifdef DEBUG
    cout << "[DEBUG] cleanup called" << endl;
    #endif
    record *current = start;
    while (current != NULL) {
        record *temp = current;
        current = current->next;
        delete temp;
    }
    start = NULL;
}

llist::llist(const llist& other) : start(NULL) {
    #ifdef DEBUG
    cout << "[DEBUG] copy constructor called" << endl;
    #endif

    record *current = other.start;
    while (current != NULL) {
        addRecord(current->accountno, current->name, current->address);
        current = current->next;
    }
}

llist& llist::operator=(const llist& other) {
    #ifdef DEBUG
    cout << "[DEBUG] assignment operator called" << endl;
    #endif

    if (this == &other) {
        return *this;
    }

    record *current = other.start;
    while (current != NULL) {
        addRecord(current->accountno, current->name, current->address);
        current = current->next;
    }

    return *this;
}

ostream& operator<<(ostream& os, const llist& list) {
    #ifdef DEBUG
        cout << "[DEBUG] operator << called" << endl;
    #endif

    record *current = list.start;
    while (current != NULL) {
        os << "Account Number: " << current->accountno << endl;
        os << "Name: " << current->name << endl;
        os << endl << "Address: " << current->address << endl;
        current = current->next;
    }
    return os;
}

