//
//  StringReverse.cpp
//  LeetCode
//
//  Created by 张木林 on 1/15/25.
//

#include "StringReverse.hpp"
#include<utility> // swap
#include<iostream>


void StringReverse::reverseString(string &str)
{
    int left = 0; //左指针
    int right = str.size() -1; //右指针
    
    //双指针逐步向中间移动
    while(left < right)
    {
        swap(str[left],str[right]);//交换两个指针位置上的字符
        left++;
        right--;
    }
}


int main() {
    std::string myString = "Hello, World!";
    std::cout << "原始字符串: " << myString << std::endl;

    // 调用反转函数
    StringReverse::reverseString(myString);
    std::cout << "反转后的字符串: " << myString << std::endl;

    return 0;
}
