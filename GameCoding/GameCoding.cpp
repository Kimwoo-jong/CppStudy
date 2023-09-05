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
	// 1) ASCII 코드 'a' = 97, 'A' = 65
	char ch = 'a';
	// 7bit (0 ~ 127)

	// 2) ANSI >> 동일한 키코드 값 = 동일한 문자
	// // ASCII + 각 국 언어별로 128
	// CP949(한국어)

	// 3) 유니코드 (동일 번호 = 동일한 문자 = 동일한 유니코드)
	// 인코딩(UTF-8)
	// - UTF-8	: 영어(1), 한국어/중국어(3)
	// - UTF-16 : 영어(2), 한국어(2), 중국어(2)

	// 4) MBCS(Multi Bytes Character Set) vs WBCS(Wide Byte Character Set)
	// - 멀티바이트 집합	: 가변 길이 인코딩	>> UTF-8
	// - 유니코드 집합	: 고정 길이 인코딩	>> UTF-16

	setlocale(LC_ALL, "");
	cout << "LC_ALL : " << setlocale(LC_ALL, NULL) << endl;

	// CP949(한국어)
	const char* test = "안녕하세요";
	cout << test << endl;

	//
	auto test2 = u8"aaa김우종입니당";
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;

	//
	auto test3 = u"김우종데스";

	// char // string
	wchar_t ch1 = L'김';
	wstring name = L"김우종데스웅";

	wcout << name << endl;
}