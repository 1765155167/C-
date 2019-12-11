#pragma once

// С����ڵ�
typedef struct NODE
{
	struct NODE* next;	// ָ���̽ڵ��ָ��
}ListNode;

typedef struct LINKLIST
{
	ListNode head;
	int size;
}LinkList;

typedef void(*PRINTLIST)(ListNode*);

// ��ʼ��������һ���յ����Ա�L��
LinkList* InitList();
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(LinkList* L, int pos, ListNode* data);
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ�أ�����e������ֵ
void ListDelete(LinkList* L, int pos);
//����
int ListFind(LinkList* L, ListNode* data);
// �������Ա�L��Ԫ�ظ���
int ListLength(LinkList* L);
//��ӡ
void ListPrint(LinkList* L, PRINTLIST print);
//�ͷ�
void ListFree(LinkList* L);