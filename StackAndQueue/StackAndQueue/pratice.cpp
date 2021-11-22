#include "pratice.h"
#include <vector>
#include <random>
#include <iostream>
#include <limits>

void pushData(std::vector<int>& vecArray, int* separator, int value)
{
	if (*separator < *(separator + 1) )
	{
		vecArray.at(*separator) = value;
		(*separator)++;
	}
	else
	{
		std::cout << "Push Fail : " << *separator << std::endl;
	}
}

int popData(std::vector<int>& vecArray, int* separator)
{
	int returnData = vecArray.at((*separator - 1));
	if (*separator > 0)
	{
		(*separator)--;
	}
	
	return returnData;
}

void pratic1()
{
	std::vector<int> vecArray(10);

	int separator[4] = {0, ((vecArray.size() / 3) * 1), ((vecArray.size() / 3) * 2), vecArray.size() };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> distribution(0, vecArray.size() / 3 + 1);
	for (rsize_t i = 0; i < 3; i++)
	{
		size_t count = distribution(gen);
		do
		{
			pushData(vecArray, separator + i, distribution(gen));
		} while (count-- );
	}

	for (rsize_t i = 0; i < 3; i++)
	{
		do
		{
			std::cout << popData(vecArray, separator + i) << " ";
		} while (separator[i] > (vecArray.size() / 3) * i);
		std::cout << std::endl;
	}

}


struct stStackNode
{
	int value;
	int min;
	stStackNode* next;
	stStackNode(int value) : value(value), min(value), next(NULL)
	{}
};
class STACK
{
	stStackNode* top;

public:
	STACK():top(NULL)
	{}

	void push(int value)
	{
		stStackNode* t = new stStackNode(value);
		t->next = top;
		if (top != NULL && top->min < value)
		{
			t->min = top->min;
		}
		top = t;
	}

	int pop()
	{
		if (top == NULL) return 0;
		int returnValue = top->value;
		top = top->next; 
		return returnValue;
	}

	int min()
	{
		return top->min;
	}
};

void pratic2()
{
	STACK stack;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> distribution(0, 10);
	for (rsize_t i = 0 ; i < 5; i++)
	{	
		stack.push(distribution(gen));
	}

	std::cout << stack.min() << std::endl;

	for (rsize_t i = 0; i < 5; i++)
	{
		std::cout << i << "_" << stack.pop() << " ";
	}
	std::cout << std::endl;
}

struct stStack
{
	int value;
	stStack* next;

	stStack() : value(0), next(NULL)
	{
	}
};

class cStack
{
	stStack* top;
public:
	cStack() : top(NULL)
	{
	}

	void push(int value)
	{
		stStack* node = new stStack;
		node->value = value;
		if (top == NULL)
		{
			top = node;
		}
		else
		{
			node->next = top;
			top = node;
		}
	}

	int pop()
	{
		if (top == NULL)
		{
			return -1;
		}
		int value = top->value;
		top = top->next;
		return value;
	}

	int peek()
	{
		if (top != NULL)
		{
			return top->value;
		}
		else
		{
			return -1;
		}
	}

	bool isEmpty()
	{
		return (top == NULL);
	}
};

class cSetOfStacks
{
	int count;
	cStack node;
	cSetOfStacks* prev;
public:
	cSetOfStacks(): prev(NULL), count(0)
	{}

	void push(int value)
	{
	
	}
	
	int pop()
	{
		return 0l;
	}
};

void pratic3()
{
	cSetOfStacks setStack;

	for (rsize_t i = 0; i < 10; i++)
	{
		setStack.push(i);
	}

	for (rsize_t i = 0; i < 10; i++)
	{
		printf("%d ", setStack.pop());
	}


}
class MyQueue
{
	cStack left;
	cStack right;
public:
	MyQueue()
	{
	}
	void push(int value)
	{
		left.push(value);
	}

	int pop()
	{
		int value = right.pop();
		if (value != -1)
		{
			return value;
		}

		do
		{
			value = left.pop();
			if (value == -1)
			{
				break;
			}
			right.push(value);
		}
		while (value != -1);
		value = right.pop();

		return value;
	}
};
void pratic4()
{
	MyQueue myQueue;

	for (rsize_t i = 1; i <= 10; i++)
	{
		myQueue.push(i);
	}
	std::cout << myQueue.pop();
	myQueue.push(11);

	for (rsize_t i = 1; i <= 10; i++)
	{
		std::cout << myQueue.pop(); 
	}
}


void sortStack(cStack& left, cStack& right)
{
	while (!left.isEmpty())
	{
		int value = left.pop();
		if (right.isEmpty())
		{
			right.push(value);
		}
		else
		{
			while (value < right.peek())
			{
				left.push(right.pop());
			}
			right.push(value);
		}
	}

	while (!right.isEmpty())
	{
		left.push(right.pop());
	}
}

void pratic5()
{
	cStack left;
	cStack right;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> distribution(0, 5);
	for (rsize_t i = 0; i < 5; i++)
	{
		int value = distribution(gen);
		std::cout << value << " ";
		left.push(value);
	}
	std::cout << std::endl;

	sortStack(left, right);
	
	for (rsize_t i = 0; i < 5; i++)
	{
		std::cout << left.pop() << " ";
	}
}

#include <list>

template <typename T>
struct stQueueNode
{
	T data;
	stQueueNode* next;
	stQueueNode(T data) : next(NULL)
	{
		this->data = data;
	}
};

template <typename T>
class CMyQueue
{
	stQueueNode<T>* front;
	stQueueNode<T>* rear;

public:
	CMyQueue() : front(NULL), rear(NULL)
	{}

	void push(T data)
	{
		if (front == NULL)
		{
			front = new stQueueNode<T>(data);
			rear = front;
		}
		else
		{
			rear->next = new stQueueNode<T>(data);
			rear = rear->next;
		}
	}

	T pop()
	{
		if (front == NULL)
		{
			std::cout << "empty" << std::endl;
			return 0;
		}

		T returnData = front->data;
		front = front->next;
		return returnData;
	}

	T peek()
	{
		return front->data;
	}

	bool IsEmpty()
	{
		return (front == NULL);
	}
};

class AnimalQueue
{
	CMyQueue<int> dogQueue;
	CMyQueue<int> catQueue;

public:
	void enQueue(bool check, int data)
	{
		if (check)
		{
			dogQueue.push(data);
		}
		else
		{
			catQueue.push(data);
		}
	}

	int deQueueAny()
	{
		if (dogQueue.IsEmpty() && catQueue.IsEmpty())
		{
			std::cout << "empty";
			return 0;
		}
		if (dogQueue.IsEmpty())
		{
			std::cout << "cat : ";
			return catQueue.pop();
		}
		if (catQueue.IsEmpty())
		{
			std::cout << "dog : ";
			return dogQueue.pop();
		}

		if (dogQueue.peek() < catQueue.peek())
		{
			std::cout << "dog : ";
			return dogQueue.pop();
		}
		else
		{
			std::cout << "cat : ";
			return catQueue.pop();
		}
	}

	int deQueueDog()
	{
		std::cout << "dog : ";
		return dogQueue.pop();
	}

	char deQueueCat()
	{
		std::cout << "cat : ";
		return catQueue.pop();
	}
};


void pratic6()
{
	AnimalQueue animalQueue;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<int> distribution(0, 1);
	
	for (rsize_t i = 0; i < 10; i++)
	{
		if (distribution(gen))
		{
			std::cout << "dog : " << i << ", ";
			animalQueue.enQueue(true, i);
		}
		else
		{
			std::cout << "cat : " << i << ", ";
			animalQueue.enQueue(false ,i);
		}
	}
	std::cout << std::endl;

	for (rsize_t i = 0; i < 10; i++)
	{
		std::cout << animalQueue.deQueueAny() << ", ";
	}
	std::cout << std::endl;
}