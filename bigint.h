#ifndef BIGINT_H
#define BIGINT_H
typedef struct node {
    int data;
    struct node *next, *prev;
}n;
n *create();
n *create2(int val);
n *newnode(n **bint, int val);
n *reverseList(n *head);
int isNegative(int n);
void insertAtHead(n **head, int value);
void insertAtTail(n **head, int value);
void display();
int *reverseArray(int *arr, int size);
void addDigits(n **result, int d1, int d2, int *carry);
n *addtwolists(n *first, n *second);
int *addbigints(n **tail1, n **tail2);
int *subbigints(n **tail1, n **tail2);
long long int modbigints(n **head1, n **head2);
#endif