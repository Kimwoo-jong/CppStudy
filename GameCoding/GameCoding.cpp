#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Knight
{
public:
	~Knight() { }
	void Attack()
	{
		// shared_ptr
		//if (_target)
		//	_target->_hp -= _damage;

		// weak_ptr
		if (_target.expired() == false)
		{
			// refCount를 이용하여 사용할 수 있는지 여부를 판단함.
			// spr의 값이 nullPtr일 경우 사용하면 안되는 값.
			// spr의 값이 nullPtr이 아닐 경우 사용이 가능
			shared_ptr<Knight> spr = _target.lock();
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	//shared_ptr<Knight> _target = nullptr;
	weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:
	int _refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr() { }
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (ptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& other) : _ptr(other._ptr), _block(other._block)
	{
		if (_ptr)
		{
			_block->_refCount++;
		}
	}

	~SharedPtr()
	{
		if (_ptr)
		{
			_block->_refCount--;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}

	void operator=(const SharedPtr& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr)
			_block->_refCount++;
	}

public:
	T* _ptr;
	RefCountBlock* _block;

};

class UniquePtr
{
private:
	void operator=(const UniquePtr&) { }
};

int main()
{
	// 스마트 포인터
	// shared_ptr	: refCount라는 참조 갯수가 참조가 될 때마다 증가하는데, 참조 갯수가 0이 되어야 삭제하는 방식
	
	// weak_ptr		: 독립적으로 사용할 수 없고 shared_ptr의 사이클 문제를 보충하기 위해 태어난 포인터 
	//				  weakrefCount라는 개별의 숫자를 이용해 refCount 블록을 추적(존재하는지 판단)하는 기능
	//				  refCount 블록이 없어지지 않은 경우 다시 shared_ptr을 사용 가능하도록 해줌.
	
	// unique_ptr	: 하나만 존재해야 함. 복사와 관련된 것을 다 막아둠. 이동은 가능

#pragma region Shared_Ptr : refCount라는 참조 갯수가 참조가 될 때마다 증가하는데, 참조 갯수가 0이 되어야 삭제하는 방식
	{
		// 이 방식에서는 몇 명이 가리키는지 모름.
		Knight* k1 = new Knight();

		Knight* k3;

		k3 = k1;
	}
	{
		// 이 방식으로는 refCount가 증가하기 때문에 몇 명이 가리키는지 명확함.
		// 얕은 복사처럼 동일 포인터를 관리하지만,
		// 실질적으로는 refCount가 증가하기 때문에 만들어 준 것.
		SharedPtr<Knight> k1(new Knight());
		SharedPtr<Knight> k3;
		k3 = k1;

		// 우리가 원하는 시점에서 소멸시킬 수 없음. (아무도 기억하지 않을 때 삭제되기 때문)

		// 아래의 상황일 시 Attack 함수 내부에서
		// 딜리트된 메모리를 접근하는 use after free
		//k1->_target = k2;
		//delete k2;
		//k1->Attack();
	}
#pragma endregion
#pragma region Weak_Ptr : shared_ptr이 서로를 가리키는 경우 refCount의 변화가 일어나지 않는 문제가 발생할 수 있기 때문에 그것을 보완하기 위한 용도로 등장
	{
		shared_ptr<Knight> k1(new Knight());	// refCount = 1 >> k1 소멸시 0
		weak_ptr<Knight> weak = k1;				// refCount는 증가하지 않음, weakCount라는 개별의 수를 관리함.
												// weakCount는 refCount의 유무를 판단하는 용도
		shared_ptr<Knight> k2(new Knight());	// refCount = 2 
		// 연쇄적으로 k1.타겟이 k2를 가리키지 않으므로 refCount가 -1 되어 k2의 refCount = 1;
		// 이어서 k2의 refCount도 -1이 되면서 0으로 소멸

		// 이 순간 refCount가 1 증가함
		k1->_target = k2;
		k2->_target = k1;
		// 이렇게 서로 가리키는 경우 메모리 누수(Memory Reak)가 일어난다.
		// refCount가 0이 되어야 소멸하는데 서로를 가리키고 있으므로 0이 될 수 없음.
		// 인위적으로 타겟을 nullptr로 밀어주지 않는 이상 사라지지 않음 (메모리 누수)
	}
#pragma endregion
#pragma region Unique_Ptr : 하나만 존재해야 함. 복사와 관련된 것을 다 막아둠. 이동은 가능
	{
		unique_ptr<Knight> k(new Knight());
		unique_ptr<Knight> k2;
		// 자기 자신의 권한을 포기하고 k2에 모든 것을 위임하는 것.
		k2 = std::move(k);
	}
#pragma endregion
}