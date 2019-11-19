#include<iostream>
using namespace std;

//어떤 노드의 부모를 찾는 함수 
int getParent(int parent[], int node) {
	if (parent[node] == node)	//어떤 노드의 값이 그 부모의 값과 같으면
		return node;	//그대로 반환(재귀함수의 종료)
	else //부모와 자신의 값이 다르면
		return parent[node] = getParent(parent, parent[node]);//실제 부모를 찾기 위해 재귀로 함수 실행
}

//두 부모노드 합치는 함수 - 둘 중 작은 값으로
void unionParent(int parent[], int x, int y) {	//노드 x와 y를 받음
	x = getParent(parent, x);	//부모를 찾음
	y = getParent(parent, y);
	if (x < y) parent[y] = x;	//두 노드중 더 작은 노드로 부모를 설정(합침)
	else parent[x] = y;
}

//같은 그래프에 속해있는가 확인(같은 부모를 가지는가)
int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);	//부모값을 통해 찾음
	y = getParent(parent, y);
	if (x == y) return 1;	//같은 부모를 가지면 True반환
	else return 0;
}

int main() {
	int parent[9];	//전부 개별적인 원소로 이루어져 있다 가정
	for (int i = 1; i <= 8; i++)
		parent[i] = i;
	unionParent(parent, 1, 2);	//1~3은 합쳐저 연결되어 있음
	unionParent(parent, 2, 3);	//
	unionParent(parent, 5, 6);	//5~8은 합쳐져 연결되어 있음
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	cout << "노드 1과 5는 연결되어 있는가?";
	if (findParent(parent, 1, 5) == 1)
		cout << " : 네" << endl;
	else
		cout << " : 아니오" << endl;

	cout << "노드 5과 8는 연결되어 있는가?";
	if (findParent(parent, 5, 8) == 1)
		cout << " : 네" << endl;
	else
		cout << " : 아니오" << endl;

	unionParent(parent, 1, 7);
	cout << "1과 7을 합친 후, 노드 1과 5는 연결되어 있는가?";
	if (findParent(parent, 1, 5) == 1)
		cout << " : 네" << endl;
	else
		cout << " : 아니오" << endl;
}