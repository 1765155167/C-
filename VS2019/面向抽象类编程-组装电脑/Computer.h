#pragma once
#include "Card.h"
#include "Memary.h"
#include "CPU.h"

class Computer
{
public:
	Computer();
	Computer(Card* card, Memary* mem, CPU* cpu);
	~Computer();
	void show();
private:
	Card* card;//�Կ�
	Memary* mem;//�ڴ���
	CPU* cpu;//cpu
};

