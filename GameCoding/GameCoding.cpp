#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>

class Player
{
public:
	Player() : _id(0) {}
	Player(int id) : _id(id) {}

public:
	int _id = 0;
};

// 몰라도 사용이 가능하긴 함
//template<typename T, typename U>
//struct Pair
//{
//	T first;
//	U second;
//};
//
//template<typename T, typename U>
//auto MakePair(T first, U second)
//{
//	return std::pair<T, U>(first, second);
//}

int main()
{
	vector<Player*> v;

	v.push_back(new Player(100));
	v.push_back(new Player(300));
	v.push_back(new Player(200));
	v.push_back(new Player(500));
	v.push_back(new Player(400));

	// (key, value)
	// C++ vector = C# List
	// C++ hash_map = C# Dictionary
	map<int, Player*> m;
	// 추가
	// 찾기
	// 삭제
	// 순회

	for (Player* player : v)
	{
		/*int key = player->_id;
		Player* data = player;

		MakePair(key, data);*/

		m.insert(make_pair(player->_id, player));
	}

	//
	auto it = m.find(300);

	if (it != m.end())
	{
		int key = (*it).first;
		Player* value = it->second;
	}
	else
	{
		cout << "없음" << endl;
	}

	m.erase(200);

	// 순회
	for (auto it = m.begin(); it != m.end(); it++)
	{
		int key = it->first;
		Player* p = it->second;
	}

	// 데이터가 있냐 없냐
	// 사이즈가 0인지 보는 함수
	m.empty();

	// 갖고 오되, 없으면 기본값으로 추가.
	Player* p = m[1000];
}