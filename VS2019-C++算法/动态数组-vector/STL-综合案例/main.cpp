#include "Player.h"
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <time.h>

//����24��ѡ�� ��Ŵ�1001 - 10024
void CreatePlayer(std::map<int, Player*>& mPlist, std::vector<int>& v)
{
	for (int i = 0; i < 24; i++)
	{
		std::string name = "ѡ��";
		int id = 1001 + i;
		name += 'A' + i;
		mPlist.insert(std::make_pair(id, new Player(name)));
		v.push_back(id);
	}
}
//��ǩ
void Sortitlon(std::vector<int>& v)
{
	std::random_shuffle(v.begin(), v.end());
}

//�����÷���
double getScore(Player* p)
{
	std::deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(rand()%50 + 51);//51 - 100
	}
	sort(d.begin(),d.end());//Ĭ������
	//ȥ����߷�����ͷ�
	d.pop_back();
	d.pop_front();
	int sum = std::accumulate(d.begin(),d.end(),0);
	return sum * 1.0 / d.size();//ȥƽ����
}

//�������ؽ����б�
struct mycompare
{
	bool operator()(double a, double b)const {
		return a > b;
	}
};
std::vector<int> Game(std::map<int, Player*>& mPlist, std::vector<int>& v, int a)
{
	std::multimap<double, int, mycompare> mGroup;//<���������>
	int groupIndex = 0;
	std::vector<int> Promotion;
	//��ί���
	for (auto it = v.begin(); it != v.end(); it++)
	{
		Player* p = mPlist[*it];
		double score = getScore(p);
		p->setScore(a, score);
		mGroup.insert(std::make_pair(score, *it));
		groupIndex++;
		if (groupIndex%6 == 0)
		{
			int index = 0;
			for (auto mit = mGroup.begin(); mit != mGroup.end(); mit++)
			{
				if (index < 3)//ȡǰ����
				{
					Promotion.push_back((*mit).second);
				}
				else
				{
					break;
				}
				index++;
				//std::cout << "����:" << (*mit).first << ":" << "���:" << (*mit).second << std::endl;
			}
			mGroup.clear();
		}
	}
	return Promotion;
}
//��ӡ��������
void PrintPromotionList(std::map<int, Player*>& mPlist, std::vector<int> v, int i)
{
	std::cout << "����ѡ����������:" << std::endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		Player* p = mPlist[*it];
		if (i == 1)
		{
			std::cout << p->getName() << "��һ��:" << p->getScore(1) << std::endl;
		}
		if (i == 2)
		{
			std::cout << p->getName() << "�ڶ���:" << p->getScore(2) << std::endl;
		}
		if (i == 3)
		{
			std::cout << p->getName() << "��һ��:" << p->getScore(1) 
				<< "�ڶ���:" << p->getScore(2)
				<< "������:" << p->getScore(3) << std::endl;
		}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::map<int, Player*> mPlist;
	std::vector<int> v1, v2, v3, v4;
	CreatePlayer(mPlist, v1);
	Sortitlon(v1);//��һ�ֳ�ǩ
	v2 = Game(mPlist, v1, 1);//��һ�ֱ���
	PrintPromotionList(mPlist, v2, 1);
	Sortitlon(v2);//�ڶ��ֳ�ǩ
	v3 = Game(mPlist, v2, 2);//�ڶ��ֱ���
	PrintPromotionList(mPlist, v3, 2);
	Sortitlon(v3);//�����ֳ�ǩ
	v4 = Game(mPlist, v3, 3);//�����ֱ���
	PrintPromotionList(mPlist,v4, 3);
}
