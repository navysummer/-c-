#include "seqlist.h"

int main(void)
{
    seqlist L;
    InitList(&L);
    ;
    int i,k=0;
    Datatype e;
    Datatype ee;
    Datatype eee;
    Datatype eeee;
    for (i = 1; i <=LIST_SIZE+1; i++)
    {
        if (!ListInsert(&L, i, i*i))
            printf("��%d����%d�����б�\n",i, L.data[i-1]);
    }
    printf("the length of list is  %d\n", ListLength(L));
    

    k = 5;
    Getelem(L, k-1, &e);
    printf("��%d����Ϊ%d\n",k, e);
    if (ListEmpty(L))
        printf("list is not empty\n");
    printf("%d�������%d\n", 25, Locateelem(L, 25));
    Priorelem(L, 4,&ee);
    printf("%d��ǰһ��Ԫ������%d\n", 4, ee);
    Nextelem(L, 256, &eee);
    printf("%d�ĺ�һ��Ԫ������%d\n", 256, eee);
    Listdelete(&L,1,&eeee);
    printf("ɾ��Ԫ����%d\n", eeee);
    printf("the length of list is  %d\n", ListLength(L));
    DestroyList(&L);
    getchar();
    return 0;

}
