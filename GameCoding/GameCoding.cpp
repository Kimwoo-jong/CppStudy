#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// 함수 포인터의 단점
// - 시그니처가 안 맞으면 사용 X
// - 상태를 가질 수 없음

int main()
{
	// 멤버 함수 포인터 (정적/전역 함수랑 다르다)

	// 클라 -> 나 (10)번 유저 공격할래
	// 클라2 -> 나 (10, 20) 좌표로 이동할래
	// 함수 포인터는 바인딩이 되지 않는다. (데이터를 포함할 수 없음 : 매번 달라지기 때문)
}