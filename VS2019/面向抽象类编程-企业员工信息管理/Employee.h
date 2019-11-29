#pragma once
#include <iostream>
#include <string>

class Employee
{
public:
	Employee();
	Employee(std::string name);
	virtual ~Employee();
	//����Ա��н��
	virtual void pay() = 0;
	//��ӡԱ����Ϣ
	void displayStatus();
	//��������
	virtual void upLevel() = 0;
protected:
	std::string name;//����
	size_t id;//���
	size_t level;//����
	double salary;//нˮ
	static size_t sum;//Ա����������������ְ���
};

