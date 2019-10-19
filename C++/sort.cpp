#include <ctime>
#include <string>
#include <cstdlib>
#include <queue>
#include <pthread.h>
#include <csignal>
#include <windows.h>
#include <iostream>

using namespace std;

template<class T>
void Swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

/*ð������*/
void BriSort(int data[], int len)
{
	bool flag = false;//ʵ��ӱ�־�����������������ʱ�����ˣ����ڽ��������Ǻܶ����ݵĽṹ��ʱ�ӱ�־����������ʱ��

	for(int i = 0; i < len - 1; i++)
	{
		flag = false;
		for(int j = 0; j < len - i - 1; j++)
		{
			if(data[j] < data[j + 1])
			{
				swap(data[j], data[j + 1]);
				flag = true;
			}
		}
		if(flag == false)
		{
			break;
		}
	}
}

/*��������*/
void InsertSort(int data[],int len)
{
	int begin = 1;
	int i = 0;
	while(begin < len)
	{
		int key = data[begin];
		for(i = begin - 1; i >= 0; i--)
		{
			if(key <= data[i])
			{
				data[i + 1] = key;
				break;
			}
			data[i + 1] = data[i];
		}
		if(i < 0)
			data[0] = key;
		begin++;
	}
}

/*ѡ������*/
void selectionSort(int data[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int max = i;
		for(int j = i; j < len; j++)
		{
			if(data[j] > data[max])/*����[i-len]���ֵ����*/
			{
				max = j;
			}
		}
		swap(data[i], data[max]);
	}
}

/*ϣ������*/
void shellSort(int data[], int len)
{
	for(int gap = len/2; gap > 0; gap /= 2)
	{
		for(int i = 0; i < gap; i++)/*i�� [i:len-i]����gap���в�������*/
		{
			int begin = i + gap;//Ҫ�����Ԫ�ص�λ��
			while(begin < len - i)
			{
				int j = 0;
				int key = data[begin];
				for(j = begin - gap; j >= i; j -= gap)
				{
					if(key <= data[j])//�����������
					{
						data[j + gap] = key;
						break;
					}
					data[j + gap] = data[j];//Ԫ������ƶ�gapλ
				}
				if(j < i)
					data[i] = key;
				begin += gap;
			}
		}
	}
}

/*�鲢����*/
template<class T>
void MergeSortTemp(T data[], int start, int end, T temp[])
{
	int len = end - start + 1;
	int mid = (end - start) / 2;
	if (len == 0) {
		return ;
	}
	if (len == 1) {
		return ;
	}
	MergeSortTemp(data, start, mid, temp);
	MergeSortTemp(data, mid + 1, end, temp);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= end)
	{
		if(data[i] < data[j])
		{
			temp[k++] = data[j++];
		}else
		{
			temp[k++] = data[i++];
		}
	}
	while(i <= mid)
	{
		temp[k++] = data[i++];
	}
	while(j <= end)
	{
		temp[k++] = data[j++];
	}
	for(int i = 0; i < k; i++)
	{
		data[start + i] = temp[i];
		cout << temp[i] << " ";
	}
	cout << endl;
}

template<class T>
void MergeSort(T data[], T len)
{
	T temp[len];
	MergeSortTemp(data, 0, len - 1, temp);
}

/*������*/
void adjustHeap(int * arrs, int p, int len){
    int curParent = arrs[p]; //���׽ڵ�
    int child = 2 * p + 1;   //����
    while(child < len){      //û�к���
        if(child + 1 < len && arrs[child] < arrs[child+1]){//���Һ��Ӳ����Һ���ֵ��������
            child++;    //�ϴ��ӵ��±�
        }
        if(curParent < arrs[child]){
            arrs[p]=arrs[child];
            //û�н�curParent��ֵ����������Ϊ��Ҫ����������
            //����亢�����д�ģ������ƣ�curParent��Ҫ�������ơ�
            p=child;
            child=2*p+1;
        }
        else
            break;
    }
    arrs[p]=curParent;
}

void heapSort(int * arrs, int len){
    //�����ѣ�����ײ�ĸ��ڵ㿪ʼ
    for(int i = len/2 -1; i>=0; i--)
        adjustHeap(arrs, i, len);
    for(int i = len -1; i>=0; i--){
        int maxEle = arrs[0];
        arrs[0] = arrs[i];
        arrs[i] = maxEle;

        adjustHeap(arrs, 0, i);
    }
}



#define MAX 10//5938
#define PRINT
int main(void)
{
	time_t c_end, c_start;
	int data[MAX];
	int len = 0;

	srand((unsigned)time(NULL));
	for(int i = 0; i < MAX; i++)
	{
		data[i] = rand()%100;
	}
	len = sizeof(data) / sizeof(data[0]);

#ifdef PRINT
	for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
#endif

	c_start = clock();
	//BriSort(data, len);//ð������ num:20000 time:1496ms O(n^2)
	//InsertSort(data, len);//�������� num:20000 time:300ms O(n^2)
	//selectionSort(data, len);//ѡ������ num:20000 time:557ms O(n^2)
	//shellSort(data, len);//ϣ������ num:20000 * 10 time:35ms O(n^logn)
	//heapSort(data, len);//������ num:20000 * 10 time:44ms O(n^logn)
	MergeSort(data, len);
	c_end =clock();

	cout << difftime(c_end, c_start) << endl;

#ifdef PRINT
	for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
#endif
	
	return 0;
}
