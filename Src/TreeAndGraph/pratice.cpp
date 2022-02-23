#include "pratice.h"
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <stdlib.h>
#include <map>
class CGraph
{
	size_t nNodeSize;
	std::vector<std::vector<size_t>>* vecAdjacency;
	size_t nNodeCount;

public:
	CGraph(size_t nNodeSize) : nNodeSize(nNodeSize), nNodeCount(0)
	{
		vecAdjacency = new std::vector<std::vector<size_t>>(nNodeSize);
	}
	void addNode(size_t nRoot, size_t nDestination)
	{
		if (nRoot >= nNodeSize)
		{
			std::cout << "Not Found Root" << std::endl;
		}
		else
		{
			vecAdjacency->at(nRoot).push_back(nDestination);
		}
	}
	void IsRoute(size_t nRoot, size_t nDestination)
	{
		bool bResult = false;

		std::queue<size_t> queue;
		queue.push(nRoot);
		while (!queue.empty())
		{
			size_t nNode = queue.front();
			if (nNode == nDestination)
			{
				bResult = true;
				break;
			}
			queue.pop();
			
			for (std::vector<size_t>::const_iterator iter = vecAdjacency->at(nNode).begin(); iter != vecAdjacency->at(nNode).end(); iter++)
			{
				queue.push(*iter);
			}
		}

		if (bResult)
		{
			std::cout << "Found" << std::endl \
				<< "Root : " << nRoot << std::endl \
				<< "Destination : " << nDestination << std::endl;
		}
		else
		{
			std::cout << "Node Found" << std::endl \
				<< "Root : " << nRoot << std::endl \
				<< "Destination : " << nDestination << std::endl;
		}
	}
};

void pratic1()
{
	CGraph cGraph(6);
	cGraph.addNode(5, 2);
	cGraph.addNode(5, 0);
	cGraph.addNode(4, 0);
	cGraph.addNode(4, 1);
	cGraph.addNode(2, 3);
	cGraph.addNode(3, 1);
	cGraph.addNode(6, 1);

/*
	Test graph :
	0 <---4---->1
	^ 			^
	|			|
	|			|
	5---->2---->3
*/
	cGraph.IsRoute(5, 4);
	cGraph.IsRoute(2, 1);
}

struct Node
{
	uint32_t value;
	Node* left;
	Node* right;
	Node* parent;
	bool visited;
	uint32_t level;
	Node(uint32_t value)
		: value(value)
		, left(NULL)
		, right(NULL)
		, parent(NULL)
		, visited(false)
		, level(0)
	{
	}
	Node(uint32_t value, uint32_t level)
		: value(value)
		, left(NULL)
		, right(NULL)
		, parent(NULL)
		, visited(false)
		, level(level)
	{
	}
};


Node* insertNode(std::vector<uint32_t>& vecList, int low, int hight, uint32_t level = 0, Node* parent = NULL)
{
	if (low > hight)
	{
		return NULL;
	}
	int mid = (low + hight) / 2;
	Node* node = new Node(vecList.at(mid), level);
	if (parent != NULL)
	{
		node->parent = parent;
	}
	level++;
	node->left = insertNode(vecList, low, mid - 1, level, node);
	node->right = insertNode(vecList, mid + 1, hight, level, node);

	return node;
}

Node* createMinimalTree(std::vector<uint32_t>& vecList)
{
	if (vecList.size() == 0)
	{
		return NULL;
	}

	return insertNode(vecList, 0, vecList.size() - 1);
}

void inOrderTraversal(Node* node)
{
	if (node != NULL)
	{
		inOrderTraversal(node->left);
		printf("%d", node->value);
		inOrderTraversal(node->right);
	}
}

void pratic2()
{
	std::vector<uint32_t> vecList;
	for (uint32_t i = 1; i <= 5; i++)
	{
		vecList.push_back(i);
	}

	Node* root = createMinimalTree(vecList);
	inOrderTraversal(root);
}

void dfs(Node* node, uint32_t count, std::vector<std::list<uint32_t>>& vecList)
{
	if (node != NULL)
	{
		count++;
		if (vecList.size() < count)
		{
			std::list<uint32_t> listLinkedList;
			vecList.push_back(listLinkedList);
		}
		node->visited = true;
		vecList[count - 1].push_back(node->value);
		if (node->left != NULL && !node->left->visited)
		{
			dfs(node->left, count, vecList);
		}
		if (node->right != NULL && !node->right->visited)
		{
			dfs(node->right, count, vecList);
		}
		count--;
	}
}

void pratic3()
{
	std::vector<uint32_t> vecList;
	for (uint32_t i = 1; i <= 8; i++)
	{
		vecList.push_back(i);
	}

	Node* root = createMinimalTree(vecList);
	std::vector<std::list<uint32_t>> vecLinkedList;
	dfs(root, 0, vecLinkedList);

	uint32_t i = 0;
	for (std::list<uint32_t> listLinkedList : vecLinkedList)
	{
		std::cout << i << " : ";
		for (uint32_t value : listLinkedList)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
		i++;
	}
}


uint32_t dfs(Node* node, uint32_t nDepth, uint32_t nLevel)
{
	if (node != NULL)
	{
		nLevel++;
		node->visited = true;
		if (node->left != NULL && !node->left->visited)
		{
		 	nDepth = dfs(node->left, nDepth, nLevel);
		}
		if (node->right != NULL && !node->right->visited)
		{
			nDepth = dfs(node->right, nDepth, nLevel);
		}
	}
	if (nDepth < nLevel)
	{
		nDepth = nLevel;
	}
	return nDepth;
}

bool checkBalancedBinaryTree(Node* node)
{
	uint32_t nLeft = 0, nRight = 0;
	if (node != NULL)
	{
		node->visited = true;
		if (node->left != NULL && !node->left->visited)
		{
			nLeft = dfs(node->left, nLeft, 0);
		}
		if (node->right != NULL && !node->right->visited)
		{
			nRight = dfs(node->right, nRight, 0);
		}
	}
	return nLeft - 1 == nRight || nLeft == nRight || nLeft == nRight - 1;
}


void pratic4()
{
	std::vector<uint32_t> vecList;
	for (uint32_t i = 1; i <= 8; i++)
	{
		vecList.push_back(i);
	}

	Node* root = createMinimalTree(vecList);
	Node* temp = root;
	while (root->right != NULL)
	{
		root = root->right;
	}
	root->right = new Node(22);
	root->right->right = new Node(11);
	if (checkBalancedBinaryTree(temp))
	{
		std::cout << "It is Balanced Binary Tree" << std::endl;
	}
	else
	{
		std::cout << "It isn't Balanced Binary Tree" << std::endl;
	}
}

void inOrderTraversal(Node* node, uint32_t& value, bool& checker)
{
	if (checker == true && node != NULL)
	{
		inOrderTraversal(node->left, value, checker);
		if (value <= node->value)
		{
			value = node->value;
		}
		else
		{
			checker = false;
		}
		inOrderTraversal(node->right, value, checker);
	}
}

void pratic5()
{
	std::vector<uint32_t> vecList;
	for (uint32_t i = 1; i <= 8; i++)
	{
		vecList.push_back(i);
	}

	Node* root = createMinimalTree(vecList);
	bool checker = true;
	Node* temp = root;
	while (root->left != NULL)
	{
		root = root->left;
	}
	root->left = new Node(0);
	uint32_t value = 0;
	inOrderTraversal(temp, value, checker);
	if (checker)
	{
		std::cout << "It is Balanced Binary Tree" << std::endl;
	}
	else
	{
		std::cout << "It isn't Balanced Binary Tree" << std::endl;
	}
}

void findNextNode(Node* node)
{
	if (node != NULL)
	{
		if (node->right != NULL)
		{
			node = node->right;
			while (node->left != NULL)
			{
				node = node->left;
			}
			std::cout << node->value << std::endl;
		}
		else
		{
			while(true)
			{ 
				if (node->parent == NULL)
				{
					std::cout << "Next is NULL" << std::endl;
					break;
				}
				else if (node == node->parent->right)
				{
					node = node->parent;
				}
				else
				{
					std::cout << node->parent->value << std::endl;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "node is NULL" << std::endl;
	}
}

void pratic6()
{
	std::vector<uint32_t> vecList;
	for (uint32_t i = 1; i <= 15; i++)
	{
		vecList.push_back(i);
	}

	Node* root = createMinimalTree(vecList);

	findNextNode(root->left->right);
	findNextNode(root->left->left);
	findNextNode(root->left->right->right);
	findNextNode(root);
	findNextNode(root->right->right);
	findNextNode(root->right->left);
	findNextNode(root->right->right->right);
}

class CProject
{
public:
	int inbound;
	char name;
	std::vector<CProject*> child;
	CProject(char name) :inbound(0), name(name)
	{}
	void add(CProject* node)
	{
		child.push_back(node);
		node->inbound++;
	}
};

void pratic7()
{
	std::list<CProject*> listProject;
	CProject a('a'), b('b'), c('c'), d('d'), e('e'), f('f');
	listProject.push_back(&a);
	listProject.push_back(&b);
	listProject.push_back(&c);
	listProject.push_back(&d);
	listProject.push_back(&e);
	listProject.push_back(&f);
	a.add(&d);
	f.add(&b);
	b.add(&d);
	f.add(&a);
	d.add(&c);

	std::queue<CProject*> queueOrder;
	while (false == listProject.empty())
	{
		std::queue<CProject*> queueProcessNext;
		for (auto iter : listProject)
		{
			if (iter->inbound == 0)
			{
				queueProcessNext.push(iter);
			}
		}
		while (false == queueProcessNext.empty())
		{
			CProject* temp = queueProcessNext.front();
			queueProcessNext.pop();
			for (auto iter : temp->child)
			{
				iter->inbound--;
			}
			temp->child.clear();
			listProject.remove(temp);
			queueOrder.push(temp);
		}
	}
	while (false == queueOrder.empty())
	{
		CProject* temp = queueOrder.front();
		queueOrder.pop();
		printf("%c", temp->name);
	}
}

struct AdvancedNode : public std::enable_shared_from_this<AdvancedNode>
{
	std::weak_ptr<AdvancedNode> parent;
	std::unique_ptr<AdvancedNode> left = nullptr;
	std::unique_ptr<AdvancedNode> right = nullptr;
	int value = 0;
	bool marker = false;

	AdvancedNode() = delete;
	explicit AdvancedNode(int value) : value(value)
	{
	}
	~AdvancedNode() = default;
	void addLeftNode(std::unique_ptr<AdvancedNode> Node)
	{
		this->left = std::move(Node);
		this->left->parent = this->weak_from_this();
	}
	void addRightNode(std::unique_ptr<AdvancedNode> Node)
	{
		this->right = std::move(Node);
		this->right->parent = this->weak_from_this();
	}
};

using namespace std::string_literals;
void pratic8()
{
	std::unique_ptr<AdvancedNode> root = std::make_unique<AdvancedNode>(5);

	root->addLeftNode(std::make_unique<AdvancedNode>(1));
	root->addRightNode(std::make_unique<AdvancedNode>(6));
	root->left->addLeftNode(std::make_unique<AdvancedNode>(2));
	root->left->addRightNode(std::make_unique<AdvancedNode>(3));

	int firstNodeValue{ 0 }, secondNodeValue{ 0 };
	
	std::cout << R"(Input FirstNodeValue : )"s.data();
	std::cin >> firstNodeValue;
	std::cout << R"(Input SecondNodeValue : )"s.data();
	std::cin >> secondNodeValue;

	// skip	
}
