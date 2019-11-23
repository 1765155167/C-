// C++��ģ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <ctime>
#include "Vector.hpp"

void VectorTest()
{
	Vector<int, 21> vector;
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 0; i < 20; i++)
	{
		vector.back_push(rand() % 100);
	}
	vector.back_push(50);
	auto v = vector.begin();
	while (v != vector.end())
	{
		std::cout << *v << " ";
		v++;
	}
	std::cout << std::endl;
}
float data[1024];
template<typename T> T GetValue(int i)
{
	return static_cast<T>(data[i]);//��data[i]ǿ��ת����T��
}

/*ǿ��ת��*/
template< typename DstT, typename SrcT>
DstT c_style_cast(SrcT v)
{
	return (DstT)(v);
}

int main()
{
	using namespace std;
	VectorTest();
	cout << c_style_cast<int>(2.5) << endl;
	return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
