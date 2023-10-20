#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
int isNegative(int n) {
    static int no=0;
    if (n==1) no=n;
    if (n==5) return no;
}
n *create() {
    n *temp=(n *)malloc(sizeof(n));
    temp->data=0;
    temp->prev=temp->next=NULL;
    return temp;
}
n *create2(int val) {
    n *nn=(n *)malloc(sizeof(n));
    nn->data=val;
    nn->next=NULL;
    return nn;
}
n *newnode(n **bint, int val) {
    n *temp=(n *)malloc(sizeof(n));
    n *curr;
    temp->data=val;
    temp->next=NULL;
    if (!(*bint)->data) {
        (*bint)=temp;
        curr=temp;
        curr->prev=NULL;
    }
    else {
        n *dummy=curr;
        curr->next=temp;
        curr=curr->next;
        curr->prev=dummy;
    }
    return curr;
}
n* reverseList(n* head) {
    n* prev=NULL, *curr=NULL, *next=head;
    while (next) {
        prev = curr;
        curr = next;
        next = next->next;
        curr->next = prev;
    }
    return curr;
}
void insertAtHead(n** head, int value) {
    n* newNode = create2(value);
    if (*head) {
        newNode->next = *head;
        *head = newNode;
    } else {
        *head = newNode;
    }
}
void insertAtTail(n** head, int value) {
    n* newNode = create2(value);
    if (*head) {
        n* tmp = *head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        *head = newNode;
    }
}
void display(n *bint) {
    while (bint) {
        printf("%d", bint->data);
        bint=bint->next;
    }
    printf("\n");
}
int *reverseArray(int* arr, int size) {
    int *reversed = (int *)malloc((size+1) * sizeof(int)), i=0;
    for (; i < size; i++) {
        reversed[i] = arr[size - i - 1];
    }
    if (isNegative(5)==1) reversed[i-1]=reversed[i-1]+1;
    reversed[i]=-69;
    return reversed;
}
void addDigits(n** result, int d1, int d2, int* carry) {
    int tmp = d1 + d2 + *carry;
    int sum = tmp % 10;
    *carry = tmp / 10;
    insertAtTail(result, sum);
}
n *addtwolists(n *first, n *second) {
    n *result=NULL;
    first=reverseList(first);
    second=reverseList(second);
    int carry=0;
    while (first && second) {
        addDigits(&result, first->data, second->data, &carry);
        first=first->next;
        second=second->next;
    }
    while (first != NULL) {
        addDigits(&result, first->data, 0, &carry);
        first=first->next;
    }
    while (second != NULL) {
        addDigits(&result, 0, second->data, &carry);
        second=second->next;
    }
    if (carry != 0) insertAtTail(&result, carry);
    result = reverseList(result);
    return result;
}
int *addbigints(n **tail1, n **tail2) {
    int carry=0, i=0, max=0;
    n *temp1=*tail1;
    n *temp2=*tail2;
    while (temp1 || temp2) {
        if (temp1) temp1=temp1->prev;
        if (temp2) temp2=temp2->prev;
        max++;
    }
    int *sum=(int *)malloc((max+1)*sizeof(int));
    while ((*tail1) || (*tail2)) {
        int LSB1=(*tail1)?(*tail1)->data:0;
        int LSB2=(*tail2)?(*tail2)->data:0;
        int digitSum=LSB1+LSB2+carry;
        carry=digitSum/10;
        sum[i++]=digitSum % 10;
        if (*tail1) *tail1=(*tail1)->prev;
        if (*tail2) *tail2=(*tail2)->prev;
    }
    if (carry > 0) sum[i++] = carry;
    int *result=reverseArray(sum, max);
    return result;
}
int *subbigints(n **tail1, n **tail2) {
    int max=0, i=0;
    n *temp1=*tail1;
    n *temp2=*tail2;
    while (temp1 || temp2) {
        if (temp1) temp1=temp1->prev;
        if (temp2) temp2=temp2->prev;
        max++;
    }
    int borrow=0, *diff=(int *)malloc((max+1)*sizeof(int));
    while (*tail1 || *tail2) {
        int LSB1=(*tail1)?(*tail1)->data:0;
        int LSB2=(*tail2)?(*tail2)->data:0;
        int digitDiff;
        if (LSB1-borrow>=LSB2) {
            digitDiff=LSB1-LSB2-borrow;
            borrow=0;
        }
        else {
            digitDiff=10+LSB1-LSB2-borrow;
            borrow=1;
        }
        diff[i++]=digitDiff;
        if (*tail1) *tail1=(*tail1)->prev;
        if (*tail2) *tail2=(*tail2)->prev;
    }
    if (borrow==1) {
        isNegative(1);
        i=0;
        while (i!=max) {
            diff[i]=9-diff[i];
            i++;
        }
    }
    int *result=reverseArray(diff, max);
    return result;
}
long long int modbigints(n **head1, n** head2) {
    long long int num2=0, res=0;
    while (*head2) {
        num2=num2*10+(*head2)->data;
        *head2=(*head2)->next;
    }
    while (*head1) {
        res=(res*10+(*head1)->data)%num2;
        *head1=(*head1)->next;
    }
    return res;
}