#include<iostream>
#include<queue>	//큐 사용
#include<vector> //데이터 저장
using namespace std;

int number = 7;	//원소의갯수
int check[7];	//방문처리
vector<int> a[8];	//각 노드의 갯수(7개) 인덱스 1~7로 처리하자

void BFS(int start) {
	queue<int> q;	//큐 만들기
	q.push(start);	//시작노드를 큐에 넣기
	check[start] = true;	//방문처리
	while (!q.empty()) {	//큐가 빌 때까지
		int x = q.front();q.pop();	//큐에서 하나를 꺼내 변수 x에 저장
		cout << x;
		for (int i = 0; i < a[x].size(); i++) {	//큐에서 꺼낸 노드와 인접한 노드를 하나씩 방문
			 int y = a[x][i];
			if (!check[y]) {	//방문을 한 상태라면 무시(방문X)
				q.push(y);	//방문하지 않았을 경우 큐에 담아줌
				check[y] = true;	//방문처리
			}
		}
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

	BFS(1);	//시작점은 1이야
}