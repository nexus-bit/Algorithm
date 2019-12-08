////RSA Term Project (Hand_made_Nexusbit) Overflow ver.
//#include<iostream>
//#include<ctime>
////#include <unistd.h>	//리눅스에서의 sleep(s)함수 - 1초 내에서는 동일한 rand()함수 결과 중복을 피하기 위해 썼어요
//#include<windows.h>	//윈도우에서의 sleep(ms)함수
//#include<cmath>
//using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////함수는 5개 만들었음 -> 2개가 작동을 안해서(오버플로우) 2개를 더 만듦
//int rand_sosu();
//int get_e(int o);
//int get_d(int e, int o);
//
//char encript(char c, int n, int e);
//char decript(char c, int n, int d);
//int numen(int M, int n, int e);
//int numde(int C, int n, int d);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int main() {
//	cout << "공개키와 비밀키를 만드는 중입니다...\n";
//	cout << "(랜덤 수 들 중, 조건에 맞는 수를 추출하는 데에 시간이 다소 걸릴 수 있습니다)\n";
//	cout << "===========================================================================" << endl;
//
//	//1. 공개키, 비밀키 만들기 - n, e, d로 구성
//	//1) n 구하기 : 랜덤 소수 p * q
//	int p, q;
//	p = rand_sosu();
//	cout << "랜덤 소수 p 지정	: " << p << endl;
//	q = rand_sosu();
//	cout << "랜덤 소수 q 지정	: " << q << endl;
//	int n = p * q;
//	cout << ">>p * q = n 계산	: " << n << endl;
//
//	//2) e 구하기
//	//	φ(n) : (p-1)*(q-1) : 1~n-1 중 n과 서로소의 갯수
//	int o = (p - 1) * (q - 1);
//	cout << "서로소 개수 φ(n) 계산	: " << o << endl;
//
//	//	1 < e < φ(n)에 만족하며, φ(n)과 서로소인 e를 지정한다.
//	//	즉 1 < e < (p-1)*(q-1)
//	int e = get_e(o);
//	cout << "φ(n)를 통해 e 지정	: " << e << "	[1 < e < φ(n) 을 만족하며, e는 φ(n)과 서로소]" << endl;
//
//	//3) d 구하기
//	//	(e * d)mod φ(n)=1 : e * d를 φ(n)으로 나눴을 때 나머지가 1인 랜덤d
//	int d = get_d(e, o);
//	cout << "규칙에 만족하는 d 지정	: " << d << "	[(e * d)modφ(n) = 1 을 만족]" << endl << endl;
//
//	//4) 공개키, 비밀키 완성
//	cout << "공개키는 (" << n << ", " << e << ")	입니다." << endl;	//암호화 가능
//	cout << "비밀키는 (" << n << ", " << d << ")	입니다." << endl;	//복호화 원래 본인말 알고 있어야 함
//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	//2. 암호화 하기
//	char data[20] = { "kss0097@hanmail.net" };	//암호화 되기 전 M
//	char encripted[20] = { NULL };	//암호화 이후 나타날 데이터 C
//	cout << "===========================================================================" << endl;
//	cout << "암호화 되기 전의 이메일은 [" << data << "]입니다." << endl;
//
//	//1) C = M^e mod n 을 통해 M을 C로 암호화
//	for (int i = 0; i < 20; i++)	//배열의 모든 데이터 암호화
//		encripted[i] = encript(data[i], n, e);
//
//	//2) 암호화된 데이터 확인해 보기
//	cout << "암호화된 이메일의 형태는 [";
//	for (int i = 0; i < 20; i++)
//		cout << encripted[i];
//	cout << "]입니다." << endl;
//
//	//3. 복호화 하기
//	char decripted[20] = { NULL };	//복호화 이후 나타날 원래 데이터 M
//
//	//1) M = C^d mod n을 통해 C를 M으로 복호화
//	for (int i = 0; i < 20; i++)	//배열의 모든 데이터 복호화
//		decripted[i] = decript(encripted[i], n, d);
//	
//	//2) 복호화된 원래 데이터 확인해 보기
//	cout << "복호화된 이메일의 형태는 [";
//	for (int i = 0; i < 20; i++)
//		cout << decripted[i];
//	cout << "]입니다." << endl;
//	//////////////////////////////////////////////////////////////////////////////////////////////////
//	//4. 에러 발생? _ 오버플로우
//	cout << "===========================================================================" << endl;
//	cout << endl << endl << "숫자가 너무 커서 자료형이 받아들이지 못함, 다음처럼 가정해보자." << endl;
//	n = 14;	//임의의 두 소수 p, q를 2, 7, p * q = n = 14라고 가정
//	o = 6;	//φ(n) = 6
//	e = 5;	//1~352사이. 352와서로소
//	d = 11;	//(5*d)를 6으로 나눴을떄 1이 남음
//	//또한 배열 대신 숫자를 이용해 보자
//	int number = 5;	//데이터
//	int ennum = 0;
//	int denum = 0;
//
//	//암호화와 복호화
//	cout << "암호화 되기 전의숫자는 [" << number << "]입니다." << endl;
//
//	//1) C = M^e mod n 을 통해 M을 C로 암호화
//	ennum = numen(number, n, e);
//
//	//2) 암호화된 데이터 확인해 보기
//	cout << "암호화된 숫자의 형태는 [";
//	cout << ennum;
//	cout << "]입니다." << endl;
//
//	//3) M = C^d mod n을 통해 C를 M으로 복호화
//	denum = numde(ennum, n, d);
//
//	//4) 복호화된 원래 데이터 확인해 보기
//	cout << "복호화된 이메일의 형태는 [";
//	cout << denum;
//	cout << "]입니다." << endl;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int rand_sosu() {	//랜덤 소수 생성 함수
//	Sleep(1000);
//	srand((unsigned int)time(NULL));
//	int x = (rand() % 48) + 2;	//이 프로그램은 2 ~ 49 사이의 값으로 가정
//	while (true) {	//소수로 리턴될때까지 무한반복
//		if (x == 2)
//			return x;	//일단 2는 소수 - 리턴
//		for (int i = 2; i < x; i++) {
//			if (x % i == 0)
//				break;	//소수가 아닐경우 숫자 다시 지정
//			else if ((i + 1) == x)
//				return x;	//소수일 경우 반환
//		}
//		x++;
//		//x의 값을 무한으로 1초마다 갱신되는 rand값에 다시 넣으면 오래 걸림
//		//초기값만 rand로 받고, x가 1씩 커지며 소수를 찾을때까지 무한반복
//	}
//}
//
//int get_e(int o) {	//공개키에 필요한 e를 정하는 과정
//	//e는 1 < e < φ(n)에 만족하며, φ(n)과 서로소여야 함
//	Sleep(1000);
//	srand((unsigned int)time(NULL));
//	int e = (rand() % (o - 2)) + 2;	//e : 2 ~φ(n)-1사이의 랜덤 수(1 < e < φ(n))
//	while (1) {
//		int gongyaksu = 0;
//		for (int i = 2; i <= e; i++)
//			if ((e % i == 0) && (o % i == 0))
//				gongyaksu++;	//공약수 갯수만큼 카운트
//		if (gongyaksu == 0)	//공약수가 1 한개이면 서로소 - 반환
//			return e;
//		//1 < e < φ(n)에서  랜덤으로 초기 e를 정한 후  2 ~ φ(n)-1를 돌아가며 서로소를 찾을때까지 무한루프
//		else if (e > 2)
//			e--;
//		else
//			e = o - 1;
//	}
//}
//
//int get_d(int e, int o) {	//비밀키에 필요한 d를 정하는 과정
//	srand((unsigned int)time(NULL));
//	int d = rand() % 10000;	//d는 쉽게 풀면 안되기 때문에 rand함수의 전체 랜덤을 썼음
//	while (true) {
//		if ((d * e) % o == 1)	//e * d를 φ(n)으로 나눴을 때 나머지가 1인 수 찾으면
//			return d;	//d값 으로 지정한다
//		else	//조건에 맞지 않으면 나머지가 1이라는 조건 맞을때까지 숫자 계속 지정
//			d = rand() % 10000;
//	}
//}
//
//char encript(char c, int n, int e) {	//암호화 처리 과정 M->C
//	//C = M ^ e mod n
//	int tmp = pow(c, e);
//	return tmp % n;
//}
//
//char decript(char c, int n, int d) {
//	//C = M ^ e mod n -> M = C^d mod n (페르마의 소정리)
//	int tmp = pow(c, d);
//	return tmp % n;
//}
//
//int numen(int M, int n, int e)
//{
//	int tmp = pow(M, e);
//	return tmp % n;
//}
//
//int numde(int C, int n, int d)
//{
//	int tmp = pow(C, d);
//	return tmp % n;
//}