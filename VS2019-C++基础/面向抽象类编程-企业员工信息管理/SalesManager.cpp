#include "SalesManager.h"

SalesManager::SalesManager(double salesDegree, std::string name)
{
	this->name = name;
	this->salesDegree = salesDegree;//�����ܶ�
	this->fixedSalary = 4000;//�̶�н��
}

SalesManager::~SalesManager()
{
}

void SalesManager::pay()
{
	this->salary = this->fixedSalary + this->salesDegree * 0.05;
}

void SalesManager::upLevel()
{
	this->level++;
	this->fixedSalary += 1000;
}
