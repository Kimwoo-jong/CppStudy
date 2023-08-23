#include <iostream>
using namespace std;

// 캐스팅 4총사
// static_cast
// dynamic_cast
// const_cast
// reinterpret_cast

class Player
{
public:
	Player();
	virtual ~Player();
};

class Knight : public Player
{
public:
	Knight();
	virtual ~Knight();
};

class Archer : public Player
{};

class Dog
{
};

int main()
{
	// static_cast : 타입 원칙으로 볼 때 합리적인 캐스팅만 허용
	// 1) int <-> float

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;
	
	Archer* k = new Archer();
	Player* p = k;

	// dynamic_cast : 상속 관계에서의 안전 변환
	// 다형성을 활용하는 방식 (virtual)
	// RTTI (Runtime Type Information)
	Knight* k2 = dynamic_cast<Knight*>(p);
	if (k2 != nullptr)
	{
		// 기사였구만
	}

	// const_cast
	const char* name = "DevWooj";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	// 위험하고, 강력한 형태
	// 포인터 -> 전혀 관계 없는 다른 포인터로 변환

	__int64 address = reinterpret_cast<__int64>(k);
}