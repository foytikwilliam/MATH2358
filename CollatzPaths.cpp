#include <iostream>
#include "CollatzList.h"

using namespace std;

void CollatzList::appendNode( int n )
{
	ListNode *newNode;
	ListNode *nodePtr;
	
	newNode = new ListNode;
	newNode->value = n;
	newNode->next = NULL;
	
	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;
		while(nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}
void CollatzList::displayList() const
{
	ListNode *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout<<nodePtr->value<<" <== ";
		nodePtr = nodePtr->next;
	}
	
}
int consolePath( int n)
{
	int choose;
	cout<<"("<<2*n<<" , "<<(-1+2*n)/3<<")";
	int leftNode = 2*n;
	int rightNode = (-1+2*n)/3;
	cin >> choose;
	if (choose == leftNode)
		return leftNode;
	else if (choose == rightNode)
		return rightNode;
	else
		return n;	
	cin.ignore();	
}

void collatzPath( int n, CollatzList *test )
{
	test->appendNode(n);
	while (n<1025110000)
	{
		if ((-1+n*2)%3==0)
		{
			test->displayList();
			return collatzPath(consolePath(n),test);

		}
		else
		{
			return collatzPath(n*2,test);
		}
	}
	test->displayList();
}

int main()
{
	
	CollatzList *test;
	test = new CollatzList;	
	test->appendNode(1);
	test->appendNode(2);
	test->appendNode(4);

	collatzPath(8,test);
	return 0;
}
