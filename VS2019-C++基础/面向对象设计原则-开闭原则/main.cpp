#include <iostream>
//����ԭ�� ��չ���š����Ĺر�
//���Ӵ������ʽ��չ��

//дһ��������
class AbstractCalculator
{
public:
	virtual double getResult() = 0;
	virtual void setOperatorNum(double a, double b) = 0;
};

//�ӷ�������
class PlusCalcualtor : public AbstractCalculator
{
public:
	PlusCalcualtor():a(0),b(0) {

	}
	void setOperatorNum(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double getResult() {
		return this->a + this->b;
	}
private:
	double a;
	double b;
};

//����������
class MinuteCalcualtor : public AbstractCalculator
{
public:
	MinuteCalcualtor():a(0),b(0) {

	}
	void setOperatorNum(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double getResult() {
		return this->a - this->b;
	}
private:
	double a;
	double b;
};

//�˷�������
class MultiplyCalcualtor : public AbstractCalculator
{
public:
	MultiplyCalcualtor():a(0),b(0) {
		
	}
	void setOperatorNum(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double getResult() {
		return this->a * this->b;
	}
private:
	double a;
	double b;
};
//ʱ���������չ��ȡģ����������ʱ�����޸���ǰ�Ĵ���
class DemoCalcualtor : public AbstractCalculator
{
public:
	DemoCalcualtor():a(0),b(0) {

	}
	void setOperatorNum(double a, double b) {
		this->a = a;
		this->b = b;
	}
	double getResult() {
		return static_cast<int>(this->a) % static_cast<int>(this->b);
	}
private:
	double a;
	double b;
};

void test01()
{
	AbstractCalculator* cal = new MultiplyCalcualtor;
	cal->setOperatorNum(10, 20);
	std::cout << cal->getResult() << std::endl;
	delete cal;

	cal = new MinuteCalcualtor;
	cal->setOperatorNum(10, 20);
	std::cout << cal->getResult() << std::endl;
	delete cal;

	cal = new DemoCalcualtor;
	cal->setOperatorNum(20, 7);
	std::cout << cal->getResult() << std::endl;
	delete cal;
}

int main()
{
	test01();
	return 0;
}