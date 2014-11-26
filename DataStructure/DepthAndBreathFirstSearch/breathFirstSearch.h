
#include <iostream>

// The classes and methods resemble
// those of Depth first search algorithm
// a Queue is implemented for the BFS instead of a stack in DFS

class Queue
{
private:
	struct queueList
	{
		int var;
		queueList *next;
	};
	queueList *head, *cur;
	
	struct visited
	{
		int visit;
		visited *next;
	};
	visited *Head, *Cur;
	
public:
	Queue();
	~Queue();
	void enqueue(int val);
	int getTop();
	void pop();
	void printQueue();
	void printPath(queueList *&);
	bool isQueueEmpty();
	
	void visitedNode(int val);
	bool isVisited(int val);
	void printVisitedNode();
};

class BreathFirstSearch
{
private:
	struct List
	{
		int first;
		int sec;
		List *next;
	};
	List *head, *cur;
public:	
	BreathFirstSearch();
	~BreathFirstSearch();
	// Initialize nodes - create paths
	void initialize(int f, int s);
	// Depth First Search - Non recursive
	void search(int node);
	void print();
};


