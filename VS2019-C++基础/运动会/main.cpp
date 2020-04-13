/*
һ��һ�ȵĿ����˶�����Ҫ��ʼ�ˣ�ͬѧ��������һ������뿪��������ʾ����ȫ���ĵ�Ͷ�뵽����������Ŀ�С�UED���ʦС����Ȼû�вμ�������Ŀ�������������ش���Ϊ���������ӵĶӳ�������Ҫ��ÿ����Ŀ��Ϊ������ͬѧ�Ǽ���������
��Ϊ�˶������Ŀ�ڶ࣬�ܶ���Ŀ��ͬһʱ���ͬʱ�����š���Ϊ�����ӳ���С����Ҫ�������¹���
����ͬʱ�����������Ŀ��������
��ÿ��������Ŀ���͵�ʱ�����볬����Ŀʱ����һ�룬ÿ��������Ŀֻ�ܼ���һ��
������Ŀ�Ŀ�ʼ�ͽ���ʱ�䶼�����㣬�����Ŀ���е�һ����Ҫ�뿪��Ҳֻ��ѡ�������뿪
�����������ڸ���������Ŀ���������л��ѵ�ʱ��
���С�����һ���㷨������֪����������Ŀ�ճ̵�ǰ���£������Ƿ�����ÿ��������Ŀ��Ϊ������ͬѧ�Ǽ��͡�
˵����
���������Ŀʱ��Ϊ2������ʱ����һ��Ϊ2;
���������Ŀʱ��Ϊ3������ʱ����һ��Ϊ2;
���������Ŀʱ��Ϊ4������ʱ����һ��Ϊ3��

��������:
�������1+N�� ��һ������һ������N, 1 <= N <= 10����ʾ����Ҫ�μӶ��ٸ����ۻ� ����N�У�ÿ�����뿪ʼ�ͽ���ʱ�䣬��Ϊ�������ÿո�ָ���0 <= startTime < endTime <= 24

�������:
�������һ�� ���С���ܹ��μ�ȫ�����ۻᣬ����1 ���С�첻�ܹ��μ�ȫ�����ۻᣬ����-1
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//��ȡ��̿�ʼʱ��
int getFinishTime(pair<int, int> p) {
	return p.second - (p.second - p.first) / 2 - 1;
}

//��ȡ��Ҫʱ��
int getNeedTime(pair<int, int> p) {
	return (p.second - p.first) / 2 + 1;
}

class MyCompare :public std::binary_function<pair<int, int>, pair<int, int>, bool>
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)const
	{
		if (getFinishTime(a) != getFinishTime(b))
			return getFinishTime(a) < getFinishTime(b);
		else return a.first < b.first;
	}
};

struct MyPrint {
	void operator()(pair<int, int> p) {
		cout << p.first << " " << p.second << endl;
	}
};

void right(vector<pair<int, int>> table) {
	int start = table[0].first;
	int num = table.size();
	for (int i = 0; i < num; i++) {
		if (start > getFinishTime(table[i]))
		{
			cout << -1 << endl;
			break;
		}
		if (i == num - 1)
		{
			cout << 1 << endl;
			break;
		}
		int end = start + getNeedTime(table[i]);
		start = max(end, table[i + 1].first);
	}
	return;
}
int main() {
	int N = 0;
	vector<pair<int, int>> v;//[����ʼʱ�䣬 ]
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	std::sort(v.begin(), v.end(), MyCompare());
	//for_each(v.begin(), v.end(), MyPrint());
	right(v);
	return 0;
}