homework9: bulbasaur.o charmander.o wartortle.o pokemon.o main.o
	g++ -o homework9 bulbasaur.o charmander.o wartortle.o pokemon.o  main.o

main.o: main.cpp bulbasaur.h charmander.h wartortle.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

pokemon.o: pokemon.cpp pokemon.h
	g++ -ansi -pedantic-errors -Wall -c pokemon.cpp

bulbasaur.o: bulbasaur.cpp bulbasaur.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c bulbasaur.cpp

charmander.o: charmander.cpp charmander.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c charmander.cpp

wartortle.o: wartortle.cpp wartortle.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c wartortle.cpp

clean:
	rm -f *.o homework9
