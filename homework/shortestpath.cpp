#include<iostream>
#include<vector>
#include<queue>
#include"edge.h"
#include"node.h"
#include"my_function.cpp"


using namespace std;

void relax(node * u, node * v, int w);
edge * foundEdge(node * n1, node * n2, vector<edge *> edgeList);
node * extract_min(vector<node *> Q);
void printPath(node * node1, node* node2);
static int time;


int main()
{
	vector<node *> nodeList;  //建立节点向量
	for (int i = 0; i < 9; i++)
	{
		node * z = new node();
		nodeList.push_back(z);  //动态向 节点向量 里增加 节点实例
	}

	//动态向 边缘向量edgeList里面 增加 edge 实例
	vector<edge *> edgeList;
	edge * edge0 = new edge(4, nodeList[0], nodeList[1]);
	edgeList.push_back(edge0);
	edge * edge1 = new edge(8, nodeList[1], nodeList[2]);
	edgeList.push_back(edge1);
	edge * edge2 = new edge(7, nodeList[2], nodeList[3]);
	edgeList.push_back(edge2);
	edge * edge3 = new edge(9, nodeList[3], nodeList[4]);
	edgeList.push_back(edge3);
	edge * edge4 = new edge(10, nodeList[5], nodeList[4]);
	edgeList.push_back(edge4);
	edge * edge5 = new edge(2, nodeList[6], nodeList[5]);
	edgeList.push_back(edge5);
	edge * edge6 = new edge(8, nodeList[0], nodeList[7]);
	edgeList.push_back(edge6);
	edge * edge7 = new edge(11, nodeList[1], nodeList[7]);
	edgeList.push_back(edge7);
	edge * edge8 = new edge(2, nodeList[8], nodeList[2]);
	edgeList.push_back(edge8);
	edge * edge9 = new edge(7, nodeList[7], nodeList[8]);
	edgeList.push_back(edge9);
	edge * edge10 = new edge(6, nodeList[8], nodeList[6]);
	edgeList.push_back(edge10);
	edge * edge11 = new edge(4, nodeList[2], nodeList[5]);
	edgeList.push_back(edge11);
	edge * edge12 = new edge(14, nodeList[3], nodeList[5]);
	edgeList.push_back(edge12);
	edge * edge13 = new edge(7, nodeList[4], nodeList[5]);
	edgeList.push_back(edge13);
	edge * edge14 = new edge(3, nodeList[3], nodeList[2]);
	edgeList.push_back(edge14);
	edge * edge15 = new edge(11, nodeList[8], nodeList[0]);
	edgeList.push_back(edge15);

	for (int i = 0; i < nodeList.size(); i++)
	{
		for (int j = 0; j < nodeList.size(); j++)
		{
			edge * x = foundEdge(nodeList[i], nodeList[j], edgeList);
			if (x != NULL)
			{
				nodeList[i]->adjNodes.push_back(nodeList[j]);  //把有连接的节点储存到 该节点旗下的 adjNodes 向量里
			}
		}
	}

	vector<node *> S;  //节点S 向量
	nodeList[0]->dis = 0;  //给第一个节点的 dis 赋值
	S.push_back(nodeList[0]);  //存进 S 向量
	vector<node *> Q;  // 节点Q 向量

	for (int i = 0; i < nodeList.size(); i++)
		Q.push_back(nodeList[i]);   // 相当于复制  Q=nodeList

	while (!Q.empty())  //只要Q里面有元素，就一直执行
	{
		auto u = extract_min(Q);
		for (vector<node *>::iterator it = Q.begin(); it != Q.end(); it++) {
			//如果遍历到 最小的dis ??
			if (*it == u) {
				Q.erase(it); //
				break;
			}
		}
		S.push_back(u);
		for (auto v :u->adjNodes)
		{
			auto e = foundEdge(u, v, edgeList);  // 到这一步，就找到了两个节点和一条路径
			relax(u, v, e->weight );			//储存上一节点
		}		
	}
    

	for (int i = 0; i < nodeList.size(); i++)
	{
		cout << "从起点到节点" << nodeList[i]->id << "的最短距离是" << nodeList[i]->dis << endl;
		cout << "最短路径为：" << endl;
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}
	getchar();
	return 0;
}

