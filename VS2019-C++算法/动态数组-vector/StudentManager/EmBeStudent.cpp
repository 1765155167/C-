#include "EmBeStudent.h"

EmBeStudent::EmBeStudent()
{
}

EmBeStudent::EmBeStudent(std::string mName, std::string mId, std::string mProfession, std::string mClass)
{
	this->mName = mName;
	this->mId = mId;
	this->mClass = mClass;
	this->mProfession = mProfession;
}

EmBeStudent::~EmBeStudent()
{
}

void EmBeStudent::show()
{
	std::cout << "����:" << this->getName()
		<< "ѧ��:" << this->getId()
		<< "רҵ:" << this->getProfession()
		<< "�༶" << this->getClass() << std::endl;
}
