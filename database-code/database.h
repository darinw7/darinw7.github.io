/*****************************************************************

//  NAME:        Darin Wong
//
//  HOMEWORK:    Project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 26, 2024
//
//  FILE:        database.h
//
//  DESCRIPTION: This file includes function prototypes for
//               records in the database.
//
****************************************************************/

#ifndef _DATABASEH_
#define _DATABASEH_
#include "record.h"

int addRecord (struct record **, int, char [ ],char [ ]);
void printAllRecords(struct record *);
int findRecord (struct record *, int);
int deleteRecord(struct record **, int);
int writefile(struct record *, char []);
int readfile(struct record **, char []);
void cleanup(struct record **);

#endif
