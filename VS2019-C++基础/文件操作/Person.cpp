#include "Person.h"
#include <fstream>

void write()
{
	using namespace std;
	const char* filePath = "C:\\Users\\17651\\Desktop\\C++��ߴ���\\Person";
	Person p(20, "�����");
	p.show();
	std::ofstream osm(filePath, ios::out | ios::binary);
	if (!osm) {
		cout << "�ļ�" << filePath << "��ʧ��" << endl;
		return;
	}
	osm.write((const char*)&p, sizeof(Person));
	osm.close();
	return ;
}

void read()
{
	using namespace std;
	const char* filePath = "C:\\Users\\17651\\Desktop\\C++��ߴ���\\Person";
	Person p;
	ifstream ism(filePath, ios::in | ios::binary);
	if (!ism) {
		cout << "�ļ�" << filePath << "��ʧ��" << endl;
		return;
	}
	ism.read((char*)&p, sizeof(Person));
	p.show();
	ism.close();
	return ;
}

int main()
{
	//write();
	//read();
	std::cout << sizeof(Person) << std::endl;
	return 0;
}