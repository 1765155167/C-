#include <iostream>
#include <deque>
#include <map>
#include "Worker.h"
#include <time.h>
#include <algorithm>
//��Ŀ����
/*
 *������Ƹ��5��Ա����5��Ա�����빫˾����Ҫָ��Ա�����Ǹ����Ź���
 *Ա����Ϣ��:���� ���� �绰 ���ʵ�
 *ͨ��MultiMap������Ϣ�Ĳ��� ���� ��ʾ
 *�ֲ�����ʾԱ����Ϣ
*/
const int SalDep = 1;//���۲���
const int TechDep = 2;//�з�����
//����Ա��
void CreateWorker(std::deque<Worker*>& dWorker)
{
	Worker* p;
	p = new Worker("�����", "17550296339", 20, 10000);
	dWorker.push_back(p);
	p = new Worker("����ͷ", "17625525535", 21, 8000);
	dWorker.push_back(p);
	p = new Worker("С����", "18595801890", 22, 18000);
	dWorker.push_back(p);
	p = new Worker("С��", "18958338972", 22, 15000);
	dWorker.push_back(p);
	p = new Worker("��С��", "12345678956", 22, 15001);
	dWorker.push_back(p);
}
//����
void WorkerByGroup(std::deque<Worker*>& dWorker,
	std::multimap<int, Worker*>& mapWorkeyGroup)
{
	srand(static_cast<int>(time(NULL)));
	for (auto it = dWorker.begin(); it != dWorker.end(); it++)
	{
		int id = rand() % 2 + 1;
		switch (id)
		{
		case 1:
			mapWorkeyGroup.insert(std::make_pair(SalDep, *it));
			break;
		case 2:
			mapWorkeyGroup.insert(std::make_pair(TechDep, *it));
			break;
		default:
			break;
		}
	}
}
//��ӡ�����ŷ�����Ϣ
void PrintWorkerByGroup(std::multimap<int, Worker*>& mapWorkeyGroup)
{
	auto it = mapWorkeyGroup.find(SalDep);
	if (it != mapWorkeyGroup.end())
	{
		std::cout << "���۲���Ա����Ϣ" << std::endl;
		size_t num = mapWorkeyGroup.count(SalDep);
		for (size_t i = 0; i < num && it != mapWorkeyGroup.end(); i++)
		{
			if (((*it).second) != NULL)
			{
				((*it).second)->show();
			}
			it++;
		}
	}
	it = mapWorkeyGroup.find(TechDep);
	if (it != mapWorkeyGroup.end())
	{
		std::cout << "�з�����Ա����Ϣ" << std::endl;
		int num = mapWorkeyGroup.count(TechDep);
		for (size_t i = 0; i < num && it != mapWorkeyGroup.end(); i++)
		{
			if (((*it).second) != NULL)
			{
				((*it).second)->show();
			}
			it++;
		}
	}
}
void DeleteWorker(std::deque<Worker*>& dWorker)
{
	while (!dWorker.empty())
	{
		Worker* p = dWorker.back();
		dWorker.pop_back();
		if (p != NULL)
		{
			delete p;
			p = NULL;
		}
	}
}

//����������Ϣ
void PrintInfo(std::pair<int, Worker*> p)
{
	std::cout << p.first << ":";
	p.second->show();
}

void PrintListMap(std::multimap<int, Worker*>& mapWorkeyGroup)
{
	for_each(mapWorkeyGroup.begin(), mapWorkeyGroup.end(), PrintInfo);
}

//MultiMap������ͬ��ֵ����
int main()
{
	std::deque<Worker*> dWorker;//�������Ա��
	std::multimap<int, Worker*> mapWorkeyGroup;//Ա��������Ϣ
	//����Ա��
	CreateWorker(dWorker);
	//����
	WorkerByGroup(dWorker, mapWorkeyGroup);
	//�����������
	//PrintListMap(mapWorkeyGroup);
	//��ӡ�����ŷ�����Ϣ
	PrintWorkerByGroup(mapWorkeyGroup);
	//�ͷ�Ա������
	DeleteWorker(dWorker);
	return 0;
}