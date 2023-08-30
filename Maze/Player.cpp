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
		
		// 이동
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

	// 목적지
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0),  // DOWN
		Pos(0, 1)   // RIGHT
	};

	// 내가 바라보는 방향 기준 앞에 있는 좌표
	/*Pos nextPos = pos + front[_dir];*/

	// 목적지를 찾을 때까지
	while (pos != dest)
	{					
		// 위쪽를 볼 때 (-1 + 4) % 4 == 3 (Right)
		// 왼쪽을 볼 때 (0 + 4) % 4 == 0 (Up)
		// 아래쪽을 볼 때 (1 + 4) % 4 == 1 (Left)
		// 오른쪽을 볼 때 (2 + 4) % 4 == 2 (Down)
		
		// 현재 바라보는 방향 기준 우측 방향을 바라봄
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		// 1. 현재 바라보는 방향 기준, 우측으로 갈 수 있는지 확인
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = newDir;
			// 앞으로 1보 전진
			pos += front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if(CanGo(pos + front[_dir]))
		{
			// 앞으로 1보 전진
			pos += front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
}

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	// 목적지
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
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견됨.
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	// 큐가 비어있지 않으면 무한 루프
	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 목적지 도착
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역인지 확인
			if(CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견된 지역인지 확인
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

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	// Reverse 함수를 사용하지 않았을 경우
	// 직접 구현하여 큐를 뒤집어주는 것
	/*vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
	{
		temp[i] = _path[_path.size() - 1 - i];
	}

	_path = temp;*/

	// 위에서 구현한 함수가 출구 -> 시작점이므로
	// 큐의 순서를 바꾸면 정방향 재생
	//::reverse(_path.begin(), _path.end());
}