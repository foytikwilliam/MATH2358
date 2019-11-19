#ifndef COLLATZLIST_H
#define COLLATZLIST_H

class CollatzList
{
private:
	struct ListNode
{
	int value;
	struct ListNode *next;
};

ListNode *head;

public:
	CollatzList()
		{ head = NULL; }

	~CollatzList()
	{
		ListNode *nodePtr;
		ListNode *nextNode;

		nodePtr = head;

		while (nodePtr != NULL)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}	
	void appendNode(int);
	void displayList() const;
};
#endif
