#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIST_SIZE 100
#define LIST_INCREMENT 10
typedef int Datatype ;
typedef struct{
    Datatype* data;
    int length;
    int listsize;
}seqlist;

/*InitList(&L)
初始条件：无
操作结果：构造一个空的线性表。成功返回0出错返回-1*/

int InitList(seqlist *L)
{
    L->data = (Datatype *)malloc(sizeof(Datatype)*LIST_SIZE);
    if (L->data == NULL)
        return -1;
    L->length = 0;
    L->listsize = LIST_SIZE;
    printf("initial finish\n");
    return 0;
}

/*DestroyList(&L)
初始条件：线性表L已经存在
操作结果:销毁线性表L。成功返回0出错返回-1*/

int DestroyList(seqlist *L)
{
    while (!L->data)
    free(L->data);
    L->length = 0;
    printf("destroy finish\n");
    return 0;

}

/*ListEmpty(L)
初始条件：线性表L已经存在
操作结果：若L为空表，返回0，否则返回-1*/

int ListEmpty(seqlist L)
{
    if (L.length == 0)
    {
        printf("list is empty\n");
        return 0;
    }
    else
        return -1;
}

/*ListLength (L)
初始条件：线性表L已经存在
操作结果：返回表的长度，失败返回-1*/


int ListLength(seqlist L)
{

    return L.length;
}

/*Getelem(L,i,&e)
初始条件：线性表L已经存在1=<i<=LIST_SIZE
操作结果：用e返回L中第i个元素的值成功返回0出错返回-1*/
int Getelem(seqlist L, int i, Datatype *e)
{
    if (i < 0 || i >LIST_SIZE)
    {
        printf("position error\n");
        return -1;
    }
    *e = L.data[i];
    return 0;

}
/*Locateelem(L,e)
初始条件：线性表L已经存在
操作结果：返回L中第一个和e相等的序列号，若元素不存在，则返回-1*/
int Locateelem(seqlist L, Datatype e)
{

    int i;//遍历整个链表，直到结尾若没找到返回-1
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i+1;
    }
    return -1;
}
/*Priorelem(L,cur_e,&pre_e)
初始条件：线性表已经存在
操作结果：若cur_e是L中的元素，且不是第一个，则用pre_e返回它的前驱元素，否则返回错误-1，成功返回0*/
int Priorelem(seqlist L, Datatype cur_e, Datatype *pre_e)
{
    int i = 0;
    if (cur_e == L.data[0])
        return -1;
    i = Locateelem(L, cur_e);
    if (i== -1)
        return -1;
    else
    {
        *pre_e = L.data[i - 2];
        return 0;
    }

}
/*Nextelem(L,cur_e,&next_e)
初始条件：线性表已经存在
操作结果：若cur_e是L中的元素，且不是最后一个，则用next_e返回它的前驱元素，否则返回错误-1，成功返回0*/
int Nextelem(seqlist L, Datatype cur_e, Datatype *next_e)
{
    int i = 0;
    if (cur_e == L.data[ListLength(L)-1])
        return -1;
    i = Locateelem(L, cur_e);
    if (i == -1)
        return -1;
    else
    {
        *next_e = L.data[i];
        return 0;
    }

}
/*ListInsert(&L,i,e)
初始条件：线性表L已经存在
操作结果：在L中第i个位置之前插入新的数据，表长加1，返回0成功，-1错误*/
int ListInsert(seqlist *L, int i, Datatype e)
{
    if (i<1 || i>L->listsize)
    {
        printf("position error\n");
        return -1;
    }
    if (L->length >= L->listsize)
        L->data = (Datatype *)realloc(L->data, (LIST_INCREMENT + LIST_SIZE)*sizeof(Datatype));
    if (!L->data)
    {
        printf("realloc error\n");
        return -1;
    }
    Datatype *q=NULL;
    q = &L->data[i - 1];//插入位置
    Datatype *p = NULL;
    for (p = &L->data[L->length - 1]; p >= q;p--)//从最后一个位置开始依次把前面的值赋值给后一个位置
    {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    L->listsize += LIST_INCREMENT;
    return 0;


}
/*Listdelete(&L,i,&e)
初始条件：线性表L存在
操作结果：删除L中序号为i的元素，并将其值由e带回,成功返回0，出错返回-1*/

int Listdelete(seqlist *L, int i, Datatype *e)
{

    if (i<1 || i>L->listsize)
    {
        printf("postion error:\n");
        return -1;
    }
    Datatype *q = NULL;
    Datatype *p = NULL;
    q = &L->data[i - 1];//删除元素位置
    *e = *q;
    p = &L->data[L->length - 1];//表尾位置
    while (q <= p)
    {
        *q = *(q + 1);
        q++;
    }
    L->length--;
    return 0;
}
