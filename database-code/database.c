/************************************************************************************
//
//  NAME:        Darin Wong
//
//  HOMEWORK:    Project1
// 
//  CLASS:       ICS 212
// 
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 2, 2024
// 
//  FILE:        database.c
// 
//  DESCRIPTION: This file implements the functions that are used to create a linked
//               linked list of account records that belong to the customer. All
//               records include an account number and address, name, and address. 
//               Within the database, the functions it allows us to use are for
//               adding a new record in ascending order, print all records, printing
//               or deleting a record with a specific account number, writing records
//               to a file, and reading from a file.
//
*************************************************************************************/

#include <stdio.h>
#include "database.h"
#include "record.h"
#include <stdlib.h>
#include <string.h>

extern int debugmode;
struct record *temp;
struct record *current;
struct record *prev;
struct record *next;
/****************************************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   This function adds a new record to the linked list, of which is inserted
//                 based on the account numbers being sorted in ascending order. When
//                 there are duplicates attempted to be added, it will return -1 and not
//                 add that record.
//
//
//  PARAMETERS:    start(struct record **): pointer to start of records
//                 accountnumber(int): the account number
//                 name(char []): name of the person who owns this account
//                 address(char []): address of the person who owns this account
//
//  Return values: 0(success)
//
********************************************************************************************************/

int addRecord (struct record ** start, int uaccountno, char* uname, char* uaddress) {
    if(debugmode) {
        printf("\n[DEBUG] \nCalling addRecord with \naccountno: %d \nname: %s \naddress: \n%s\n", uaccountno, uname, uaddress);
    }
    
    temp = (struct record *) malloc(sizeof(struct record));
    if(!temp) {
        return -1;
    }
    
    (*temp).accountno = uaccountno;
    strcpy((*temp).name, uname);
    strcpy((*temp).address, uaddress);
    (*temp).next = NULL;

    if(*start == NULL) {
        *start = temp;
        return 0;
    }

    current = *start;
    prev = NULL;

    while(current != NULL) {
        if((*current).accountno == uaccountno) {
            free(temp);
            return -1;
        } else if((*current).accountno > uaccountno) {
            if(prev == NULL) {
                (*temp).next = *start;
                *start = temp;
            } else {
                (*temp).next = current;
                (*prev).next = temp;
            }
            return 0;
        } else {
            prev = current;
            current = (*current).next;
        }
    }

    (*prev).next = temp;
    return 0;
}

/***********************************************************************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   This function prints all the records that are in the database, which includes the account number,
//                 name, and address. If there are no records in the list, a message will be printed saying that there
//                 are no records to display.
//
//  Parameters:    start(struct record *): pointer to start of records
//
//  Return values: void
//
*************************************************************************************************************************/

void printAllRecords(struct record * start) {
    struct record *current = start;
    if (debugmode) {
        printf("\n[DEBUG] Called printAllRecords\n");
    }

    if(current == NULL) {
        printf("No records to display");
        return;
    }

    printf("Printing all records!\n");
    while(current != NULL){
        printf("Account No: %d\nName: %s\nAddress: \n%s\n", (*current).accountno, (*current).name, (*current).address);
        current = (*current).next;
    }
}

/****************************************************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   This function looks for a record based on a specific account number that we enter,
//                 and prints it out if it is found. If the record is not found, it instead returns
//                 -1 for failing.
//
//  Parameters:    start(struct record *): pointer to start of records
//                 accountno(int): account number used to find record of
//
//  Return values: 0(success)
//
***********************************************************************************************/

int findRecord(struct record * start, int accountno) {
    if (debugmode) {
        printf("\n[DEBUG] Called findRecord with accountno: %d\n", accountno);
        
    }
    current = start;
    while(current != NULL) {
        if((*current).accountno == accountno) {
            printf("Account Number: %d\n", (*current).accountno);
            printf("Name: %s\n", (*current).name);
            printf("Address: %s\n", (*current).address);
            return 1;
        }
        current = (*current).next;
    }
    printf("Record with Account Number %d not found.\n", accountno);
    return -1;
}

/****************************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function deletes a record based on a specific account
//                 number that we enter, and frees up the memory. If the
//                 record is not found, it instead returns -1 for failing.
//
//  Parameters:    start(struct record **): pointer to start of records
//                 accountno(int): account number to delete
//
//  Return values: 0(success)
//
*******************************************************************************/

int deleteRecord(struct record ** start, int accountno) {
    if (debugmode) {
        printf("\n[DEBUG] Called deleteRecord with accountno: %d\n", accountno);
    }

    current = *start;
    prev = NULL;

    if(current == NULL) {
        return -1;
    }
    
    while(current != NULL) {
        if((*current).accountno == accountno) {
            if(prev == NULL) {
                *start = (*current).next;
            } else {
                (*prev).next = (*current).next;
            }
            free(current);
            return 0;
        } else {
            prev = current;
            current = (*current).next;
        }
    }
    return -1;
}

/*********************************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   This file writes records from linked list into a file. If the
//                 file can't be opened, -1 is returned.
//
//  Paramaters:    start(struct record *): pointer to start of linked list
//                 filename(char []): name of file we write records to
//
//  Return values: 0: success
//                -1: failure
//
**********************************************************************************/

int writefile(struct record *start, char filename[]) {
    FILE *file;
    
    if (debugmode) {
        printf("\n[DEBUG] Called writefile with filename: %s\n", filename);
    }

    file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error: Cannot open file %s to write to.\n", filename);
        return -1;
    }

    current = start;

    while(current != NULL) {
        fprintf(file, "%d,%s,%s\n", (*current).accountno, (*current).name, (*current).address);
        current = (*current).next;
    }

    fclose(file);
    return 0;
}

/*************************************************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This file reads records from a file into the linked list. All of the records
//                 include an account number, name, and address. For records that can't be opened,
//                 -1 is returned, and also for addresses that are too long & duplicate account
//                 numbers get skipped.
//
//
//  Parameters:    start(struct record **): pointer to start of linked list
//                 filename(char []): name of file we read records from
//
//  Return values: 0: success
//                -1: failure
//
**************************************************************************************************/

int readfile(struct record **start, char filename[]) {
    int accountno;
    char name[25];
    char address[45];
    char temp[256];
    FILE *file;

    if(debugmode) {
        printf("\n[DEBUG] Called readfile with filename: %s\n", filename);
    }    

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s to read.\n", filename);
        return -1;
    }

    while (fscanf(file, "%d,%24[^,],", &accountno, name) == 2) {
        address[0] = '\0';
        while (fgets(temp, sizeof(temp), file) != NULL) {
            if(temp[0] == '\n') {
                break;
            }

            if (strlen(address) + strlen(temp) < sizeof(address)) {
                strcat(address, temp);
            } else {
                printf("Address is too long, skipping record.\n");
                break;
            }
        }

        if (addRecord(start, accountno, name, address) == -1) {
            printf("Error: Duplicate account number %d found in file. Skipping record.\n", accountno);
        }
    }

    fclose(file);
    return 0;
}

/************************************************************************************************** 
//  Function name: cleanup
//  
//  DESCRIPTION:   This function frees up the dynamic  memory that we are allocating for in the
//                 linked list, and sets NULL to start, which makes sure that everything is cleaned
//                 up, before the program comes to an end.
//
//  Parameters:    start(struct record **): pointer to start of linked list
//
//  Return values: None(void)

***************************************************************************************************/

void cleanup(struct record **start) { 
    current = *start; 
    
    while(current != NULL) { 
        next = (*current).next;
        free(current); 
        current = next; 
    } 

    *start = NULL; 
}


