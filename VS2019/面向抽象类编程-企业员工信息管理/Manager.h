#pragma once
#include "Employee.h"
class Manager :
	virtual public Employee
{
public:
	Manager();
	Manager(std::string name);
	~Manager();
	//����Ա��н��
	virtual void pay();
	//��������
	virtual void upLevel();
public:
	double fixedSalary;//�̶�н��
};

