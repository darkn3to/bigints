#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
void main() {
    char int1[100], int2[100];
    int val, choice;
    printf("Enter the first integer: ");
    scanf("%s", int1);
    printf("Enter the second integer: ");
    scanf("%s", int2);
    n *bint1=create(), *bint2=create(), *tail1, *tail2;
    char *ptr=int1;
    while (*ptr) { 
        val=(*ptr)-'0';
        tail1=newnode(&bint1, val);
        ptr++;
    }
    ptr=int2;
    while (*ptr) {
        val=(*ptr)-'0';
        tail2=newnode(&bint2, val);
        ptr++;
    }
    printf("Enter the operation you want to perform: \n1. Addition\n2. Subtraction\n3. Multiply\n4. Division\n5. Modulus\n6. Exit\n");
    scanf("%d", &choice);
    int i;
    switch (choice) {
        case 1:
            int *sum=addbigints(&tail1, &tail2);
            printf("Sum: ");
            i=0;
            while (sum[i]!=-69) printf("%d", sum[i++]);
            printf("\n");
            goto bye;
        break;
        case 2: 
            int *diff=subbigints(&tail1, &tail2);
            i=0;
            if (isNegative(5)) printf("Diff: -");
            else printf("Diff: ");
            while (diff[i]!=-69) printf("%d", diff[i++]);
            printf("\n");
            goto bye;
        break;
        case 3:
            n *result=NULL, *second=tail2;
            int carry=0, c=0;
            while (second) {
                n *tmp=NULL, *first=tail1;
                while (first) {
                    int s=(first->data*second->data)+carry;
                    insertAtHead(&tmp, s);
                    first=first->prev;
                }
                for (int i=0; i<c; i++) insertAtTail(&tmp, 0);
                second=second->prev;
                c++;
                result=addtwolists(result, tmp);
            }
            printf("Product: ");
            display(result);
            goto bye;
        break;
        case 4:
            printf("Quotient: ");
        break;
        case 5:
            long long int mod=modbigints(&bint1, &bint2);
            printf("Remainder: %lld\n", mod);
            goto bye;
        break;
        case 6:
            exit(0);
        default: printf("Invalid input!\n");
    }
    bye:
    printf("Press Enter to continue...");
    getchar();
    getchar();
}