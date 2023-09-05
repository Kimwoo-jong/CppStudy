#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

// find
// find_if
// count_if
// all_of
// any_of
// none_of
// for_each <<
// remove
// remove_if <<

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 100;
		v.push_back(n);
	}
#pragma region find
	 // Q) 특정 숫자가 있는지
	{
		int num = 50;

		bool found = false;
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;

			if (value == num)
			{
				//found = true;
				break;
			}
		}

		auto it = std::find(v.begin(), v.end(), num);
		if (it == v.end())
		{
			cout << "찾지 못함." << endl;
		}
		else
		{
			cout << "찾음." << endl;
		}
	}
#pragma endregion
#pragma region find_if
	 // Q2) 11로 나뉘어 떨어지는 숫자가 있는지?
	{
		int div = 11;

		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;

			if (value % div == 0)
			{
				break;
			}
		}

		struct CanDivideBy11
		{
			bool operator()(int n)
			{
				return n % 11 == 0;
			}
		};

		auto it = std::find_if(v.begin(), v.end(), CanDivideBy11());
		if (it == v.end())
		{
			cout << "찾지 못함." << endl;
		}
		else
		{
			int value = *it;
			cout << value << " 찾음" << endl;
		}
	}
#pragma endregion
#pragma region count_if, all_of, any_of, none_of
	 // Q) 홀수인 숫자 갯수는?
	{
		int count = 0;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 != 0)
			{
				count++;
			}
		}

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		int n = std::count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수입니까?
		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());

		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = std::any_of(v.begin(), v.end(), IsOdd());

		//모든 데이터가 홀수가 아닙니까?
		bool b3 = std::none_of(v.begin(), v.end(), IsOdd());
	}
#pragma endregion
#pragma region for_each
	 // Q) 벡터에 있는 모든 숫자들에 3을 곱해주세요.
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n *= 3;
			}
		};

		std::for_each(v.begin(), v.end(), MultiplyBy3());
	}
#pragma endregion
#pragma region remove_if ( 중요함 )
	// Q) 홀수인 데이터를 일괄 삭제
	vector<int> v = { 1, 4, 3, 5, 8, 2 };

	// 순환 삭제의 올바른 방법
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it % 2 != 0)
			it = v.erase(it);
		else
			it++;
	}

	struct IsOdd
	{
		bool operator()(int n)
		{
			return n % 2 != 0;
		}
	};

	// 1 4 3 5 8 2
	
	// 벡터를 복사하여 정리를 하는 것이 아닌 원본에서 정리를 진행하기 때문에
	// 삭제 및 정리가 완료된 후에 남은 원소는 내가 직접 처리 해줘야함.
	// 4 8 2 5 8 2
	std::remove_if(v.begin(), v.end(), IsOdd());

	// 이를 해결하기 위해서는 위의 작업에서 추가적으로 벡터의 끝까지 한 번더 지워주는 과정을 거쳐야 함.
	v.erase(std::remove_if(v.begin(), v.end(), IsOdd()), v.end());

	int a = 3;
#pragma endregion
}