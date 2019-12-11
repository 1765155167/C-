#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

// ��ʼ��������һ���յ����Ա�L��
LinkList* InitList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(LinkList* L, int pos, ListNode* data) {
	if (L == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > L->size)
	{
		pos = L->size;
	}
	//���Ҳ���λ��
	ListNode* p = &(L->head);
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	//�����½ڵ�
	data->next = p->next;
	p->next = data;
	L->size++;
}
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ��
void ListDelete(LinkList* L, int pos) {
	if (L == NULL)
	{
		return;
	}
	if (pos < 0 || pos > L->size)
	{
		return;
	}
	//���Ҳ���λ��
	ListNode* p = &(L->head);
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}
	//ɾ��
	p->next = p->next->next;
	L->size--;
}
//����
int ListFind(LinkList* L, ListNode* data) {
	if (L == NULL)
	{
		return -1;
	}
	ListNode* p = L->head.next;
	while (p != NULL)
	{
		if (p == data)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}
// �������Ա�L��Ԫ�ظ���
int ListLength(LinkList* L) {
	return L->size;
}
//��ӡ
void ListPrint(LinkList* L, PRINTLIST print) {
	if (L == NULL)
	{
		return;
	}
	//��ֵָ��
	ListNode* p = L->head.next;
	while (p != NULL)
	{
		print(p);
		p = p->next;
	}
}
//�ͷ�
void ListFree(LinkList* L) {
	if (L == NULL)
	{
		return;
	}
	free(L);
}

typedef struct Person {
	ListNode node;
	char name[10];
	int age;
}Person;

void fun(ListNode* p)
{
	Person* per = (Person*)p;
	printf("����:%s,����:%d\n", per->name, per->age);
}

int main()
{
	LinkList* L = InitList();
	Person p1, p2, p3, p4, p5;
	strcpy_s(p1.name, 4, "aaa");
	strcpy_s(p2.name, 4, "bbb");
	strcpy_s(p3.name, 4, "ccc");
	strcpy_s(p4.name, 4, "ddd");
	strcpy_s(p5.name, 4, "eee");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	ListInsert(L, 0, (ListNode*)(&p1));
	ListInsert(L, 0, (ListNode*)(&p2));
	ListInsert(L, 0, (ListNode*)(&p3));
	ListInsert(L, 0, (ListNode*)(&p4));
	ListInsert(L, 0, (ListNode*)(&p5));
	ListDelete(L, 0);
	ListPrint(L, fun);
	if (ListFind(L, (ListNode*)(&p5)))
	{
		printf("���ҳɹ�");
	}
	else
	{
		printf("����ʧ��");
	}
}