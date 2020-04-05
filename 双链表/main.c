#include "Dlist.h"
void main() {
  List mylist;
  InitDlist(&mylist);
  ElemType item;
  Node *p = NULL;
  int select = 1;
  while (select) {
    printf("*******************************************\n");
    printf("*[1] push_back    [2] push_front  *\n");
    printf("*[3] show_list    [4] pop_back   *\n");
    printf("*[5] pop_front    [6] insert_val  *\n");
    printf("*[7] find       [8] length    *\n");
    printf("*[9] delete_val    [10] sort     *\n");
    printf("*[11] reverse     [12] clear     *\n");
    printf("*[13*] destroy     [0] quit_system  *\n");
    printf("*******************************************\n");
    printf("请选择：>>");
    scanf("%d", &select);
    if (select == 0) break;
    switch (select) {
    case 1:
      printf("请输入要插入的数据（-1结束）:>");
      while (scanf("%d", &item), item != -1) {
        push_back(&mylist, item);
      }
      break;
    case 2:
      printf("请输入要插入的数据（-1结束）:>");
      while (scanf("%d", &item), item != -1) {
        push_front(&mylist, item);
      }
      break;
    case 3:
      show_list(&mylist);
      break;
    case 4:
      pop_back(&mylist);
      break;
    case 5:
      pop_front(&mylist);
      break;
    case 6:
      printf("请输入要插入的数据:>");
      scanf("%d", &item);
      insert_val(&mylist, item);
      break;
    case 7:
      printf("请输入要查找的数据:>");
      scanf("%d", &item);
      p = find(&mylist, item);
      if (p == NULL)
        printf("要查找的数据在单链表中不存在！\n");
      break;
    case 8:
      printf("单链表的长度为%d\n", length(&mylist));
      break;
    case 9:
      printf("请输入要删除的值:>");
      scanf("%d", &item);
      delete_val(&mylist, item);
      break;
    case 10:
      sort(&mylist);
      break;
    case 11:
      reverse(&mylist);
      break;
    case 12:
      clear(&mylist);
      break;
      //case 13:
      //destroy(&mylist);
      //break;
    default:
      printf("选择错误,请重新选择！\n");
      break;
    }
  }
  destroy(&mylist);
}


