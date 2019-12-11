#pragma once
#include <iostream>
typedef struct NODE {
	struct NODE* next;
}Node;

typedef void(*PRINTCIRCLELIST)(Node*);
typedef bool(*COMPAIR)(Node*, Node*);

class CircleList
{
public:
	CircleList();
	~CircleList();
	void push_pos(Node* data, int pos);//ָ��λ�ò���
	void traversal(PRINTCIRCLELIST print);
	void remove(Node* data, COMPAIR compair);
private:
	Node head;
	int len;
};

