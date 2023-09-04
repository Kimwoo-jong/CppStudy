#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include "BinarySearchTree.h"

// 이진 탐색 (binary search) -> O(logN) 데이터 추가/삭제
// 이진 탐색 트리 -> 

//vector<int> numbers;
//
//void BinarySearch(int N)
//{
//	int left = 0;
//	int right = numbers.size() - 1;
//
//	while (left <= right)
//	{
//		cout << "탐색 범위 : " << left << " ~ " << right << endl;
//
//		int mid = (left + right) / 2;
//
//		if (N < numbers[mid])
//		{
//			cout << N << " < " << numbers[mid] << endl;
//			right = mid - 1;
//		}
//		else if (N > numbers[mid])
//		{
//			cout << N << " > " << numbers[mid] << endl;
//			left = mid + 1;
//		}
//		else
//		{
//			cout << "찾았음!" << endl;
//			break;
//		}
//	}
//}

int main()
{
	// O(N)
	// [1][8][15][23][32][44][56][63][81][91]

	// vector를 이용하여 binarysearch

	// O(logN)
	/*numbers = { 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(45);*/

	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(10);

	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);

	bst.Print();
}