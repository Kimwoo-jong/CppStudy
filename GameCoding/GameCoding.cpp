#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// DFS (depth first search)
// DFS = 재귀함수 = 스택
// BFS (breath first search)
// BFS = 큐

struct Vertex
{
	//int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 발견한
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트
	/*adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};

}

void Bfs(int here)
{
	// ex) 누구에 의해서 발견되었는지
	vector<int> parent(6, -1);
	// ex) 시작점에서 얼마만큼 떨어져 있는지
	vector<int> dist(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	//
	parent[here] = here;
	dist[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		// 방문 도장
		cout << "Visited : " << here << endl;

		for (int there = 0; there < 6; there++)
		{
			if(adjacent[here][there] == 0)
				continue;
			if(discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
			//
			parent[there] = here;
			dist[there] = dist[here] + 1;
		}

		/*int size = adjacent[here].size();
		for (int i = 0; i < size; i++)
		{
			int there = adjacent[here][i];
			if(discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
		}*/
	}
}

void BfsAll()
{
	discovered = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

int main()
{
	CreateGraph();
	
	Bfs(0);
}