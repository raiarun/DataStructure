
#include <iostream>

class stack
{
private:
	struct stackList
	{
		int var;
		stackList *next;
	};
	stackList *head, *cur;
	
	struct visited
	{
		int visit;
		visited *next;
	};
	visited *Head, *Cur;
	
public:
	stack();
	~stack();
	void push(int val);
	int getTop();
	void pop();
	void printStack();
	void printPath(stackList *&);
	bool isStackEmpty();
	
	void visitedNode(int val);
	bool isVisited(int val);
	void printVisitedNode();
};


class DepthFirstSearch
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
	DepthFirstSearch();
	~DepthFirstSearch();
	// Initialize nodes - create paths
	void initialize(int f, int s);
	// Depth First Search - Non recursive
	void search(int node);
	
	void recursion(int node, stack & obj);
	void recursiveSearch(int node);
	void print();
};

