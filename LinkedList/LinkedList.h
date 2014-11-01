
#include <iostream>

class LinkedList
{
private:
	struct List
	{
		int var;
		List *next;
	};
	List *prev, *cur, *head, *tail;

public:

	LinkedList();
	~LinkedList();
	void initialize(int var);
	void addToHead(int val);
	void addToTail(int val);
	void deleteNode(int val);
	void deleteTailNode();
	void findMidPoint();
	
	void reverseList();
	void print();	
};

struct nextList
{
	int var;
	nextList *Next;
};

nextList *initList(nextList * &head, nextList * &cur, int val);
void reverseRecursive(nextList * &node);
void print(nextList *node);


