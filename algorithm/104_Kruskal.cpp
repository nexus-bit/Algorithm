#include<iostream>
#include<vector>
#include<algorithm>	//sort를 사용할 수 있는 라이브러리(good!)
using namespace std;

int getparent(int parent[], int n) {	//노드의 부모 찾기 함수, 예시(1, 2, 3의 연결)
	if (parent[n] == n)	//제일 작은 1의 부모는 항상 1, 리턴 1
		//ex1 : 1은 union할 필요가 없으므로 1 리턴
		return n;
	else	//부모가 바뀐 노드. 부모가 노드랑 같아질때까지 재귀적으로 반복.
		//ex3 : 3과 2의 union으로 인해 부모는 작은 2로 변함 -> 재귀 호출 2
		//ex2 : 2와 1의 union으로 인해 부모는 작은 1로 변함 -> 재귀 호출 1
		return (parent[n] = getparent(parent, parent[n]));
}

void unionparent(int parent[], int x, int y) {	//두 개의 부모노드를 병합(union)하는 함수
	x = getparent(parent, x);	//x의 부모를 구하기(예시 - 3의 경우 1이 반환)
	y = getparent(parent, y);
	if (x > y)	//큰 노드의 부모를 작은 노드의 부모로 바꿈
		parent[x] = y;
	else	//3의 부모는 곧 1이 됨.
		parent[y] = x;
}

int findparent(int parent[], int x, int y) {	//x, y가 같은 그래프 내에 있는지(같은 부모를 가지는지) 여부 출력
	x = getparent(parent, x); //x의 부모를 구해 x에 저장
	y = getparent(parent, y);
	if (x == y) return 1;	//ex 3과 1을 비교해서 부모가 같으면(재귀 호출로 인해 같아짐) 같은 그래프 내에 있음(연결됨)
	else return 0;
}
//여기까지가 유니온 파인드(사이클이 있는지 검증)

//간선 클래스 선언
class Edge {
public:
	int node[2];	//간선엔 서로 연결된 2개의 노드가 저장됨
	int distance;	//간선의 길이(거리)
	Edge(int a, int b, int distance) {	//초기화해주는 생성자 함수
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge &edge) {	//정렬의 기준을 만듦, 거리가 작은게 먼저 출력이 되도록
		return this->distance < edge.distance;
	}
};
int main() {
	int n = 7;	//정점의 갯수
	int m = 11;	//간선의 갯수
	vector<Edge> v;	//간선 데이터가 담길 벡터
	v.push_back(Edge(1, 7, 12));	//1과 7 사이 간선비용은 12
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));	//총 11 간선

	//간선 비용 기준 오름차순 정렬
	sort(v.begin(), v.end());	//알고리즘 라이브러리 기능, 자동정렬

	//각 정점이 포함된 그래프가 어디인지 저장
	int parent[7];
	for (int i = 0; i < n; i++)
		parent[i] = i;	//모든 정점은 자기 자신을 가리키도록

	int sum = 0;	//거리합 0으로 초기화
	//사이클에 포함되지 않으면 그래프에 포함시켜준다.
	for (int i = 0; i < v.size(); i++) {
		if (!findparent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {	//간선에서의 첫번쨰, 두번째 노드가 사이클이 발생하지 않을 경우
			sum += v[i].distance;	//해당 거리만큼 결과값에 더해주고
			unionparent(parent, v[i].node[0] - 1, v[i].node[1] - 1);	//실제로 두 노드 연결(합쳐춤)
		}
	}
	cout << endl << sum;
}

//영문 주석
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