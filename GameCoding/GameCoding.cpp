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
		if (_target)
			_target->_hp -= _damage;
	}

public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr;
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

void Test(shared_ptr<Knight>& k)
{
	// 여기서 refCount는 +1됨
}

int main()
{
	// 스마트 포인터
	// shared_ptr	: 
	// weak_ptr		: 
	// unique_ptr	: 

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
	}

	shared_ptr<Knight> k1(new Knight());
	shared_ptr<Knight> k2(new Knight());

	// 이 순간 refCount가 1 증가함
	k1->_target = k2;

	// 우리가 원하는 시점에서 소멸시킬 수 없음. (아무도 기억하지 않을 때 삭제되기 때문)

	// 아래의 상황일 시 Attack 함수 내부에서
	// 딜리트된 메모리를 접근하는 use after free
	//k1->_target = k2;

	//delete k2;

	//k1->Attack();
}