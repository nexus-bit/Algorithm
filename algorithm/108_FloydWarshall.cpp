#include<iostream>
#define inf 1000000 //inf : ��
#define node 5 //node : ������ ����
using namespace std;

//�ʱ� �迭 �ʱ�ȭ
int start[5][5] = {
	{0, 10, 5, inf, inf},
	{inf, 0, 2, 1, inf},
	{inf, 3, 0, 9, 2},
	{inf,inf, inf, 0, 4},
	{7, inf, inf, 6, 0}
};

void floyd() {
	//��� �迭 �ʱ�ȭ
	int end[node][node];
	for (int i = 0; i < node; i++)
		for (int j = 0; j < node; j++)
			end[i][j] = start[i][j];	//����� �ʱⰪ ���� ����

	//i->j�� ���� i->k->j�� ��츦 ��
	for (int k = 0; k < node; k++) //k = ���İ��� ���
		for (int i = 0; i < node; i++) //i = ��� ���
			for (int j = 0; j < node; j++) //j = ���� ���
				if (end[i][k] + end[k][j] < end[i][j])
					end[i][j] = end[i][k] + end[k][j];

	//��� �迭 ���
	for (int i = 0; i < node; i++) {
		for (int j = 0; j < node; j++) {
			cout << end[i][j] << "	";
		}
		puts("");
	}
}

int main() {
	floyd();
}