#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int item;
    struct node_s* next;
} node_t;

node_t* reverse_list(node_t* head)
{
    node_t* n=head;
    head=NULL;
    while(n) {
        node_t* m = n;
        n = n->next;
        m->next = head;
        head = m;
    }
    return head;
}

node_t* create_list_head(node_t* head, int n)
{
    node_t* p;
    srand(time(0));
    head = (node_t*)malloc(sizeof(node_t*));
    head->next = NULL;
    int i = 0;
    for(i = 0; i<n; i++)
    {
        p = (node_t*)malloc(sizeof(node_t*));
        p->item =  rand()%100+1;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

int main()
{
    node_t* head;
    head = create_list_head(head, 2);
    node_t* p = head;
    while (p) {
        printf("%d,", p->item);
        p = p->next;
    }
    head = reverse_list(head);
    p = head;
    while (p) {
        printf("%d,", p->item);
        p = p->next;
    }
}
