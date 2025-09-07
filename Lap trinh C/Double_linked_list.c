#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *makeNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void pushFront(node **head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = (*head);
    if ((*head) != NULL)
        (*head)->prev = newNode;
    (*head) = newNode;
}

void pushBack(node **head, int x)
{
    node *newNode = makeNode(x);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }
    node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insert(node **head, int x, int k)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1)
    {
        pushFront(head, x);
    }
    else if (k == n + 1)
    {
        pushBack(head, x);
    }
    else
    {
        node *newNode = makeNode(x);
        node *temp = (*head);
        for (int i = 1; i < k - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void popFront(node **head)
{
    if (*head == NULL)
        return;
    node *temp = (*head);
    (*head) = (*head)->next;
    if ((*head) != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void popBack(node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = (*head);
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void erase(node **head, int k)
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
    if(victim->next != NULL)
        temp->next->prev = victim->prev;
    free(victim);
}

void reverse(node *head)
{
    if(head == NULL)
        return;
    while(head->next != NULL)
    {
        head = head->next;
    }
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
}

void sort(node **head)
{
    for(node *i = *head; i!=NULL; i = i->next)
    {
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next)
        {
            if(min->data > j->data)
                min = j;
        }
        int temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

int main()
{
    node *head = NULL;
    while (1)
    {
        printf("------------------------\n");
        printf("1. Them vao dau\n");
        printf("2. Them vao cuoi\n");
        printf("3. Them vao giua\n");
        printf("4. Xoa o dau\n");
        printf("5. Xoa o cuoi\n");
        printf("6. Xoa o giua\n");
        printf("7. Duyet nguoc\n");
        printf("8. Sap xep\n");
        printf("9. Duyet\n");
        printf("0. Ket thuc\n");
        printf("------------------------\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            int x;
            scanf("%d", &x);
            pushFront(&head, x);
        }
        else if (choice == 2)
        {
            int x;
            scanf("%d", &x);
            pushBack(&head, x);
        }
        else if (choice == 3)
        {
            int x, k;
            scanf("%d%d", &x, &k);
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
            reverse(head);
        }
        else if(choice == 8)
        {
            sort(&head);
        }
        else if (choice == 9)
        {
            duyet(head);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}