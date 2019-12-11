#include "Computer.h"

Computer::Computer()
{
	this->card = NULL;
	this->mem = NULL;
	this->cpu = NULL;
}

Computer::Computer(Card* card, Memary* mem, CPU* cpu)
{
	this->card = card;
	this->mem = mem;
	this->cpu = cpu;
}

Computer::~Computer()
{
	if (this->card != NULL)
	{
		delete this->card;
	}
	if (this->mem != NULL)
	{
		delete this->mem;
	}
	if (this->cpu != NULL)
	{
		delete this->cpu;
	}
}

void Computer::show()
{
	if (this->card)
	{
		this->card->disPlay();
	}
	else
	{
		std::cout << "�õ������Կ�" << std::endl;
	}
	if (this->cpu)
	{
		this->cpu->calculate();
	}
	else
	{
		std::cout << "�õ�����cpu" << std::endl;
	}
	if (this->mem)
	{
		this->mem->storage();
	}
	else
	{
		std::cout << "�õ������ڴ���" << std::endl;
	}
	
}
