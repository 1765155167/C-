#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include "Player.h"
#include <algorithm>
//��ί��ְ���(sort�㷨����)
//����5��ѡ��(�������÷�)��10����ί��5��ѡ�ֽ��д��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȥƽ���÷�
//���÷ֶ�5��ѡ�ֽ�������

//����ѡ��
void createPlayer(std::vector<Player>& v)
{
	std::string nameSpeed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	{
		std::string name = "ѡ��";
		Player p(name + nameSpeed[i], 0);
		v.push_back(p);
	}
}

//���
void printVal(int val)
{
	std::cout << val << " ";
}

void setScorePlayer(Player& p)
{
	int score;
	std::deque<int> deq;
	//srand(static_cast<int>(time(NULL)));
	for (size_t i = 0; i < 10; i++)
	{
		deq.push_back(rand()%41 + 60);//������
	}
	//�������з�����������
	sort(deq.begin(), deq.end());//Ĭ����������
	//std::for_each(deq.begin(), deq.end(), printVal);
	//std::cout << std::endl;
	//ȥ����߷�����ͷ�
	deq.pop_back();
	deq.pop_front();
	//��ƽ����
	int sum = 0;
	for (std::deque<int>::iterator begin = deq.begin();
		begin != deq.end(); begin++)
	{
		sum += *(begin);
	}
	p.setScore(sum / deq.size());
}

void setScore(std::vector<Player>& v)
{
	for (std::vector<Player>::iterator it = v.begin();
		it != v.end(); it++)
	{
		setScorePlayer(*it);
	}
}


//������ӡ
class Comrelue {
public:
	bool operator()(Player& a, Player& b) const {
		return a.getScore() > b.getScore();
	}
};

bool comrelue(Player& a, Player& b)
{
	if (a.getScore() > b.getScore())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printInfo(Player& p)
{
	p.show();
}

void printPlayer(std::vector<Player>& v)
{
	//�����Ӵ�С
	sort(v.begin(), v.end(), Comrelue());
	std::for_each(v.begin(), v.end(), printInfo);
}

int main()
{
	std::vector<Player> v;
	createPlayer(v);
	setScore(v);
	printPlayer(v);
	return 0;
}