#include <stdio.h>
#include "linkList.h"
int main() {
    //��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    link *p = initLink();
    display(p);
    printf("�ڵ�4��λ�ò���Ԫ��5��\n");
    p = insertElem(p, 5, 4);
    display(p);
    printf("ɾ��Ԫ��3:\n");
    p = delElem(p, 3);
    display(p);
    printf("����Ԫ��2��λ��Ϊ��\n");
    int address = selectElem(p, 2);
    if (address == -1) {
        printf("û�и�Ԫ��");
    }
    else {
        printf("Ԫ��2��λ��Ϊ��%d\n", address);
    }
    printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
    p = amendElem(p, 3, 7);
    display(p);
    return 0;
}
