#include <iostream>
#include <ctime>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*ð��������*/
void mySort(int data[], int len)
{
	//data: 1 5 6 8 4 1 2 
	//i = 0 ʱð��[0~len-1] [0~len-1 -i] 
	//i = 1 ʱð��[0~len-2] [0~len-1 -i] 

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (data[j] < data[j + 1])/*�õ���j+1 ��ôj + 1�ķ�Χ���ܳ���len - i - 1 */
			{
				swap(data[j], data[j + 1]);
			}
		}
	}
}

#define MAX 20
int main()
{
	int data[MAX];
	srand((unsigned)time(NULL));//�����������
	for (size_t i = 0; i < MAX; i++)
	{
		data[i] = rand() % 100;//���鸳ֵ��100���ڵ��������
	}
	std::cout << "����ǰdataΪ��";
	for (size_t i = 0; i < MAX; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	mySort(data, MAX);

	std::cout << "�����dataΪ��";
	for (size_t i = 0; i < MAX; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}