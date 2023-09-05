#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;



int main()
{
	std::string str = "DevWooj";
	std::string str2 = "DevWooj";

	// 1) 비교 -> ID/PW 맞는지
	if (str == str2)
	{
	}

	// 2) 복사
	string str3;
	str3 = str;

	// 3) 추가 ()
	//str.append("1231231232");
	str += "1234";

	// 4) 찾기
	auto c = str.find("Dev");
	if (c == std::string::npos)
	{
		cout << "Not Found" << endl;
	}

	// 5) 교체
	string chatStr = "SHIT !!!";
	string findStr = "SHIT";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	string str4 = str.substr(0, 3);

	const char* name = str.c_str();
}