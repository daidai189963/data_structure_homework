#include"my_function.h"

edge * foundEdge(node * n1, node * n2, vector<edge *> edgeList)
{
	edge * x = NULL;
	for (int i = 0; i < edgeList.size(); i++)
	{
		node * node1 = edgeList[i]->Node1;
		node * node2 = edgeList[i]->Node2;
		if (n1 == node1&&n2 == node2)
		{
			x = edgeList[i];
		}
	}
	return x;
}

void relax(node * u, node * v, int w)
{
	if ((v->dis)> (u->dis + w))
	{
		v->dis = u->dis + w;
		v->prevNode = u;
	}
}

node * extract_min(vector<node *> Q)  //把 Q里面的dis 最小值找到，返回 node 实例
{
	int tmp = 999999;
	node * x = NULL;
	for (int i = 0; i < Q.size(); i++)
	{
		if (Q[i]->dis < tmp)
		{
			tmp = Q[i]->dis;
			x = Q[i];
		}
	}
	
	return x;
}

void printPath(node * node1, node* node2)
{
	if (node1 == node2)
		cout << node1->id << "  ";
	else
	{
		if (node2->prevNode == NULL)
			cout << "no path from" << node1->id << "to" << node2->id << "exist" << endl;
		else
		{
			printPath(node1, node2->prevNode);
			cout << node2->id << "  ";
		}

	}
}