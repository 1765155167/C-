#pragma once
#include "Salesperson.h"
#include "Manager.h"
class SalesManager :
	public Salesperson, public Manager
{
public:
	SalesManager(double salesDegree, std::string name);
	~SalesManager();
	//����Ա��н��
	virtual void pay();
	//��������
	virtual void upLevel();
private:

};

