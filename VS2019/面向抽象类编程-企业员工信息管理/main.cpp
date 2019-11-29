#include "Employee.h"
#include "Technical.h"
#include "Manager.h"
#include "Salesperson.h"
#include "SalesManager.h"

void test(Employee* tech)
{
	tech->upLevel();
	tech->upLevel();
	tech->pay();
	tech->displayStatus();
	delete tech;
}

int main()
{
	//test(new Technical(300, "�����"));
	//test(new Manager("С��"));
	//test(new Salesperson(500000,"С��"));
	test(new SalesManager(500000, "С��"));
	return 0;
}