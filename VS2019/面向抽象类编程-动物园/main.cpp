#include "AnimalInterFace.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
	Cat* c = new Cat;
	Voice(c);
	Voice(new Dog, true);//ʹ�����ͷ�
	delete c;
}