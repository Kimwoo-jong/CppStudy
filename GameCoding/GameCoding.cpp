#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

// Bubble Sort
// 1 5 3 4 2
// 1 3 4 2 5
// 1 3 2 4 5
// 1 2 3 4 5

void BubbleSort(vector<int>& v)
{
	const int size = v.size();

	// O(N^2)
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

// Selection Sort
// 1 5 3 4 2
// 1 2 3 4 5

void SelectionSort(vector<int>& v)
{
	const int size = v.size();

	// O(N^2)
	for (int i = 0; i < size - 1; i++)
	{
		int bestIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (v[j] < v[bestIndex])
				bestIndex = j;
		}

		if(i != bestIndex)
			swap(v[i], v[bestIndex]);
	}
}

// Heap Sort
// 1 5 3 4 2
// 1 2 3 4 5

// O(NLogN) << 대부분의 좋은 정렬 방식
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(NLogN)
	for (int num : v)
		pq.push(num);

	v.clear();

	// O(NLogN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());		// O(1)
		pq.pop();					// O(LogN)
	}
}

// 병합 정렬
// 분할 정복 ( Divide and Conquer )
// - 분할(divide)		문제를 더 단순히 분할
// - 정복(Conquer)		분할된 문제를 해결
// - 결합(Combine)		결과를 취합하여 정리

// [3][K}[7][2][J][4][8][9]			<< 8개 * 1
// [3][K}[7][2]	[J][4][8][9]		<< 4개 * 2
// [3][K}	[7][2]	[J][4]	[8][9]	<< 2개 * 4
// [3] [K} [7] [2] [J] [4] [8] [9]	<< 8개 * 1
// [3][K] [2][7] [4][J] [8][9]		<< 2개 * 4
// [2][3][7][K] [4][8][9][J]		<< 4개 * 2
// [2][3][4][7][8][9][J][K]			<< 8개 * 1

// O(N)
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

// O(LogN)
// 두 가지를 다 완료하여 최종 MergeSort의 시간복잡도는 O(NLogN)
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v{1, 5, 3, 4, 2};

	//std::sort(v.begin(), v.end());
	//BubbleSort(v);
	//SelectionSort(v);
	//HeapSort(v);
	MergeSort(v, 0, v.size()-1);
}