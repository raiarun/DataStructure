
#!/bin/bash

search: main.o depthFirstSearch.o breathFirstSearch.o
	g++ -std=c++0x -o search main.o depthFirstSearch.o breathFirstSearch.o -lrt
	if [ -d obj ]; then rm -r obj; fi
	mkdir obj
	mv *.o ./obj
main.o: main.cpp
	g++ -std=c++0x -c -Wall -I./include main.cpp
depthFirstSearch.o: depthFirstSearch.cpp
	g++ -std=c++0x -c -Wall -I./include depthFirstSearch.cpp
breathFirstSearch.o: breathFirstSearch.cpp
	g++ -std=c++0x -c -Wall -I./include breathFirstSearch.cpp
clean:
	rm -f -r *.o ./obj search
