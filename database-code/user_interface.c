/**********************************************************************************
//
//  NAME:        Darin Wong
//
//  HOMEWORK:    Project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 4, 2024
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: This file includes the user-interface in which allows us then
//               to access the database. It starts by sending a intro message
//               to the user, followed by asking them to select a menu option
//               which is displayed on the screen. After the user then selects
//               an option, additional information may be requested in the case
//               that it must receive input in order to have the necessary 
//               information processing. Then, it calls the function from the
//               database that matches the menu option that the user inputed.
//               Then, the results would be displayed except that the functions. 
//               Nontheless, it would then repeat through this entire process
//               again until the user decides to quit the program.
//
************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"
#include "record.h"

int debugmode = 0;

void getaddress (char [], int);
void displayMenu();
void runUI();

/***************************************************************************
//  Function name: getaddress
//
//  DESCRIPTION:   This function gets the address input from the user,
//                 which can have many lines and any format but must stay
//                 within the character array limit that is set.
//
//  Parameters:    address(char[]): character array that stores an address
//                 size(int): size of array
//
//  Return values: void
//
******************************************************************************/

void getaddress(char address[], int size){
    char temp[256];
    char * res;
    int stop = 0;
  
    printf("Enter the address (Press Enter twice to finish): \n");
    address[0] = '\0';

    while(!stop) {
        res = fgets(temp, sizeof(temp), stdin);

        if(res == NULL || (temp[0] == '\n' && address[0] != '\0')) {
            stop = 1;
        } else if ((strlen(address) + strlen(temp)) + 1 < size) {
            strcat(address, temp);
        } else {
            printf("Address is too long, shortening input.\n");
            stop = 1;
        }
    }
}

/*******************************************************************
//
//  Function name: displayMenu
//
//  DESCRIPTION:   This function displays the list of options in
//                 the user interface that the user can enter and
//                 a brief description for what they do. 
//
//  Parameters:    none
//
//  Return values: none
//
*********************************************************************/

void displayMenu(){
    printf("\nWelcome to the bank database!\n");
    printf("Please choose one of the options below.\n");
    printf("add: Add a new record\n");
    printf("printall: Print all records\n");
    printf("find: Find a record\n");
    printf("delete: Delete a record\n");
    printf("quit: Quit the program\n");
}

/*****************************************************************
//
//  Function name: runUI
//
//  DESCRIPTION:   This function starts by running the user interface
//                 loop and displaying the menu to the user. Once
//                 it accepts the user's input, it then calls the
//                 database for its' functions and chooses the right
//                 one depending what the user chooses. For a few
//                 of the options, the user is then required to input
//                 more information based on what is necessary to
//                 make it function properly.
//
//  Parameters:    None
//
//  Return values: None
//
****************************************************************/

void runUI(){
    struct record * start = NULL;
    char option[10];
    int accountnumber;
    char name[25];
    char address[45];
    int running = 1;

    readfile(&start, "records.txt");

    while(running) {
        displayMenu();
        printf("\nYour choice: ");
        fgets(option,sizeof(option),stdin);
        option[strcspn(option, "\n")] = '\0';

        if((strncmp(option,"add", 3) == 0 || strncmp(option,"a",1) == 0 || strncmp(option,"ad",2) == 0) && strlen(option) <= 3) {
            printf("Enter your account number: ");
            while(scanf("%d", &accountnumber)!= 1 || accountnumber <= 0){
                printf("Error.  Please enter a positive integer: ");
                while(getchar() != '\n');
            }
        getchar();
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        getaddress(address,sizeof(address));

        if(addRecord(&start, accountnumber, name, address) == -1) {
            printf("Error: Duplicate account number.\n");
        } else {
            printf("Successfully added a record.\n");
        }
       } else if(((strncmp(option,"printall", 8) == 0 || strncmp(option,"p",1) == 0 || strncmp(option,"pr",2) == 0 || strncmp(option,"pri",3) == 0 || strncmp(option, "prin",4) == 0 || strncmp(option,"prin       t",5) == 0 || strncmp(option,"printa",6) == 0 || strncmp(option,"printal",7) == 0) && strlen(option) <= 8)){
       printAllRecords(start);

       } else if((strncmp(option, "find", 4) == 0 || strncmp(option,"f",1) == 0 || strncmp(option,"fi",2) == 0 || strncmp(option,"fin",3) == 0) && strlen(option) <= 4){
           printf("Enter account number to find record: ");
           while(scanf("%d",&accountnumber) !=1 || accountnumber <= 0){
               printf("Error. Please enter a positive integer: ");
               while(getchar() != '\n');
           }
       getchar();
       findRecord(start, accountnumber);
 
       } else if((strncmp(option, "delete", 6) == 0 || strncmp(option,"d",1) == 0 || strncmp(option,"de",2) == 0 || strncmp(option,"del",3)==0 || strncmp(option,"dele",4)==0 || strncmp(option,"delet",5)
       == 0) && strlen(option) <= 6){
           printf("Enter account number to delete: ");
           while(scanf("%d",&accountnumber) != 1 || accountnumber <= 0){
               printf("Error. Please enter a positive integer: ");
               while(getchar() != '\n');
           }
           getchar();
           if(deleteRecord(&start, accountnumber) == -1) {
               printf("Account not found or could not be deleted.\n");
           } else {
               printf("Account deleted successfully.\n");
           }
       } else if((strncmp(option, "quit", 4) == 0 || strncmp(option,"q",1)==0 || strncmp(option,"qu",2) == 0 || strncmp(option,"qui",3) == 0) && strlen(option)<=4){
           writefile(start, "records.txt");
           cleanup(&start); 
           running = 0;

       } else {
           printf("Invalid option. Try again.");
       }
    }
}

/************************************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function starts the debug mode only if the amount of
//                 arguments is exactly 2 and if the second arg is 'debug'. If
//                 there are more than 2 or the second arg is anything other than
//                 'debug',than the program will display an error and exit. Therefore,
//                 if debug mode is successful,than the runUI program will be run.
//
//  Parameters:    argc(int): # of command-line arguments
//                 argv(char*[]): array of chars showing the command-line args
//
//  Return values: 0: program successfully runs
//
*****************************************************************************************/

int main(int argc, char* argv []){
    if(argc == 2 && strcmp(argv[1], "debug") == 0){
        debugmode = 1;
        printf("\nDebug mode activated.\n");
    } else if (argc > 2 || (argc == 2 && strcmp(argv[1], "debug") != 0)){
        printf("Invalid command line arguments. Exiting....\n");
     return 1;
    }
    
    runUI();
    return 0;
}

