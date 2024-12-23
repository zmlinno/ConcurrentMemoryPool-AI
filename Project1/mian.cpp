#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


bool isFirstAndLastEqual(const string& str)
{
	if (str.empty())
	{
		return false;
	}
	return str.front() == str.back();
}
int main()
{
	string input;
	cout << "请输入一个字符: " << endl;
	cin >> input;

	if (isFirstAndLastEqual(input))
	{
		cout << "第一个字母和最后一个字母相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	return 0;
}