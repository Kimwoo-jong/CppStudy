#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct Vertex
{
	//int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vertices.resize(6);

	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[5][4] = adjacent[4][5] = 5;
}

struct VertexCost
{
	VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) {}

	// 함수 내에서 수정하지 않겠다는 약속으로 함수 뒤에 const 표기
	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const VertexCost& other) const
	{
		return cost > other.cost;
	}

	int cost;
	int vertex;
};

// Dijikstra = BFS + 양념(cost)
// - BFS = queue
// - Dijikstra = priority_queue
void Dijikstra(int here)
{
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;
	// 최적의 경로를 저장해줄 벡터 생성
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	pq.push(VertexCost(0, here));
	best[here] = 0;
	parent[here] = here;

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		VertexCost v = pq.top();
		pq.pop();

		int cost = v.cost;
		here = v.vertex;

		// 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if(best[here] < cost)
			continue;

		// 방문
		cout << "방문! " << here << endl;

		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않았으면 스킵
			if(adjacent[here][there] == -1)
				continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			
			if(nextCost >= best[there])
				continue;

			// 지금까지 찾은 경로 중에서는 최선의 수치 = 갱신
			best[there] = nextCost;
			// 후에 갱신될 수 있음.
			parent[there] = here;
			pq.push(VertexCost(nextCost, there));
		}
	}
}

int main()
{
	CreateGraph();

	Dijikstra(0);
}