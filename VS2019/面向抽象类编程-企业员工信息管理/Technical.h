#pragma once
#include "Employee.h"
class Technical :
	public Employee
{
public:
	Technical(size_t time_month, std::string name);
	//����Ա��н��
	virtual void pay();
	//��������
	virtual void upLevel();
	void setTimeMonth(size_t timeMonth);
	~Technical();
private:
	size_t timeMonth;//һ���¹����˶���Сʱ
	int hourMoney;
};

