#include<iostream>
#include<queue>	//ť ���
#include<vector> //������ ����
using namespace std;

int number = 7;	//�����ǰ���
int check[7];	//�湮ó��
vector<int> a[8];	//�� ����� ����(7��) �ε��� 1~7�� ó������

void BFS(int start) {
	queue<int> q;	//ť �����
	q.push(start);	//���۳�带 ť�� �ֱ�
	check[start] = true;	//�湮ó��
	while (!q.empty()) {	//ť�� �� ������
		int x = q.front();q.pop();	//ť���� �ϳ��� ���� ���� x�� ����
		cout << x;
		for (int i = 0; i < a[x].size(); i++) {	//ť���� ���� ���� ������ ��带 �ϳ��� �湮
			 int y = a[x][i];
			if (!check[y]) {	//�湮�� �� ���¶�� ����(�湮X)
				q.push(y);	//�湮���� �ʾ��� ��� ť�� �����
				check[y] = true;	//�湮ó��
			}
		}
	}
}

int main() {	//������ �־��ֱ�
	//1�� 2�� ����
	a[1].push_back(2);	//�ϳ��� �������� ��ɾ� �ΰ���
	a[2].push_back(1);	//2���� 1�� �����

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	BFS(1);	//�������� 1�̾�
}