//Name: Warren Fernandes
//Roll No: 8940
//WAP to implement Circular Queue of int using static memory allocation

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct{
int a[SIZE];
int front,rear;
}CQueue;

int isEmpty(CQueue q){
  if(q.front == -1)
    return 1;
  else
    return 0;
}
int isFull(CQueue q){
  if((q.rear+1)%SIZE == q.front)
    return 1;
  else
    return 0;
}
void cenqueue(CQueue *c, int x){
  if(isFull(*c) == 1)
    printf("Queue Full\n");
  else{
    c->rear = (c->rear+1)%SIZE;
    c->a[c->rear] = x;
    if(c->front == -1)
      c->front = 0;
  }
}
int cdequeue(CQueue *d){
  int data;
  if(isEmpty(*d) == 1){
    printf("Queue Empty\n");
    return -1;
  }
  else{
    data = d->a[d->front];
    if(d->front == d->rear)
      d->front = d->rear = -1;
    else
      d->front = (d->front+1)%SIZE;
    return data;
  }
}
void display(CQueue q){
  int i;
  if(isEmpty(q))
    printf("Queue Empty\n");
  else{
    for(i=q.front;i!=q.rear;i=(i+1)%SIZE)
      printf("%d\t",q.a[i]);
    printf("%d\n",q.a[i]);
  }
}

int main() {
  CQueue cq1;
  int x,choice;
  char ch = 'y';
  cq1.front = cq1.rear = -1;

  while(ch == 'y' || ch == 'Y'){
    printf("Enter the choice: \n1.Enqueue \n2.Dequeue \n3.Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter element to be inserted :\n");
        scanf("%d",&x);
        cenqueue(&cq1,x);
        break;
      case 2:
        x = cdequeue(&cq1);
        printf("The removed element is %d\n",x);
        break;
      case 3:
        printf("Queue Contents\n");

        display(cq1);

    }
    printf("Do u want to continue: ");
    scanf(" %c",&ch);
  }
  return 0;
}

/******************OUTPUT************************/
/*

Enter the choice:
1.Enqueue
2.Dequeue
3.Display
1
Enter element to be inserted :
10
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
1
Enter element to be inserted :
20
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
3
Queue Contents
10  20
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
2
The removed element is 10
Do u want to continue: Y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
1
Enter element to be inserted :
30
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
1
Enter element to be inserted :
40
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
1
Enter element to be inserted :
60
Queue Full
Do u want to continue: Y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
3
Queue Contents
20  30  40
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
2
The removed element is 20
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
2
The removed element is 30
Do u want to continue: y
Enter the choice:
1.Enqueue
2.Dequeue
3.Display
2
The removed element is 40
Do u want to continue: n
*/
