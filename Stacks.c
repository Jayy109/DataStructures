//
//  main.c
//  Stack Linked List C
//
//  Created by Jaydev Jangiti on 09/05/2020.
//  Copyright © 2020 Jaydev Jangiti. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode,*top=NULL;

    void push(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
int pop()
{
    int z;
    temp=top;
    z=top->data;
    top=top->next;
    free(temp);
    return z;
}
void display()
{
    temp=top;
    while(temp!=0)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}
int peek()
{
    return top->data;
}
int main()
{
    push(97);
    push(9);
    push(67);
    push(37);
    push(9732);
    push(174);
    push(47);
    display();
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("New List \n");
    display();


}

