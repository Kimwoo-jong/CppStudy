#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>

enum class ObjectType
{
	Player,
	Monster,
	Projectile,
	Env
};

class Object
{
public:
	Object(ObjectType type) : _type(type) { }

	virtual ~Object() { }
	virtual void Init()
	{

	}

	virtual void Update()
	{

	}

	ObjectType GetObjectType() { return _type; }

	int _id;
	ObjectType _type;
};

class Player : public Object
{
public:
	Player() : Object(ObjectType::Player) {}
	Player(int id) : Object(ObjectType::Player) { }
};

class Monster : public Object
{
public:
	Monster() : Object(ObjectType::Monster) { }

};

class Projectile : public Object
{
public:
	Projectile() : Object(ObjectType::Projectile) { }

};

class Env : public Object
{
public:
	Env() : Object(ObjectType::Env) { }

};

class Field
{
public:
	static Field* GetInstance()
	{
		static Field field;
		return &field;
	}

	void Add(Object* player)
	{
		_objects.insert(make_pair(player->_id, player));
	}

	void Remove(int id)
	{
		_objects.erase(id);
	}

	void Update()
	{
		for (auto& item : _objects)
		{
			Object* obj = item.second;
			obj->Update();
		}
	}

	Object* Get(int id)
	{
		auto findIt = _objects.find(id);
		if (findIt != _objects.end())
			return findIt->second;

		return nullptr;
	}

	unordered_map<int, Object*> _objects;

	//unordered_map<int, Player*> _players;
	//unordered_map<int, Monster*> _monsters;
	//unordered_map<int, Projectile*> _projectiles;
	//unordered_map<int, Env*> _env;
};
int main()
{
	// 클래스의 상속 시 상위 객체에는 virtual 소멸자를 생성해야 함.
	// 상속 받은 하위 객체의 소멸자가 실행되지 않기 때문
	Field::GetInstance()->Add(new Player());

	Object* obj = Field::GetInstance()->Get(1);
	if (obj && obj->GetObjectType() == ObjectType::Player)
	{
		Player* player = static_cast<Player*>(obj);
	}

	Player* player = dynamic_cast<Player*>(Field::GetInstance()->Get(1));
	if (player)
	{

	}
}