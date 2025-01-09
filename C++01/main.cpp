#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

//int main()
//{
//	string s;
//	cin >> s;
//
//	for (char c : s)
//	{
//		cout << c << endl;
//	}
//	return 0;
//}

//
//int main()
//{
//	int sum;
//	cin >> sum;
//	if (sum % 2 == 0)
//	{
//		cout <<sum<<" " << "is even" << endl;
//	}
//	else
//	{
//		cout <<sum<<" " << "is odd" << endl;
//	}
//	return 0;
//}





//string solution(string my_string, string overwrite_string, int s)
//{
//	//第一步：保留原字符串的前部分 从0到s-1
//	string prefix = my_string.substr(0, s);
//
//	//第二步：直接替换中间部分为overwrite_string
//	string middle = overwrite_string;
//
//	//第三步：保留剩余部分 从s+overwrite_string.length()到结束
//	string suffix = my_string.substr(s + overwrite_string.length());
//
//	return prefix + middle + suffix;
//}
//
//int main()
//{
//	string result1 = solution("HelloWorld", "22oWor2", 2);
//	cout << result1 << endl;
//
//	string result2 = solution("Program2988UYP", "mers123", 7);
//	cout << result2 << endl;
//	return 0;
//}

//知识点总结1 关于STL中的string类的成员函数 substr

//int main()
//{
//	string my_write = "HelloWorld";
//	string subb = my_write.substr(0, 5);
//	cout << subb << endl;
//
//	string subb1 = my_write.substr(5);
//	cout << subb1 << endl;
//	//提出从索引5开始的剩余字符
//	
//	string subb2 = my_write.substr(3, 4);
//	cout << subb2 << endl;
//	//提取从索引3开始的4个字符
//	return 0;
//}





//string mengString(const string& str1, const string& str2)
//{
//	int len1 = str1.size();
//	int len2 = str2.size();
//	int length = max(str1, str2);
//	string result;
//	for (int i = 0; i < length; i++)
//	{
//		if (i < len1)
//		{
//			result += str1[i];
//		}
//		if (i < len2)
//		{
//			result += str2[i];
//		}
//		return result;
//	}
//}
//int main()
//{
//	string str1 = "aaaaa";
//	string str2 = "bbbbb";
//
//	string result = mengString(str1, str2);
//	cout << result << endl;
//
//	cout << endl;
//	return 0;
//}





//int main()
//{
//	int length = 5;
//	for (int i = 0; i < length; i++)
//	{
//		cout << i << endl;
//	}
//	cout << endl;
//	
//	return 0;
//}



//
//int main()
//{
//	string length = "helloworld";
//	for (int i = 0; i < length.size(); i++)
//	{
//		cout << length[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}







//int main()
//{
//	string str;
//	cin >> str;
//	string answer;
//	for (const char& arr : str)
//	{
//		answer += arr;
//	}
//	cout << answer << endl;
//	cout << endl;
//	return 0;
//}







//int main()
//{
//	string s;
//	int k;
//	cin >> s;
//	cin >> k;
//	for (int i = 0; i < k; i++)
//	{
//		cout << s << "";
//	}
//	cout << endl;
//	return 0;
//}



//
//int main()
//{
//	int a = 0, b = 0;
//	cin >>a>>b;
//	string num1 = to_string(a);
//	string num2 = to_string(b);
//	string A = num1 + num2;
//	string B = num2 + num1;
//
//	if (A > B)
//	{
//		cout << A << endl;
//		return stoi(A);
//		
//	}
//	else if (B > A)
//	{
//		cout << B << endl;
//		return stoi(B);
//		
//	}
//	else
//	{
//		cout << A << endl;
//		return stoi(A); //两个值相等的话，返回任意一个
//		
//	}
//	cout << endl;
//	return 0;
//}







//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	string num = to_string(a);
//	string num1 = to_string(b);
//
//	string number = num + num1;
//
//	int number1 = 2 * a * b;
//	string number2 = to_string(number1);
//
//	if (number > number2)
//	{
//		cout << "1比2大:" << endl;
//	}
//	else
//	{
//		cout << "1比2小:" << endl;
//	}
//	cout << endl;
//	return 0;
//}




//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int num = stoi(to_string(a) + to_string(b));
//	int num1 = 2 * a * b;
//	if (num > num1)
//	{
//		cout << "num大" << endl;
//	}
//	else
//	{
//		cout << "num1大" << endl;
//	}
//	return 0;
//}






//int main()
//{
//	int a = 10; 
//	int sum = 0;
//	int num = 0;
//	while (a % 2 == 0)
//	{
//		sum += pow(a, 2);
//		a = a - 2;
//		if (a < 0)break;
//	}
//	cout << sum << endl;
//
//	int b = 7;
//	while (b % 2 != 0)
//	{
//		num += b;
//		b = b - 2;
//		if (b < 0)break;
//	}
//	cout << num << endl;
//	cout << endl;
//	
//	return 0;
//}




//int main()
//{
//	int a = 10, b = 20;
//	string num1 = to_string(a);
//	string num2 = to_string(b);
//
//	string Number = num1 + num2;
//
//	bool Greater = (Number < num2);
//	if (Greater)
//	{
//		cout << "错误" << endl;
//	}
//	else
//	{
//		cout<<"正确" << endl;
//	}
//	cout << Number << endl;
//	cout << endl;
//	return 0;
//}






//
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int sum = a + b;
//	int sum1 = a - b;
//	cout << sum << endl;
//	cout << sum1 << endl;
//	cout << endl;
//
//	return 0;
//}

//bool sum(int result, int expected)
//{
//	return result == expected;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int result = a + b;
//	int expected;
//	cin >> expected;
//
//	if (sum(result, expected))
//	{
//		cout << "正确" << endl;
//	}
//	else
//	{
//		cout << "错误" << endl;
//	}
//	cout << endl;
//	return 0;
//}




//int main()
//{
//	vector<int>result = { 2,1,6 };
//	cout << result.back() << endl;//这样的话打印最后一个元素
//	//或者用
//	cout << result.size() - 1 << endl;
//	cout << result[result.size() - 1] << endl;//这个也是打印6
//	//cout << result[result.back() - 1] << endl; //这个为何报错？
//	cout << result[result.size() - 2] << endl;//打印倒数第二个
//	
//	
//	cout << endl;
//	return 0;
//}




int main()
{
	int sum = 0;
	//vector<int>result = { 2,1,6 };
	vector<int>result = { 5,2,1,7,5 };
	if (result.back() > result[result.size() - 2])
	{
		//cout << "True" << endl;
		sum = result.back() - result[result.size() - 2];
		result.push_back(sum);
	}
	else
	{
		sum = result.back() * 2;
		result.push_back(sum);
		//cout << "False" << endl;
	}
	for (int number : result)
	{
		cout << number << " ";
	}
	//cout << sum << " ";
	cout << endl;
	cout << result.size() << " ";
	cout << endl;
	return 0;
}