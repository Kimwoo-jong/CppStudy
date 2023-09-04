#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include "List.h"

int main()
{
	// size (resize)
	// capacity (reserve)
	// 삽입/삭제
	// - 시작		O(1)
	// - 중간		O(1)
	// - 끝			O(1)
	// front		O(1)
	// back			O(1)
	// push_front	O(1)
	// push_back	O(1)
	// 임의 접근 li[2]  X

	List<int> li;

	li.AddAtTail(10);
	li.AddAtTail(20);
	li.AddAtTail(30);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		int value = *it;

		if (value == 3)
			break;
	}
}