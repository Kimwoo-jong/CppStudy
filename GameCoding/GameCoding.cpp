#include <iostream>
using namespace std;
#include <vector>
#include <queue>

#pragma region 이 방식이 직관적이다.
//void CreateGraph_1()
//{
//	struct Vertex
//	{
//		// int data;
//		vector<Vertex*> edges;
//	};
//
//	// 데이터의 갯수와 초기값
//	//vector<int> v2(10, -1);
//
//	// 넣어줄 초기 데이터를 강제로 세팅
//	//vector<int> v3{1, 2, 3, 4, 5, 6, 7};
//
//	vector<Vertex> v(6);
//
//	v[0].edges.push_back(&v[1]);
//	v[0].edges.push_back(&v[3]);
//	v[1].edges.push_back(&v[0]);
//	v[1].edges.push_back(&v[2]);
//	v[1].edges.push_back(&v[3]);
//	v[3].edges.push_back(&v[4]);
//	v[5].edges.push_back(&v[4]);
//
//	bool connected = false;
//
//	int size = v[0].edges.size();
//
//	for (int i = 0; i < size; i++)
//	{
//		Vertex* vertex = v[0].edges[i];
//
//		if (vertex == &v[3])
//			connected = true;
//	}
//}
#pragma endregion
#pragma region 인접 리스트 : 실제 연결된 애들'만' 넣어준다.
//void CreateGraph_2()
//{
//	struct Vertex
//	{
//		int data;
//	};
//
//	vector<Vertex> v(6);
//
//	// [v][v][v][v][v][v]
//	vector<vector<int>> adjacent;
//	adjacent.resize(6);
//
//	//adjacent[0].push_back(1);
//	//adjacent[0].push_back(3);
//
//	adjacent[0] = { 1, 3 };
//	adjacent[1] = { 0, 2, 3 };
//	adjacent[3] = { 4 };
//	adjacent[5] = { 4 };
//
//	// Q. 0번->3번이 연결되어 있습니까?
//	bool connected = false;
//
//	int size = adjacent[0].size();
//
//	for (int i = 0; i < size; i++)
//	{
//		int vertex = adjacent[0][i];
//		if (vertex == 3)
//		{
//			connected = true;
//		}
//	}
//}
#pragma endregion
#pragma region 인접 행렬
//void CreateGraph_3()
//{
//	struct Vertex
//	{
//		int data;
//	};
//
//	vector<Vertex> v(6);
//
//	// 연결된 목록을 행렬로 관리
//	// [X][O][X][O][X][X]
//	// [O][X][O][O][X][X]
//	// [X][X][X][X][X][X]
//	// [X][X][X][X][O][X]
//	// [X][X][X][X][X][X]
//	// [X][X][X][X][O][X]
//
//	// adjacent[from][to] ?
//	// 행렬을 이용한 그래프 표현
//	// 메모리 소모가 심하나, 빠른 접근 가능
//	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
//
//	adjacent[0][1] = true;
//	adjacent[0][3] = true;
//	adjacent[1][0] = true;
//	adjacent[1][2] = true;
//	adjacent[1][3] = true;
//	adjacent[3][4] = true;
//	adjacent[5][4] = true;
//
//	// Q) 0번과 3번이 연결되어 있는가
//	bool connected = adjacent[0][3];
//
//	vector<vector<int>> adjacent2 =
//	{
//		{ -1, 15, -1, 35, -1, -1},
//		{ 15, -1, +5, 10, -1, -1},
//		{ -1, +5, -1, -1, -1, -1},
//		{ 35, 10, -1, -1, +5, -1},
//		{ -1, -1, -1, +5, -1, +5},
//		{ -1, -1, -1, -1, +5, -1},
//	};
//}
#pragma endregion

int main()
{

}
