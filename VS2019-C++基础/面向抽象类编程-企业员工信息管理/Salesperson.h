#pragma once
#include "Employee.h"
//������Ա
class Salesperson :
	virtual public Employee
{
public:
	Salesperson();
	Salesperson(double salesDegree, std::string name);
	~Salesperson();
	//����Ա��н��
	virtual void pay();
	//��������
	virtual void upLevel();
protected:
	double salesDegree;//���۶��
};

