#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{

	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		_hp = knight._hp;

		// 둘 다 동일한 원본 펫을 가리키고 있으므로,
		// 소멸의 순간 두 개가 삭제되는데 실질적인 Pet은 한 개이기 때문 (얕은 복사)
		//_pet = knight._pet;
		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 생성자
	Knight(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
	}

	// 이동 대입 연산자
	// pet의 소유권을 이전했다
	void operator=(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
	}
public:
	int _hp;
	Pet* _pet = nullptr;
};

void TestKnightCopy(Knight knight)
{
	knight._hp = 100;
}

// 원본을 넘겨줄테니 건드려도 됨.
void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 100;
}

// 원본은 넘겨주되 건드릴 수는 없다.
void TestKnight_ConstLValueRef(const Knight& knight)
{
	//knight._hp = 100;
}

// 오른값 참조 (&&)
// 원본을 넘겨준다 -> 더 이상 활용하지 않을테니 마음대로 해(일회성)
void TestKnight_RValueRef(Knight&& knight)
{
	//knight._hp = 100;
}

int main()
{
	// C++11 오른값 참조
	// 왼값(l-value) vs 오른값(r-value)

	// l-value : 단일식을 넘어서 계속 지속되는 개체
	// r-value : l-value가 아닌 나머지
	int a = 3;

	Knight k1;
	k1._pet = new Pet();

	Knight k2;
	//k2 = static_cast<Knight&&>(k1);
	k2 = std::move(k1); // << rValue_cast

	//TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight()); << 안됨 (const를 붙여야 함)
	//TestKnight_ConstLValueRef(Knight());
	//TestKnight_RValueRef(Knight());
	//TestKnight_RValueRef(static_cast<Knight&&>(k1));
}