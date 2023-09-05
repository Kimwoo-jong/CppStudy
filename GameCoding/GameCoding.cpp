#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>

// 살을 내주고 뼈를 취한다!
// 메모리를 팔아서 (CPU)성능을 얻겠다.

// 아파트 우편함
// [201][202][203][204][205]
// [101][102][103][104][105]
// O(1)

// 1 ~ 999
// [1][2][3][4] ... [999]

// 키를 알면 빠르게 찾을 수 있다. O(1)

// hash 기법
// 보안
// 예전에는 id :  / pw : 의 공간을 따로 만들어 저장했음 -> 보안 취약
// pw -> hash(!@#$) = asjkdwqjldknqwklcnkln@skdnwkdn2 > hash 기법을 사용하여 이전보다 취약점이 사라짐

int main()
{
	// hash_map
	 
	// O(1)
	unordered_map<int, int> um;
	// 추가 
	// 삭제 
	// 찾기 
	// 순회 

	um.insert(make_pair(10, 100));

	um[20] = 200;

	auto findIt = um.find(10);
	if (findIt != um.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "없음" << endl;
	}

	um.erase(10);

	for (auto it = um.begin(); it != um.end(); it++)
	{
		int key = it->first;
		int value = it->second;
	}
}