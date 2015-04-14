#include <iostream>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *List;

/*
 * 从无头单链表中删除节点
 * 一个指针指向单链表中间一个节点，请将该节点从单链表中删除
 */
void DeleteRandomNode(Node *pCurrent)
{
    assert(pCurrent != NULL);
    Node *pNext = pCurrent->next;
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
// pHead为链表的头指针，链表的第一个元素是pHead->next;
Node* reverseList(Node *pHead)
{
    //当前节点，初始化为第一个元素
    Node *pCurrent = pHead->next;
    //当前节点的前一个节点
    Node *pPrev = NULL;
    //当前节点的下一个节点
    Node *pNext = NULL;

    while (pCurrent != NULL) {
        pNext = pCurrent->next;
        pCurrent->next = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    
    pHead->next = pPrev;
    return pHead;
}

int main()
{
}
