#pragma once
#include <iostream>
#include <cstring>
class MyString
{
public:
	MyString();
	MyString(const char* data);
	MyString(const char ch);
	MyString(const MyString& another);
	/*���� =��+��==��!=��[]��<<��>> ����� */
	MyString& operator=(const MyString& another);
	MyString operator+(const MyString& another);
	bool operator==(const MyString& another);
	bool operator!=(const MyString& another);
	char& operator[](size_t num)const;
	friend std::ostream& operator<<(std::ostream& os, MyString& another);
	friend std::istream& operator>>(std::istream& is, MyString& another);
	const char* to_str()const;/*�����ַ���*/
	const size_t length() const;/*�����ַ�������*/
	~MyString();
private:
	char* buf;
	size_t len;
};

