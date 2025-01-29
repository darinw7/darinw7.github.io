#include "llist.h"
#include <iostream>
#include <cstring>

int main() {
    llist mylist;

    bool running = true;
    while (running) {
        std::cout << std::endl << "Welcome to the bank database!" << std:: endl;
        std::cout << "Please choose one of the options below." << std:: endl;
        std::cout << "add: Add a new record." << std:: endl;
        std::cout << "printall: Print all records." << std::endl;
        std::cout << "find: Find a record." << std::endl;
        std::cout << "delete: Delete a record." << std::endl;
        std::cout << "quit: Quit the program." << std::endl;
        std::cout << std::endl << "Your choice: ";
        std::string option;
        std::getline(std::cin, option);

        if (option == "a" || option.substr(0,2) == "ad" || option.substr(0, 3) == "add") {
            int accountno;
            char name[25], address[45];
            std::cout << "Enter an account number: ";
            while(!(std::cin >> accountno) || accountno <= 0) {
                std::cout << "Error. Please enter a positive integer: ";
                std::cin.clear();
            }
            std::cin.ignore();

            std::cout << "Enter a name: ";
            std::cin.getline(name, 100);
            std::cout << "Enter an address: ";
            
            address[0] = '\0';
            char line[200];
            while(true) { 
                std::cout << "";
                std::cin.getline(line, 200);
                if (line[0] == '\0') {
                    break;
                }
                if (strlen(address) > 0) { 
                    strcat(address, "\n");
                }
                strcat(address, line);
            }

            if(mylist.addRecord(accountno, name, address) == -1) {
                std::cout << "Error: Duplicate account number." << std::endl;
            }
        }

        else if (option == "f" || option.substr(0, 2) == "fi" || option.substr(0, 4) == "find") {
            int accountno;
            std::cout << "Enter an account number to find: ";
            while(!(std::cin >> accountno) || accountno <= 0) {
                std::cout << "Error. Please enter a positive integer: ";
                std::cin.clear();
            }
            std::cin.ignore();
            mylist.findRecord(accountno);
        }

        else if (option == "d" || option.substr(0,2) == "de" || option.substr(0, 6) == "delete") {
            int accountno;
            std::cout << "Enter an account number to delete: ";
            while(!(std::cin >> accountno) || accountno <= 0) {
                std::cout << "Error. Please enter a positive integer: ";
                std::cin.clear();
            }
            std::cin.ignore();
            if(mylist.deleteRecord(accountno) == -1) {
                std::cout << "Account not found or could not be deleted." << std::endl;
            } else {
                std::cout << "Account deleted successfully." << std::endl;

            }
        }

        else if (option == "p" || option.substr(0,2) == "pr" || option.substr(0, 5) == "print") {
                mylist.printAllRecords();
        }

        else if (option == "q" || option.substr(0,2) == "qu" || option.substr(0, 4) == "quit") {
            running = false;
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
