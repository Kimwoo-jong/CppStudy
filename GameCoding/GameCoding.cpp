#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
	// size(resize)
	// capacity(reserve)
	// 삽입/삭제
	// - 시작	O(N)
	// - 중간	O(N)
	// - 끝		O(1)
	// push_back, front, back
	// 임의 접근 v[i]
	// v.remove(10)?

	// 추가
	// 삭제
	// 순회
	// 검색

	//vector<int> v(5);
	//vector<int> v(5, -1);
	//vector<int> v{1, 2, 3, 4, 5};

	//v.clear();

	// size		- 줄어든다.
	// capacity - 줄어들지 않음.

	/*cout << v.size() << endl;
	cout << v.capacity() << endl;*/

	{
		// iterator ? 반복자 포인터?
		vector<int> v{1, 2, 3, 4, 5};

		vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			if (data == 3)
			{
				// 찾음
				break;
			}
		}

		if (it != v.end())
		{
			cout << "찾음" << endl;
			v.erase(it);
		}
		else
		{
			cout << "찾지 못함" << endl;
		}
	}
}