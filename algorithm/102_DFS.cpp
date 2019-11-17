#include<iostream>
#include<vector> //데이터 저장
using namespace std;

int number = 7;	//원소의갯수
int check[7];	//방문처리
vector<int> a[8];	//각 노드의 갯수(7개) 인덱스 1~7로 처리하자

void DFS(int x) {	//특정한 x라는 값이 들어왔을 때
	if (check[x]) return;	//그 노드를 방문했다면 함수 바로 끝냄
	check[x] = true;	//처음 방문하는 거라면 방문처리
	cout << x << " ";	//노드 출력
	for (int i = 0; i < a[x].size(); i++) {	//인접노드를 하나씩 방문을 하면서
		int y = a[x][i];	//인접노드를 대상으로 재귀적으로 DFS수행
		DFS(y);	//자기와 인접한 노드를 반복적으로 DFS수행 - 깊이우선 탐색이 됨
	}
}

int main() {	//데이터 넣어주기
	//1과 2를 연결
	a[1].push_back(2);	//하나의 간선마다 명령어 두개씩
	a[2].push_back(1);	//2또한 1과 연결됨

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

	DFS(1);	//시작점은 1이야
}