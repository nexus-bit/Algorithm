#include<iostream>
#include<vector> //������ ����
using namespace std;

int number = 7;	//�����ǰ���
int check[7];	//�湮ó��
vector<int> a[8];	//�� ����� ����(7��) �ε��� 1~7�� ó������

void DFS(int x) {	//Ư���� x��� ���� ������ ��
	if (check[x]) return;	//�� ��带 �湮�ߴٸ� �Լ� �ٷ� ����
	check[x] = true;	//ó�� �湮�ϴ� �Ŷ�� �湮ó��
	cout << x << " ";	//��� ���
	for (int i = 0; i < a[x].size(); i++) {	//������带 �ϳ��� �湮�� �ϸ鼭
		int y = a[x][i];	//������带 ������� ��������� DFS����
		DFS(y);	//�ڱ�� ������ ��带 �ݺ������� DFS���� - ���̿켱 Ž���� ��
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

	DFS(1);	//�������� 1�̾�
}