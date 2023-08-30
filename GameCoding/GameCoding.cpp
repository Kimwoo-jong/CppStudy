#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// 깊이 우선 탐색
// DFS (depth first search)
// DFS = 재귀함수
// BFS = 

struct Vertex
{
	//int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 내가 방문한 목록
vector<bool> visited;

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

void Dfs(int here)
{
	// 방문 도장
	visited[here] = true;

	cout << "Visited : " << here << endl;

	// 인접 리스트 O(V + E)
	/*const int size = adjacent[here].size();
	for (int i = 0; i < size; i++)
	{
		int there = adjacent[here][i];
		
		if (visited[there] == false)
			Dfs(there);
	}*/

	// 인접 행렬 O(V^2)
	for (int there = 0; there < 6; there++)
	{
		// 길이 있는지
		if(adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳에 한해서 방문
		if (visited[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
		{
			Dfs(i);
			cout << "hi" << endl;
		}
	}
}

int main()
{
	CreateGraph();

	DfsAll();
}