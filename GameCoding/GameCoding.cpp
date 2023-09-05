#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

enum ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type) { }

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	// lambda
	vector<Item> v;

	v.push_back(Item(1, Rarity::Common, ItemType::Armor));
	v.push_back(Item(2, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(3, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));
	v.push_back(Item(5, Rarity::Common, ItemType::Consumable));

	{
		/*struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};
		std::find_if(v.begin(), v.end(), IsUniqueItem());*/
		
		int wantedId = 2;

		// 람다식 이용
		// [](){} << 기본적인 틀
		 
		// 기본 캡처 모드
		// = 복사 : 초기값이 복사되어 들어가는 느낌
		// & 참조 : 주소값을 기억하고 있다가 주소값을 이용하여 값을 추출

		// 단일 변수마다 캡처 모드
		[&wantedId](Item& item)
		{
			return item._itemId == wantedId;
		};

		/*std::find_if(v.begin(), v.end(),
			[&wantedId](Item& item)
			{
				return item._itemId == wantedId;
			});*/

		//[/*캡처 모드*/](/*인자값*/)
		{
			/*내용물*/
		}
	}
}