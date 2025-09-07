#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node node;

node* makeNode(int x)//tao node moi
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head)//duyet DSLK
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(node *head)//dem so node
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void pushFront(node **head, int x)//them node vao dau
{
    node *newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(node **head, int x)//them node vao cuoi
{
    node *newNode = makeNode(x);
    if((*head) == NULL)
    {
        (*head) = newNode; return;
    }
    node *temp = (*head);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(node **head, int x, int k)//chen
{
    int n = size(*head);
    if(k < 1 || k > n + 1)
        return;
    if(k == 1)
        pushFront(head, x);
    else if(k == n + 1)
        pushBack(head, x);
    else
    {
        node *newNode = makeNode(x);
        node *temp = (*head);
        for(int i = 1; i<k-1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void popFront(node **head)//xoa o dau
{
    if((*head) == NULL)
        return;
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
}

void popBack(node **head)//xoa o cuoi
{
    if((*head) == NULL)
        return;
    node *temp = (*head);
    if(temp->next == NULL)
    {
        *head = NULL; free(temp); return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void erase(node **head, int k)//xoa
{
    int n = size(*head);
    if(k < 1 || k > n)
        return;
    if(k == 1)
    {
        popFront(head);
        return;
    }
    node *temp = (*head);
    for(int i = 1; i<k-1; i++)
        temp = temp->next;
    node *victim = temp->next;
    temp->next = victim->next;
    free(victim);
}

void sort(node **head)
{
    for(node *i = (*head); i != NULL; i = i->next)
    {
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next)
        {
            if(min->data > j->data)
                min = j;
        }
        int temp = min->data;
        min->data = i->data;
        i->data = temp;
    }
}

node* reverse(node *head)//dao nguoc
{
    if(head == NULL)
        return head;
    node *prevNode = NULL, *nextNode = NULL, *currNode = head;
    while(currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

int main()
{
    node *head = NULL;
    while(1)
    {
        printf("----------------------\n");
        printf("1. Them vao dau\n");
        printf("2. Them vao cuoi\n");
        printf("3. Them vao giua\n");
        printf("4. Xoa o dau\n");
        printf("5. Xoa o cuoi\n");
        printf("6. Xoa o giua\n");
        printf("7. Sap xep\n");
        printf("8. Dao nguoc\n");
        printf("9. Duyet\n");
        printf("0. Ket thuc\n");
        printf("----------------------\n");
        int choice; scanf("%d", &choice);
        if(choice == 1)
        {
            int x; scanf("%d", &x);
            pushFront(&head, x);
        }
        else if(choice == 2)
        {
            int x; scanf("%d", &x);
            pushBack(&head, x);
        }
        else if(choice == 3)
        {
            int x, k; scanf("%d%d", &x, &k);
            insert(&head, x, k);
        }
        else if(choice == 4)
        {
            popFront(&head);
        }
        else if(choice == 5)
        {
            popBack(&head);
        }
        else if(choice == 6)
        {
            int k; scanf("%d", &k);
            erase(&head, k);
        }
        else if(choice == 7)
        {
            sort(&head);
        }
        else if(choice == 8)
        {
            head = reverse(head);
        }
        else if(choice == 9)
        {
            duyet(head);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}