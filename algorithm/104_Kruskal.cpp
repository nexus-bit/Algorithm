#include<iostream>
#include<vector>
#include<algorithm>	//sort�� ����� �� �ִ� ���̺귯��(good!)
using namespace std;

int getparent(int parent[], int n) {	//����� �θ� ã�� �Լ�, ����(1, 2, 3�� ����)
	if (parent[n] == n)	//���� ���� 1�� �θ�� �׻� 1, ���� 1
		//ex1 : 1�� union�� �ʿ䰡 �����Ƿ� 1 ����
		return n;
	else	//�θ� �ٲ� ���. �θ� ���� ������������ ��������� �ݺ�.
		//ex3 : 3�� 2�� union���� ���� �θ�� ���� 2�� ���� -> ��� ȣ�� 2
		//ex2 : 2�� 1�� union���� ���� �θ�� ���� 1�� ���� -> ��� ȣ�� 1
		return (parent[n] = getparent(parent, parent[n]));
}

void unionparent(int parent[], int x, int y) {	//�� ���� �θ��带 ����(union)�ϴ� �Լ�
	x = getparent(parent, x);	//x�� �θ� ���ϱ�(���� - 3�� ��� 1�� ��ȯ)
	y = getparent(parent, y);
	if (x > y)	//ū ����� �θ� ���� ����� �θ�� �ٲ�
		parent[x] = y;
	else	//3�� �θ�� �� 1�� ��.
		parent[y] = x;
}

int findparent(int parent[], int x, int y) {	//x, y�� ���� �׷��� ���� �ִ���(���� �θ� ��������) ���� ���
	x = getparent(parent, x); //x�� �θ� ���� x�� ����
	y = getparent(parent, y);
	if (x == y) return 1;	//ex 3�� 1�� ���ؼ� �θ� ������(��� ȣ��� ���� ������) ���� �׷��� ���� ����(�����)
	else return 0;
}
//��������� ���Ͽ� ���ε�(����Ŭ�� �ִ��� ����)

//���� Ŭ���� ����
class Edge {
public:
	int node[2];	//������ ���� ����� 2���� ��尡 �����
	int distance;	//������ ����(�Ÿ�)
	Edge(int a, int b, int distance) {	//�ʱ�ȭ���ִ� ������ �Լ�
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge &edge) {	//������ ������ ����, �Ÿ��� ������ ���� ����� �ǵ���
		return this->distance < edge.distance;
	}
};
int main() {
	int n = 7;	//������ ����
	int m = 11;	//������ ����
	vector<Edge> v;	//���� �����Ͱ� ��� ����
	v.push_back(Edge(1, 7, 12));	//1�� 7 ���� ��������� 12
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));	//�� 11 ����

	//���� ��� ���� �������� ����
	sort(v.begin(), v.end());	//�˰��� ���̺귯�� ���, �ڵ�����

	//�� ������ ���Ե� �׷����� ������� ����
	int parent[7];
	for (int i = 0; i < n; i++)
		parent[i] = i;	//��� ������ �ڱ� �ڽ��� ����Ű����

	int sum = 0;	//�Ÿ��� 0���� �ʱ�ȭ
	//����Ŭ�� ���Ե��� ������ �׷����� ���Խ����ش�.
	for (int i = 0; i < v.size(); i++) {
		if (!findparent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {	//���������� ù����, �ι�° ��尡 ����Ŭ�� �߻����� ���� ���
			sum += v[i].distance;	//�ش� �Ÿ���ŭ ������� �����ְ�
			unionparent(parent, v[i].node[0] - 1, v[i].node[1] - 1);	//������ �� ��� ����(������)
		}
	}
	cout << endl << sum;
}

//���� �ּ�
//#include<iostream>
//#include<vector>
//#include<algorithm>	//make it sort, it a library.
//using namespace std;
//
//int getparent(int parent[], int n) {	//find node's parents'
//	if (parent[n] == n)	//1-1 : return 1 directly
//		return n;
//	else	//parent changed node. while node=parent, recursionally continue. ex3-1 : node and parent is not same so go 3 to 2. 2-1 : 2 to 1. 1-1 : node and parent is same, return 1
//		return (parent[n] = getparent(parent, parent[n]));
//}
//
//void unionparent(int parent[], int x, int y) {	//merge(union) connected two node
//	x = getparent(parent, x);	//take node(x)'s parent
//	y = getparent(parent, y);
//	if (x > y)	//union bigger node's parent to connected smaller node's parent
//		parent[x] = y;
//	else	//if 3 is connected 2, (and 2if  is connected 1,) 3's parent is 1
//		parent[y] = x;
//}
//
//int findparent(int parent[], int x, int y) {	//It returns [Are they(x, y) connected together?]
//	x = getparent(parent, x); //take x's node and store it to x
//	y = getparent(parent, y);
//	if (x == y) return 1;
//	else return 0;
//}
//
//class Edge {
//public:
//	int node[2];
//	int distance;
//	Edge(int a, int b, int distance) {	//constrctor, reset
//		this->node[0] = a;
//		this->node[1] = b;
//		this->distance = distance;
//	}
//	bool operator < (Edge &edge) {	//set sort model, and sorts from small distance
//		return this->distance < edge.distance;
//	}
//};
//int main() {
//	int n = 7;	//node
//	int m = 11;	//load
//	vector<Edge> v;	//vector var contains load data
//	v.push_back(Edge(1, 7, 12));	//1and 7's distannce is 12
//	v.push_back(Edge(1, 4, 28));
//	v.push_back(Edge(1, 2, 67));
//	v.push_back(Edge(1, 5, 17));
//	v.push_back(Edge(2, 4, 24));
//	v.push_back(Edge(2, 5, 62));
//	v.push_back(Edge(3, 5, 20));
//	v.push_back(Edge(3, 6, 37));
//	v.push_back(Edge(4, 7, 13));
//	v.push_back(Edge(5, 6, 45));
//	v.push_back(Edge(5, 7, 73));	//all 11 loads.
//
//	//short distance based bot-top sort
//	sort(v.begin(), v.end());
//
//	//save location of the graph (which include each nodes)
//	int parent[7];
//	for (int i = 0; i < n; i++)
//		parent[i] = i;
//
//	int sum = 0;
//	//if it doesn't make a cycle, then include road to the graph
//	for (int i = 0; i < v.size(); i++) {
//		if (!findparent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
//			sum += v[i].distance;
//			unionparent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
//		}
//	}
//	cout << endl << sum;
//}