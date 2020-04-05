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
��ʼ��������
�������������һ���յ����Ա��ɹ�����0������-1*/

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
��ʼ���������Ա�L�Ѿ�����
�������:�������Ա�L���ɹ�����0������-1*/

int DestroyList(seqlist *L)
{
    while (!L->data)
    free(L->data);
    L->length = 0;
    printf("destroy finish\n");
    return 0;

}

/*ListEmpty(L)
��ʼ���������Ա�L�Ѿ�����
�����������LΪ�ձ�����0�����򷵻�-1*/

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
��ʼ���������Ա�L�Ѿ�����
������������ر�ĳ��ȣ�ʧ�ܷ���-1*/


int ListLength(seqlist L)
{

    return L.length;
}

/*Getelem(L,i,&e)
��ʼ���������Ա�L�Ѿ�����1=<i<=LIST_SIZE
�����������e����L�е�i��Ԫ�ص�ֵ�ɹ�����0������-1*/
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
��ʼ���������Ա�L�Ѿ�����
�������������L�е�һ����e��ȵ����кţ���Ԫ�ز����ڣ��򷵻�-1*/
int Locateelem(seqlist L, Datatype e)
{

    int i;//������������ֱ����β��û�ҵ�����-1
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i+1;
    }
    return -1;
}
/*Priorelem(L,cur_e,&pre_e)
��ʼ���������Ա��Ѿ�����
�����������cur_e��L�е�Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��Ԫ�أ����򷵻ش���-1���ɹ�����0*/
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
��ʼ���������Ա��Ѿ�����
�����������cur_e��L�е�Ԫ�أ��Ҳ������һ��������next_e��������ǰ��Ԫ�أ����򷵻ش���-1���ɹ�����0*/
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
��ʼ���������Ա�L�Ѿ�����
�����������L�е�i��λ��֮ǰ�����µ����ݣ�����1������0�ɹ���-1����*/
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
    q = &L->data[i - 1];//����λ��
    Datatype *p = NULL;
    for (p = &L->data[L->length - 1]; p >= q;p--)//�����һ��λ�ÿ�ʼ���ΰ�ǰ���ֵ��ֵ����һ��λ��
    {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    L->listsize += LIST_INCREMENT;
    return 0;


}
/*Listdelete(&L,i,&e)
��ʼ���������Ա�L����
���������ɾ��L�����Ϊi��Ԫ�أ�������ֵ��e����,�ɹ�����0��������-1*/

int Listdelete(seqlist *L, int i, Datatype *e)
{

    if (i<1 || i>L->listsize)
    {
        printf("postion error:\n");
        return -1;
    }
    Datatype *q = NULL;
    Datatype *p = NULL;
    q = &L->data[i - 1];//ɾ��Ԫ��λ��
    *e = *q;
    p = &L->data[L->length - 1];//��βλ��
    while (q <= p)
    {
        *q = *(q + 1);
        q++;
    }
    L->length--;
    return 0;
}
