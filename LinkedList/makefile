
link: main.o LinkedList.o
	g++ -std=c++0x -o link main.o LinkedList.o -lrt -lpthread
	if [ -d obj ]; then rm -r obj; fi
	mkdir obj
	mv *.o ./obj
main.o: main.cpp
	g++ -std=c++0x -c -Wall -I./include main.cpp
LinkedList.o: LinkedList.cpp
	g++ -std=c++0x -c -Wall -I./include LinkedList.cpp
clean:
	rm -f -r *.o ./obj link 
