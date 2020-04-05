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
            printf("第%d个数%d插入列表\n",i, L.data[i-1]);
    }
    printf("the length of list is  %d\n", ListLength(L));
    

    k = 5;
    Getelem(L, k-1, &e);
    printf("第%d个数为%d\n",k, e);
    if (ListEmpty(L))
        printf("list is not empty\n");
    printf("%d的序号是%d\n", 25, Locateelem(L, 25));
    Priorelem(L, 4,&ee);
    printf("%d的前一个元素是是%d\n", 4, ee);
    Nextelem(L, 256, &eee);
    printf("%d的后一个元素是是%d\n", 256, eee);
    Listdelete(&L,1,&eeee);
    printf("删除元素是%d\n", eeee);
    printf("the length of list is  %d\n", ListLength(L));
    DestroyList(&L);
    getchar();
    return 0;

}
