#ifndef __DLIST_H__
#define __DLIST_H__
#include<cstdio>
#include<malloc.h>
#include<assert.h>
typedef int ElemType;
typedef struct Node {
  ElemType data;
  struct Node *prio;
  struct Node *next;
}Node,*PNode;
typedef struct List {
  PNode first;
  PNode last;
  size_t size;
}List;
void InitDlist(List *list);//��ʼ��˫����
void push_back(List *list, ElemType x);//��˫�����ĩβ����Ԫ��
void push_front(List *list, ElemType x);//��˫�����ͷ������Ԫ��
void show_list(List *list);//��ӡ˫����
void pop_back(List *list);//ɾ��˫��������һ��Ԫ��
void pop_front(List *list);//ɾ��˫����ĵ�һ��Ԫ��
void insert_val(List *list, ElemType val);//������Ԫ�ز��뵽˫�����У�Ҫ���ʱ˫�����е�����Ԫ��˳�����У�
Node* find(List *list, ElemType x);//����˫����������ֵΪx�Ľ��
int length(List *list);//��˫����ĳ���
void delete_val(List *list, ElemType x);//��ֵɾ��˫�����е�ĳ������Ԫ��
void sort(List *list);//��˫�����������
void reverse(List *list);//����˫����
void clear(List *list);//���˫����
void destroy(List *list);//�ݻ�˫����
//�Ż�
Node* _buynode(ElemType x);//�������
#endif


