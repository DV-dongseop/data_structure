#include <stdio.h>
#include <stdlib.h>

//다음과 같은 구조의 이중 연결 리스트에서 아래의 프로그램을 완성하시오.

typedef struct DlistNode {
  int data;
  struct DlistNode *llink;
  struct DlistNode *rlink;
} DlistNode;

void dinsert_last(DlistNode*head , int data) // 리스트의 가장 뒤에 추가
{
    DlistNode *node = (DlistNode *)malloc(sizeof(DlistNode));
    node->data=data;
    node->rlink=head;
    node->llink=head->llink;
    head->llink->rlink=node;
    head->llink=node;
}

int get_circular_length(DlistNode *phead) // 이중 연결 리스트의 길이를 계산
{
    int cnt = 0;
    for (DlistNode *p = phead->rlink; p != phead; p = p->rlink) // print 함수 코드 일부
    {
        cnt++; // 카운트 up
    }
    return cnt;
}

void print_list(DlistNode *phead) //이중 연결 리스트 출력 함수
{
    DlistNode*p;
    for (p = phead->rlink; p != phead; p = p->rlink)
    {
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

int main(void) 
{
    DlistNode *head = (DlistNode *) malloc(sizeof(DlistNode));
    head->rlink = head->llink = head;
    dinsert_last(head, 10);
    dinsert_last(head, 20);
    dinsert_last(head, 30);
    dinsert_last(head, 40);
    print_list(head);
    /*   츨력 내용 10  -> 20  ->30 ->40 */
    printf("%d\n", get_circular_length(head)); // 4를 반환
} 

//앞의 프로그램에서 dinsert_last(), print_list(), get_circular_length()  함수를 완성 하시오.