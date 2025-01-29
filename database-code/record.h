/*****************************************************************
//
//  NAME:        Darin Wong
//
//  HOMEWORK:    Project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 26,,2024
//
//  FILE:        record.h
//
//  DESCRIPTION: This file defines the record structure which is
//               used to store all of the information that the
//               user inputs.
//
*********************************************************************/

#ifndef _RECORDH_
#define _RECORDH_

struct record
{
    int                accountno;
    char               name[25];
    char               address[45];
    struct record*     next;
};
                
#endif
