//
//  String.cpp
//  CPP
//
//  Created by 张木林 on 10/29/24.
//
#include<iostream>
#include<cstring>
#include<stdexcept
using namespace std;
namespace bit

{

  class string

{
    
    friend ostream& operator<<(ostream& _cout, const bit::string& s);
    
    friend istream& operator>>(istream& _cin, bit::string& s);
    
public:
    
    typedef char* iterator;
    
    //  public:
    //      using iterator = char*;
    string(const char* str = "")
    {
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity+1];
        strcpy(_str,str);
    }
    
    //拷贝构造函数
    
    
    string(const string& s)
    {
        _size = s._size;
        _capacity = s._capacity;
        _str = new char[_capacity+1];
        strcpy(_str,s._str);
    }
    
    //赋值运算符
    string& operator=(const string &s)
    {
        if(this != &s)
        {
            char* new_str = new char[s._capacity+1];
            strcpy(new_str,s._str);
            delete[]_str;
            _str = new_str;
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }
    
    //析构函数
    ~string()
    {
        delete[]_str;
    }
    
    
    
    //////////////////////////////////////////////////////////////
    
    // iterator
    //迭代器
    iterator begin(){return _str;}
    
    iterator end(){return _str+_size;}
    
    
    
    /////////////////////////////////////////////////////////////
    
    // modify
    //修改操作
    void push_back(char c)
    {
        if(_size == _capacity)
        {
            reserve(_capacity == 0?1 : _capacity*2);
        }
        _str[_size++] = c;
        _str[_size] = '\0';
    }
    
    string& operator+=(char c)
    {
        push_back(c);
        return *this;
    }
    
    void append(const char* str)
    {
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size,str);
        _size += len;
    }
    
    string& operator+=(const char* str)
    {
        append(str);
        return *this;
    }
    
    void clear()
    {
        _size = 0;
        _str[0] = '\0';
    }
    
    void swap(string& s)
    {
        std::swap(_str,s._str);
        std::swap(_size,s._size);
        std::swap(_capacity,s._capacity);
    }
    
    const char* c_str()const
    {
        return _str;
    }
    
    
    
    /////////////////////////////////////////////////////////////
    
    // capacity
    //容量管理
    size_t size()const{return _size;}
    
    size_t capacity()const{return _capacity;}
    
    
    bool empty()const{return _size == 0;}
    
    void resize(size_t n, char c = '\0')
    {
        if(n>_capacity)
            
        {
            reserve(n);
        }
        if(n>_size)
        {
            for(size_t i = _size;i<n;i++)
            {
                _str[i] = c;
            }
        }
        _size = n;
        _str[_size] = '\0';
    }
    
    void reserve(size_t n)
    {
        if(n>_capacity)
        {
            char* new_str = new char[n+1];
            strcpy(new_str,_str);
            delete[]_str;
            _str = new_str;
            _capacity = n;
        }
    }



    /////////////////////////////////////////////////////////////

    // access
    //访问操作
    char& operator[](size_t index){return _str[index];}

    const char& operator[](size_t index)const{return _str[index];}



    /////////////////////////////////////////////////////////////

    //relational operators

        //比较运算符
    bool operator<(const string& s)const{return strcmp(_str,s._str)<0;}

    bool operator<=(const string& s)const{return strcmp(_str,s._str)<=0;}

    bool operator>(const string& s)const{return strcmp(_str,s._str)>0;}

    bool operator>=(const string& s)const{return strcmp(_str,s._str)>=0;}

    bool operator==(const string& s)const{return strcmp(_str,s._str) == 0;}

    bool operator!=(const string& s)const{return strcmp(_str,s._str) !=0;}



    // 返回c在string中第一次出现的位置

    size_t find (char c, size_t pos = 0) const;

    // 返回子串s在string中第一次出现的位置

    size_t find (const char* s, size_t pos = 0) const;

    // 在pos位置上插入字符c/字符串str，并返回该字符的位置

    string& insert(size_t pos, char c);

    string& insert(size_t pos, const char* str);

     

    // 删除pos位置上的元素，并返回该元素的下一个位置

    string& erase(size_t pos, size_t len);

  private:

    char* _str;

    size_t _capacity;

    size_t _size;

  }

}；
