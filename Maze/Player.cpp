#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//CalculatePath_RightHand();
	CalculatePath_BFS();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;
		
	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		
		// �̵�
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);

	return tileType == TileType::EMPTY;
}

void Player::CalculatePath_RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// ������
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0),  // DOWN
		Pos(0, 1)   // RIGHT
	};

	// ���� �ٶ󺸴� ���� ���� �տ� �ִ� ��ǥ
	/*Pos nextPos = pos + front[_dir];*/

	// �������� ã�� ������
	while (pos != dest)
	{					
		// ���ʸ� �� �� (-1 + 4) % 4 == 3 (Right)
		// ������ �� �� (0 + 4) % 4 == 0 (Up)
		// �Ʒ����� �� �� (1 + 4) % 4 == 1 (Left)
		// �������� �� �� (2 + 4) % 4 == 2 (Down)
		
		// ���� �ٶ󺸴� ���� ���� ���� ������ �ٶ�
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		// 1. ���� �ٶ󺸴� ���� ����, �������� �� �� �ִ��� Ȯ��
		if (CanGo(pos + front[newDir]))
		{
			// ������ �������� 90�� ȸ��
			_dir = newDir;
			// ������ 1�� ����
			pos += front[_dir];
			// ��ǥ ���
			_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��
		else if(CanGo(pos + front[_dir]))
		{
			// ������ 1�� ����
			pos += front[_dir];
			// ��ǥ ���
			_path.push_back(pos);
		}
		else
		{
			// ���� �������� 90�� ȸ��
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
}

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	// ������
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0),  // DOWN
		Pos(0, 1)   // RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	// extra)
	// parent[y][x] = pos -> (y, x)�� Pos�� ���� �߰ߵ�.
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	// ť�� ������� ������ ���� ����
	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// ������ ����
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// �� �� �ִ� �������� Ȯ��
			if(CanGo(nextPos) == false)
				continue;
			// �̹� �ٸ� ��ο� ���� �߰ߵ� �������� Ȯ��
			if(discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}
	}

	_path.clear();
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// ������
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	// Reverse �Լ��� ������� �ʾ��� ���
	// ���� �����Ͽ� ť�� �������ִ� ��
	/*vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
	{
		temp[i] = _path[_path.size() - 1 - i];
	}

	_path = temp;*/

	// ������ ������ �Լ��� �ⱸ -> �������̹Ƿ�
	// ť�� ������ �ٲٸ� ������ ���
	//::reverse(_path.begin(), _path.end());
}