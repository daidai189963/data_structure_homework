#pragma once
#include<vector>
using namespace std;

class edge;

class node
{
public:
	int id;
	int dis;
	node * prevNode;
	vector<node *> adjNodes;

	static int countId;

	node()
	{
		id = countId++;
		dis = 999999;
		prevNode = NULL;

	}


};



