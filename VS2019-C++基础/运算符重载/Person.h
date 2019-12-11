#pragma once
#include <iostream>
using namespace std;
class Person
{
public:
	Person() :m_a(0), m_b(0){}
	Person(int a, int b) :m_a(a), m_b(b) {}
	Person(const Person& p);/*�������캯��*/
	//��Ա����ʵ�� + - = << >> �����������
	friend const Person operator+(const Person& p1, const Person& p2);
	friend const Person operator-(const Person& p1, const Person& p2);
	~Person();
	void show() const;
public:
	int m_a;
	int m_b;
};

