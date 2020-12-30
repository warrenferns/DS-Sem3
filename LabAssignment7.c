//Name - Warren Fernandes
//Roll No. - 8940
//Dynamic Implementation of Queue
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  float data;
  struct node *next;
}Node;

typedef struct{
  Node *front;
  Node *rear;
}DQueue;

int isEmpty(DQueue q){
  if(q.front == NULL)
    return 1;
  else
    return 0;
}

void enqueue(DQueue *e,float x){
  Node *p=(Node*)malloc(sizeof(Node));
  p->data=x;
  p->next=NULL;
  if(e->rear==NULL)
    e->rear=e->front=p;
  else{
    e->rear->next=p;
    e->rear=p;
  }
  printf("The enqueued element is %0.3f", p->data);
}

float dequeue(DQueue *d){
  Node *q;
  float x;
  if(isEmpty(*d)){
    printf("Queue is empty");
    return -1;
  }
  else{
    q = d->front;
    x = q->data;
    d->front = d->front->next;
    if(d->front == NULL)
      d->rear = NULL;
    free(q);
    return x;
  }
}
void display(DQueue p){
  Node *q;
  printf("\nThe elements of the queue are: \n");
  for(q = p.front; q != NULL; q = q->next)
    printf("%0.3f\t",q->data);
}

int size(DQueue p){
  Node *q;
  int count=0;
  for(q = p.front; q != NULL; q = q->next)
    count++;
  return count;
}
float peek(DQueue p){
  //Node *q;
  //q = p.front;
  return p.front->data;
}
int main(){
  DQueue q;
  int choice;
  float x;
  char ch = 'Y';
  q.front=NULL;
  q.rear=NULL;
  while(ch == 'y' || ch == 'Y'){
    printf("\nEnter your choice\n1.Enqueue  2.Dequeue  3.Display \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter Element to be queued: \n");
        scanf("%f",&x);
        enqueue(&q,x);
      break;

      case 2:
        printf("The dequeued element is %0.3f",dequeue(&q));
      break;

      case 3:
        display(q);
      break;

      case 4:
        printf("%d",size(q));
        break;
      case 5:
        printf("%0.3f",peek(q));
        break;
      default:
        printf("Invalid Choice");
        exit(0);
    }
    printf("\nDo you want to continue? (Y/n): ");
    scanf(" %c",&ch);
  }
  return 0;
}

////////OUTPUT///////////
/*
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
1
Enter Element to be queued:
10
The enqueued element is 10.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
1
Enter Element to be queued:
20
The enqueued element is 20.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
3
The elements of the queue are:
10.000  20.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
2
The dequeued element is 10.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
1
Enter Element to be queued:
30
The enqueued element is 30.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
3
The elements of the queue are:
20.000  30.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
2
The dequeued element is 20.000
Do you want to continue? (Y/n): y
Enter your choice
1.Enqueue  2.Dequeue  3.Display  4.Exit
3
The elements of the queue are:
30.000
Do you want to continue? (Y/n): n*/
