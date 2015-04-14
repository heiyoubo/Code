#include <iostream>

typedef struct node
{
    int data;
    struct node *next;
} node;

/*
 * 从无头单链表中删除节点
 * 一个指针指向单链表中间一个节点，请将该节点从单链表中删除
 */
void DeleteRandomNode(node *pCurrent)
{
    assert(pCurrent != NULL);
    node *pNext = pCurrent->next;
    if (pNext != NULL) {
        pCurrent->next = pNext->next;
        pCurrent->data = pNext->data;
        delete pNext;
    }
}

/*
 * 编写一个函数，给定一个链表的头指针，要求只遍历一次，
 * 将单链表中元素顺序反转过来
 *
 */


int main()
{
}
