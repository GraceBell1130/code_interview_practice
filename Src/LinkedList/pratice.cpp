#include "pratice.h"
#include <list>
#include <random>
#include <time.h>

void pratic1() 
{
	srand(time(NULL));

	std::list<int> OverlapedList;

	for (int i = 0; i < 10; i++)
	{
		OverlapedList.push_back(rand() % 10);
	}

	for (int i : OverlapedList)
	{
		printf("%-3d", i);
	}
	printf("\r\n");
	
	for (std::list<int>::iterator checker = OverlapedList.begin(); checker != OverlapedList.end(); checker++)
	{	
		for (std::list<int>::iterator innerChecker = std::next(checker, 1); innerChecker != OverlapedList.end();)
		{
			if (*checker == *innerChecker)
			{
				innerChecker++;
				OverlapedList.erase(std::next(innerChecker, -1));
				continue;
			}
			innerChecker++;
		}
	}
	for (int i : OverlapedList)
	{
		printf("%-3d", i);
	}
}

struct Node
{
	Node* next;
	int value;

	Node(int value = 0) : next(NULL), value(value)
	{}
	
	void append(Node* nextNode)
	{
		Node* node = this;

		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = nextNode;
	}
	void printAllNode()
	{
		Node* node = this;
		while (node->next != NULL)
		{
			printf("%d -> ", node->value);
			node = node->next;
		}
		printf("%d \r\n", node->value);

	}
};

void pratic2()
{
	srand(time(NULL));
	Node* first = new Node;
	Node* backup = first;
	for (int i = 0; i < rand() % 30; i++)
	{
		first->value = rand() % 10;
		first->next = new Node;
		first = first->next;
	}
	first->next = NULL;

	first = backup;
	while (first->next != NULL)
	{
		printf("%-3d", first->value);
		first = first->next;
	}
	first = backup;

	int index = 0;
	printf("\r\ninput reverse index : ");
	scanf_s("%d", &index);
	int sizeCount = 0;
	while (first->next != NULL)
	{
		first = first->next;
		sizeCount++;
	}

	first = backup;
	for (int i = 0; i < sizeCount; i++)
	{
		if (index == i)
		{
			break;
		}
		first = first->next;
	}
	printf("reuslt : %d\r\n", first->value);
	while (first->next != NULL)
	{
		backup = first->next;
		delete first;
		first = backup;
	}

}
void pratic3()
{
	Node* first = new Node;
	Node* backup = first;

	for (int i = 0; i < 5; i++)
	{
		backup->value = 'a' + i;
		if (i == 4)
		{
			backup->next = NULL;
			break;
		}
		backup->next = new Node;
		backup = backup->next;
	}	
	backup = first;
	while (backup->next != NULL)
	{
		printf("%c -> ", backup->value);
		backup = backup->next;
	}
	printf("%c\r\n", backup->value);
	backup = first;

	printf("select char : ");
	char SelectNodeData = 'a';
	scanf_s("%c", &SelectNodeData);

	Node* selectNode = NULL;
	while (backup->next != NULL)
	{
		if (backup->next->value == SelectNodeData)
		{
			selectNode = backup;
			break;
		}
		backup = backup->next;
	}
	backup = selectNode->next;
	selectNode->next = selectNode->next->next;
	delete backup;
	backup = first;
	while (backup->next != NULL)
	{
		printf("%c -> ", backup->value);
		backup = backup->next;
	}
	printf("%c\r\n", backup->value);

	while (first->next != NULL)
	{
		backup = first->next;
		delete first;
		first = backup;
	}
}

void pratic4()
{
	srand(time(NULL));
	std::list<int> NodeList;
	for (int i = 0; i < 10; i++)
	{
		NodeList.push_back(rand() % 10);
	}

	for (std::list<int>::iterator iter=NodeList.begin(); iter != NodeList.end(); iter++)
	{
		if (iter._Ptr->_Next == NodeList.end()._Ptr)
		{
			printf("%d\r\n", iter._Ptr->_Myval);
			break;
		}
		printf("%d -> ", iter._Ptr->_Myval);
	}

	printf("select data : ");
	int SelectNodeData = 0;
	scanf_s("%d", &SelectNodeData);

	for (std::list<int>::iterator iter = NodeList.begin(); iter != NodeList.end();)
	{
		if (iter._Ptr->_Myval < SelectNodeData)
		{
			NodeList.push_front(iter._Ptr->_Myval);
			iter++;
			NodeList.erase(std::prev(iter));
			continue;
		}
		iter++;
	}

	for (std::list<int>::iterator iter = NodeList.begin(); iter != NodeList.end(); iter++)
	{
		if (iter._Ptr->_Next == NodeList.end()._Ptr)
		{
			printf("%d\r\n", iter._Ptr->_Myval);
			break;
		}
		printf("%d -> ", iter._Ptr->_Myval);
	}

}

void pratic5()
{
	rsize_t tLoopCount = 3;
	std::list<int> listFirst;
	std::list<int> listSecond;

	listFirst.push_back(7);
	listFirst.push_back(1);
	listFirst.push_back(6);

	listSecond.push_back(5);
	listSecond.push_back(9);
	listSecond.push_back(2);

	std::list<int>::iterator tempIter = listFirst.begin();
	while (tempIter != listFirst.end())
	{
		if (tempIter._Ptr->_Next == listFirst.end()._Ptr)
		{
			printf("%d\r\n", tempIter._Ptr->_Myval);
			break;
		}
		printf("%d->", tempIter._Ptr->_Myval);
		tempIter._Ptr = tempIter._Ptr->_Next;
	}

	tempIter = listSecond.begin();
	while (tempIter != listSecond.end())
	{
		if (tempIter._Ptr->_Next == listSecond.end()._Ptr)
		{
			printf("%d\r\n", tempIter._Ptr->_Myval);
			break;
		}
		printf("%d->", tempIter._Ptr->_Myval);
		tempIter._Ptr = tempIter._Ptr->_Next;
	}

	int nFirstValue = 0;
	int nSecondValue = 0;
	std::list<int>::iterator::_Nodeptr listFirstPtr = listFirst.begin()._Ptr;
	std::list<int>::iterator::_Nodeptr listSecondPtr = listSecond.begin()._Ptr;
	bool checkUpper = false;
	std::list<int> listResult;
	for (rsize_t i = 0;  i < tLoopCount; i++)
	{
		int tempFirstValue = listFirstPtr->_Myval;
		int tempSecondValue = listSecondPtr->_Myval;
		int tempResult = tempFirstValue + tempSecondValue;

		if (checkUpper)
		{
			tempResult++;
			checkUpper = false;
		}

		if (tempResult > 9)
		{
			checkUpper = true;
			tempResult%=10;
		}

		listResult.push_back(tempResult);
		listFirstPtr = listFirstPtr->_Next;
		listSecondPtr = listSecondPtr->_Next;
	}

	listFirst.clear();
	listFirst.push_back(6);
	listFirst.push_back(1);
	listFirst.push_back(7);

	listSecond.clear();
	listSecond.push_back(2);
	listSecond.push_back(9);
	listSecond.push_back(5);

	listFirstPtr = listFirst.end()._Ptr->_Prev;
	listSecondPtr = listSecond.end()._Ptr->_Prev;
	std::list<int> listReverseResult;
	for (rsize_t i = 0; i < tLoopCount; i++)
	{
		int tempFirstValue = listFirstPtr->_Myval;
		int tempSecondValue = listSecondPtr->_Myval;
		int tempResult = tempFirstValue + tempSecondValue;

		if (checkUpper)
		{
			tempResult++;
			checkUpper = false;
		}

		if (tempResult > 9)
		{
			checkUpper = true;
			tempResult %= 10;
		}

		listReverseResult.push_front(tempResult);
		listFirstPtr = listFirstPtr->_Prev;
		listSecondPtr = listSecondPtr->_Prev;
	}

	for (std::list<int>::iterator iter = listResult.begin(); iter != listResult.end(); iter++)
	{
		if (listResult.end()._Ptr->_Prev == iter._Ptr)
		{
			printf("%d\r\n", iter._Ptr->_Myval);
			break;
		}
		printf("%d->", iter._Ptr->_Myval);
	}


	for (std::list<int>::iterator iter = listReverseResult.begin(); iter != listReverseResult.end(); iter++)
	{
		if (listReverseResult.end()._Ptr->_Prev == iter._Ptr)
		{
			printf("%d\r\n", iter._Ptr->_Myval);
			break;
		}
		printf("%d->", iter._Ptr->_Myval);
	}
}

void pratic6()
{
	std::list<int> NodeList;
	NodeList.push_back(2);
	NodeList.push_back(3);
	NodeList.push_back(2);

	bool bPalindromeCheck = true;
	for (std::list<int>::iterator iter = NodeList.begin(); iter != NodeList.end(); iter++)
	{
		if (NodeList.end()._Ptr->_Prev == iter._Ptr)
		{
			printf("%d\r\n", iter._Ptr->_Myval);
			break;
		}
		printf("%d->", iter._Ptr->_Myval);
	}

	std::list<int>::iterator::_Nodeptr listFrontNode = NodeList.begin()._Ptr;
	std::list<int>::iterator::_Nodeptr listBackNode = NodeList.end()._Ptr->_Prev;
	for (rsize_t i = 0; i < NodeList.size() / 2; i++)
	{
		if (listFrontNode->_Myval != listBackNode->_Myval)
		{
			bPalindromeCheck = false;
			break;
		}
		listFrontNode = listFrontNode->_Next;
		listBackNode = listBackNode->_Prev;
	}

	if(bPalindromeCheck)
	{
		printf("NodeList is PalindromeCheck");
	}
	else
	{
		printf("NodeList is not PalindromeCheck");
	}
}

struct Node2
{
	Node2* next;
	Node2* prev;
	int value;
	Node2(int value): next(NULL), prev(NULL), value(value)
	{
	}

	void push_back(Node2* Node)
	{
		Node2* temp = this;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = Node;
		Node->prev = temp;
	}
	void push_front(Node2* Node)
	{
		Node2* temp = this;
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
		temp->prev = Node;
		Node->next = temp;
	}
};

void pratic6_mine()
{
	Node2* NodeList = new Node2(2);
	NodeList->push_back(new Node2(2));
	NodeList->push_back(new Node2(2));
	NodeList->push_back(new Node2(2));
	NodeList->push_back(new Node2(3));
	NodeList->push_front(new Node2(2));
	NodeList->push_front(new Node2(3));

	while (NodeList->prev != NULL)
	{
		NodeList = NodeList->prev;
	}

	bool bPalindromeCheck = false;
	while (NodeList != NULL)
	{
		if (NodeList->next == NULL)
		{
			printf("%d\r\n", NodeList->value);
			break;
		}
		printf("%d->", NodeList->value);
		NodeList = NodeList->next;
	}

	if (bPalindromeCheck)
	{
		printf("NodeList is PalindromeCheck");
	}
	else
	{
		printf("NodeList is not PalindromeCheck");
	}
}

int getNodeSize(Node* node)
{
	int count = 0;
	while (node->next != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void checkInterSection(Node* left, Node* right)
{
	int sizeLeft = getNodeSize(left);
	int sizeRight = getNodeSize(right);
	
	Node* thanBigNode;

	if (sizeLeft > sizeRight)
	{
		thanBigNode = left;
	}
	else
	{
		thanBigNode = right;
	}

	for (rsize_t i = 0; i < abs(sizeLeft - sizeRight);i++)
	{
		thanBigNode = thanBigNode->next;
	}

	if (sizeLeft > sizeRight)
	{
		if (thanBigNode == right)
		{
			printf("InterSection Node");
		}
	}
	else
	{
		if (thanBigNode == left)
		{
			printf("InterSection Node");
		}
	}
}

void pratic7()
{
	srand(time(NULL));

	Node* node1 = new Node((rand() % 10) + 1);
	Node* node2 = new Node((rand() % 10) + 1);

	for (rsize_t i = 0; i < 3; i++)
	{
		Node* tempNode = new Node(rand() % 5);
		node1->append(tempNode);
	}

	for (rsize_t i = 0; i < 2; i++)
	{
		Node* tempNode = new Node(rand() % 5);
		node2->append(tempNode);
	}

	node2->append(node1);

	node1->printAllNode();
	node2->printAllNode();

	checkInterSection(node1, node2);
}

void pratic8()
{
	Node* A = new Node('A');
	A->append(new Node('B'));
	A->append(new Node('C'));
	A->append(new Node('D'));
	A->append(new Node('E'));
	A->append(A->next->next);
	
	Node* iter = A;
	Node* runner = A;
	while (iter && iter->next != NULL)
	{
		iter = iter->next;
		runner = runner->next->next;
		if (iter == runner)
		{
			iter = A;
			while (iter != runner)
			{
				iter = iter->next;
				runner = runner->next;
			}
			break;
		}
	}

	printf("%c", iter->value);
}