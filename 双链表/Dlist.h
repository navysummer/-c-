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
void InitDlist(List *list);//初始化双链表
void push_back(List *list, ElemType x);//在双链表的末尾插入元素
void push_front(List *list, ElemType x);//在双链表的头部插入元素
void show_list(List *list);//打印双链表
void pop_back(List *list);//删除双链表的最后一个元素
void pop_front(List *list);//删除双链表的第一个元素
void insert_val(List *list, ElemType val);//将数据元素插入到双链表中（要求此时双链表中的数据元素顺序排列）
Node* find(List *list, ElemType x);//查找双链表中数据值为x的结点
int length(List *list);//求双链表的长度
void delete_val(List *list, ElemType x);//按值删除双链表中的某个数据元素
void sort(List *list);//对双链表进行排序
void reverse(List *list);//逆置双链表
void clear(List *list);//清除双链表
void destroy(List *list);//摧毁双链表
//优化
Node* _buynode(ElemType x);//创建结点
#endif


