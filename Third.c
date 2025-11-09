#include <stdio.h>
#define max 5
int q[max];
int front=-1;
int rear=-1;
void enq(int);
void deq();
void display();

int main()
{
    int ele;
 printf("Enter 1 to insert an element.\nEnter 2 to delete the element.\nEnter 3 to display the queue status.\nEnter 4 to exit the code.\n");
 int ch,start = 1;
 do
 {
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
         printf("enter the element:");
         scanf("%d",&ele);
         enq(ele);
         break;

     case 2:
         deq();
         break;

     case 3:
         display();
         break;

     case 4:
         start=0;
         break;
   }

 }while(start);
 return 0;
}
void enq(int x)
{
 if(rear==max-1)
 {
   printf("Queue is full.");
 }
 else if(rear==-1 && front==-1)
 {
   front=0;
   rear=0;
   q[rear]=x;
 }
 else if(rear==max-1 && front!=0)
 {
   rear=0;
   q[rear]=x;
 }
 else
 {
   rear=rear+1;
   q[rear]=x;
 }
}
void deq()
{
 if(front==-1 && rear==-1)
 {
   printf("Queue is empty.");
 }
 else if(front==rear)
 {
   printf("Deleting %d\n",q[front]);
   front=-1;
   rear=-1;
 }
 else if(front==max-1)
 {
   printf("Deleting %d\n",q[front]);
   front=0;
 }
 else
 {
   printf("Deleting %d\n",q[front]);
   front=front+1;
 }
}
void display()
{
  if(rear==-1 && front==-1)
  {
    printf("Queue is empty.");
  }
  else
  {
    int i;
    for(i=front;i<=rear;i++)
    {
      printf("%d",q[i]);
    }
  }
}