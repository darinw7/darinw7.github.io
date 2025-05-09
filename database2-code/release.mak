project: user_interface.o llist.o
	g++ -o project user_interface.o llist.o

llist.o: llist.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp

user_interface.o: user_interface.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp

clean:
	rm -f *.o project
