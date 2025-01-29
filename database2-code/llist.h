#ifndef LLIST_H
#define LLIST_H

#include "record.h"
#include <ostream>

class llist
{
    private:
        record*     start;
        char        filename[20];
        int         readfile();
        int         writefile();
        void        cleanup();

    public:
        llist();
        llist(char[]);
        ~llist();
        int addRecord(int, char [ ],char [ ]);
        int findRecord(int);
        void printAllRecords();
        int deleteRecord(int);

        llist(const llist&);
        llist& operator = (const llist&);
        friend std::ostream& operator<<(std::ostream&, const llist&);
};

#endif
