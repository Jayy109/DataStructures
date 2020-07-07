//
//  main.c
//  Queues
//
//  Created by Jaydev Jangiti on 11/05/2020.
//  Copyright © 2020 Jaydev Jangiti. All rights reserved.
//


// MARK: Queue Using Array

#include <stdio.h>
#include <stdlib.h>
#define N 10
int Queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear==N-1)
        printf("STACK OVERFLOW");
    else if(front==-1 & rear==-1)
    {
        front=rear=0;
        Queue[rear]=x;
    }
    else{
        rear++;
        Queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 & rear==-1)
        printf("EMPTY QUEUE");
    else if(front==rear)
    {
        front = rear = -1;
        
    }
    else{
        printf("The Dequeud Element : %d",Queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 & rear==-1)
        printf("EMPTY QUEUE");
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d <-",Queue[i]);
    }
}
int peek()
{
    return Queue[front];<?<<<<><><I=
}

int main()
{
    printf("Hello \n");
    enqueue(89);
    enqueue(48);
    enqueue(23);
    enqueue(53);
    enqueue(33);
    display();
    dequeue();
    dequeue();
    display();
}
*/
// MARK: Queue Using Linked List

/*
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front,*rear,*temp,*newnode;
void Enqueue(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0 & rear==0)
        front=rear=newnode;
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void display()
{
    if(front==0 & rear ==0)
    {
        printf("QUEUE IS EMPTY");
    }
    else{
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ||",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}
void dequeue()
{
    temp = front;
    front=front->next;
    printf("Dequeued Element : %d \n",temp->data);
    free(temp);
}
void peek()
{
    printf("Peek : %d \n",front->data);
}
int main()
{
    Enqueue(5393);
    Enqueue(3193);
    Enqueue(313);
    Enqueue(1393);
    Enqueue(9324);
    Enqueue(423);
    display();
    dequeue();
    dequeue();
    display();
    Enqueue(432);
    Enqueue(69);
    display();
}

*/

// MARK: Circular Queue Using Arrays


#include <stdio.h>
#include <stdlib.h>
#define N 10
int Queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear==N-1)
        printf("STACK OVERFLOW");
    else if(front==-1 & rear==-1)
    {
        front=rear=0;
        Queue[rear]=x;
    }
    else if (((rear+1)%N)==front){
        printf("QUEUE IS FULL!");
    }
    else{
        rear=(rear+1)%N;
        Queue[rear]=x;
           }
}

void dequeue()
{
    if(front==-1 & rear==-1)
        printf("EMPTY QUEUE");
    else if(front==rear)
    {
        printf("The Dequeud Element : %d",Queue[front]);
        front = rear = -1;
        
    }
    else{
         front=(front+1)%N;
        printf("The Dequeud Element : %d",Queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    if(front==-1 & rear==-1)
        printf("EMPTY QUEUE");
    int i=0;
    while(i!=rear)
    {
        printf("%d <-",Queue[i]);
        i=(i+1)%N;
    }
}

/*


// MARK: Circular Queue Using Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front=0,*rear=0,*temp,*newnode;
void Enqueue(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(rear==0)
    {
        front=rear=newnode;
    rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void display()
{
    if(front==0 & rear ==0)
    {
        printf("QUEUE IS EMPTY");
    }
    else{
    temp=front;
    while(temp -> next!=front)
    {
        printf("%d ||",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}
void dequeue()
{
    temp = front;
    if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else{
    front=front->next;
        rear->next=front;
        
    free(temp);
    }
}
void peek()
{
    printf("Peek : %d \n",front->data);
}

int main()
{
    
    
    
}
