#include<iostream>
#define inf 1000000 //inf : ∞
#define node 5 //node : 데이터 갯수
using namespace std;

//초기 배열 초기화
int start[5][5] = {
	{0, 10, 5, inf, inf},
	{inf, 0, 2, 1, inf},
	{inf, 3, 0, 9, 2},
	{inf,inf, inf, 0, 4},
	{7, inf, inf, 6, 0}
};

void floyd() {
	//결과 배열 초기화
	int end[node][node];
	for (int i = 0; i < node; i++)
		for (int j = 0; j < node; j++)
			end[i][j] = start[i][j];	//결과는 초기값 부터 시작

	//i->j의 경우와 i->k->j의 경우를 비교
	for (int k = 0; k < node; k++) //k = 거쳐가는 노드
		for (int i = 0; i < node; i++) //i = 출발 노드
			for (int j = 0; j < node; j++) //j = 도착 노드
				if (end[i][k] + end[k][j] < end[i][j])
					end[i][j] = end[i][k] + end[k][j];

	//결과 배열 출력
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