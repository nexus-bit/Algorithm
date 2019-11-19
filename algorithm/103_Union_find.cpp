#include<iostream>
using namespace std;

//� ����� �θ� ã�� �Լ� 
int getParent(int parent[], int node) {
	if (parent[node] == node)	//� ����� ���� �� �θ��� ���� ������
		return node;	//�״�� ��ȯ(����Լ��� ����)
	else //�θ�� �ڽ��� ���� �ٸ���
		return parent[node] = getParent(parent, parent[node]);//���� �θ� ã�� ���� ��ͷ� �Լ� ����
}

//�� �θ��� ��ġ�� �Լ� - �� �� ���� ������
void unionParent(int parent[], int x, int y) {	//��� x�� y�� ����
	x = getParent(parent, x);	//�θ� ã��
	y = getParent(parent, y);
	if (x < y) parent[y] = x;	//�� ����� �� ���� ���� �θ� ����(��ħ)
	else parent[x] = y;
}

//���� �׷����� �����ִ°� Ȯ��(���� �θ� �����°�)
int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);	//�θ��� ���� ã��
	y = getParent(parent, y);
	if (x == y) return 1;	//���� �θ� ������ True��ȯ
	else return 0;
}

int main() {
	int parent[9];	//���� �������� ���ҷ� �̷���� �ִ� ����
	for (int i = 1; i <= 8; i++)
		parent[i] = i;
	unionParent(parent, 1, 2);	//1~3�� ������ ����Ǿ� ����
	unionParent(parent, 2, 3);	//
	unionParent(parent, 5, 6);	//5~8�� ������ ����Ǿ� ����
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	cout << "��� 1�� 5�� ����Ǿ� �ִ°�?";
	if (findParent(parent, 1, 5) == 1)
		cout << " : ��" << endl;
	else
		cout << " : �ƴϿ�" << endl;

	cout << "��� 5�� 8�� ����Ǿ� �ִ°�?";
	if (findParent(parent, 5, 8) == 1)
		cout << " : ��" << endl;
	else
		cout << " : �ƴϿ�" << endl;

	unionParent(parent, 1, 7);
	cout << "1�� 7�� ��ģ ��, ��� 1�� 5�� ����Ǿ� �ִ°�?";
	if (findParent(parent, 1, 5) == 1)
		cout << " : ��" << endl;
	else
		cout << " : �ƴϿ�" << endl;
}