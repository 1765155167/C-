#pragma once
#include <iostream>
//��������ࣨ�ӿڣ�
class AnimalInterFace {
public:
	virtual void voice() = 0;
	virtual ~AnimalInterFace();
};
//����мܹ�����
void Voice(AnimalInterFace* p);
void Voice(AnimalInterFace* p, bool d);