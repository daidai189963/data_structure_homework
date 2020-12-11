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
	vector<node *> nodeList;  //�����ڵ�����
	for (int i = 0; i < 9; i++)
	{
		node * z = new node();
		nodeList.push_back(z);  //��̬�� �ڵ����� ������ �ڵ�ʵ��
	}

	//��̬�� ��Ե����edgeList���� ���� edge ʵ��
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
				nodeList[i]->adjNodes.push_back(nodeList[j]);  //�������ӵĽڵ㴢�浽 �ýڵ����µ� adjNodes ������
			}
		}
	}

	vector<node *> S;  //�ڵ�S ����
	nodeList[0]->dis = 0;  //����һ���ڵ�� dis ��ֵ
	S.push_back(nodeList[0]);  //��� S ����
	vector<node *> Q;  // �ڵ�Q ����

	for (int i = 0; i < nodeList.size(); i++)
		Q.push_back(nodeList[i]);   // �൱�ڸ���  Q=nodeList

	while (!Q.empty())  //ֻҪQ������Ԫ�أ���һֱִ��
	{
		auto u = extract_min(Q);
		for (vector<node *>::iterator it = Q.begin(); it != Q.end(); it++) {
			//��������� ��С��dis ??
			if (*it == u) {
				Q.erase(it); //
				break;
			}
		}
		S.push_back(u);
		for (auto v :u->adjNodes)
		{
			auto e = foundEdge(u, v, edgeList);  // ����һ�������ҵ��������ڵ��һ��·��
			relax(u, v, e->weight );			//������һ�ڵ�
		}		
	}
    

	for (int i = 0; i < nodeList.size(); i++)
	{
		cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
		cout << "���·��Ϊ��" << endl;
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}
	getchar();
	return 0;
}

