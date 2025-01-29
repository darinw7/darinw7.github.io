/*****************************************************************
//
//  NAME:        Darin Wong
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 12, 2024
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   This program creates a table of numbers from 0 to the maximum
//   number that the user inputs, and then tells whether or not
//   each number within that interval is a multiple of 3 or not.
//
****************************************************************/

#include <stdio.h>

int user_interface();
int is_multiple3(int num);
void print_table(int max_num);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function starts by calling the
//                 user_interface for a maximum number that the
//                 user inputs. After, it calls the print_table
//                 function to print numbers from 0 to the user's
//                 maximum number, showing if they are multiple of
//                 3 or not.
//
//  Parameters:    None
//
//  Return values:  0 : executes successfully
//
****************************************************************/

int main() {
    int max_num = user_interface();
    print_table(max_num);
    return 0;
}

/****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   This function starts by asking the user to
//                 enter a maximum number to create the
//                 table. It reads whatever the user inputs and
//                 determines if it is a positive integer. If not,
//                 it will keep on asking the user until it gets
//                 a valid input.
//
//  Paramaters:    none
//
//  Return values: int: the integer input that the user enters
//
***************************************************************/

int user_interface(){
    int num;
    char buffer[100];
    while(1){
        printf("This program creates a table of numbers from 0 to a maximum number of the user's choosing, and whether or not it is a multiple of 3. \n");
        printf("Enter maximum number to show: ");
        if(fgets(buffer,sizeof(buffer),stdin) != NULL) {
            if(sscanf(buffer, "%d",&num) ==1 && num > 0){
                return num;
            } else {
                printf("Invalid input. Please enter a positive integer. \n");
            }
        }
    }
}

/****************************************************************
//
//  Function name: is_multiple3
//
//  DESCRIPTION:   This function checks to see if the integer is
//                 a multiple of 3. If it is, it returns 1, and 0
//                 if not.
//
//  Parameters:    num(int): number that is passed to function
//                 to check
//
//  Return values: 1: number is a multiple of 3
//                 0: number is not a multiple of 3
//
//
*****************************************************************/

int is_multiple3(int num){
    int result;
    if(num == 0){
        result = 0;
    } else {
        result = (num % 3 == 0);
    }
    return result;
}

/***************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   This function creates a table with the table
//                 of numbers from 0 running up to the max number
//                 that is inputted by the user. Thereafter, for
//                 each number, it will print whether or not it
//                 is a multiple of 3, and is formatted using
//                 right-aligned columns.
//
//  Parameters:    max_num(int): the maximum number to print into table
//
//  Return values: none
//
***************************************************************/

void print_table(int max_num){
    int i; 
    printf("  Number   Multiple of 3?\n");
    for(i = 0; i <= max_num; i++){
        printf("%8d    %s\n", i, is_multiple3(i) ? "Yes" : "No");
    }
}

