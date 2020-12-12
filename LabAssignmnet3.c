//Name: Warren Fernandes
//Roll No: 8940
//WAP to create Queue of Students getting admission in Fr. CRCE using static memory allocation

#include <stdio.h>
#define SIZE 20

typedef struct
{
  int reg_no;
  char branch[SIZE];
}Student;

typedef struct
{
  Student s[SIZE];
  int rear, front;
}Queue;

int isEmpty(Queue q){
  if(q.front == -1)
    return 1;
  else
    return 0;
}
int isFull(Queue q){
  if(q.rear == SIZE-1)
    return 1;
  else
    return 0;
}
void enqueue(Queue *q, Student a){
  if(isFull(*q)==1){
    printf("Queue is full.");
  }
  else{
    q->rear++;
    q->s[q->rear] = a;
    if(q->front == -1){
      q->front = 0;
    }
  }
}

Student dequeue(Queue *d){
  Student S;
  if(isEmpty(*d)==1){
    printf("Queue Empty");
    return S;
  }
  else{
    S = d->s[d->front];
    if(d->front == d->rear)
      d->front = d->rear = -1;
    else
      d->front++;
    return S;
  }
}

void display(Queue q){
  int i,j=1;
  if(!isEmpty(q)){
    printf("\nSr.No.\tReg. No.\tBranch");
    printf("\n------------------------------");
    for(i=q.front;i<=q.rear;i++){
      printf("\n%d\t%d\t\t%s",j++,q.s[i].reg_no,q.s[i].branch);
    }
    printf("\n------------------------------\n");
  }
  else
    printf("\nQueue Empty\n");
}

int main(){
  Queue q1;
  int menu;
  Student x;
  char ch = 'y';

  q1.front = q1.rear = -1;

  while(ch == 'Y'||ch == 'y'){
    printf("Enter your choice\n1)Enqueue\n2)Dequeue\n3)Display\n");
    scanf("%d",&menu);
    switch(menu){
      case 1:
        printf("Enter the details of the student");
        printf("\nReg. No. : ");
        scanf("%d",&x.reg_no);
        printf("Branch: ");
        scanf("%s",x.branch);
        enqueue(&q1,x);
        break;
      case 2:
        x = dequeue(&q1);
        printf("Removed student\nRegistration No. : %d\nBranch: %s\n",x.reg_no,x.branch);
        break;
      case 3:
        printf("Queue contents");
        display(q1);
        break;
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  }
  return 0;
}

/***************OUTPUT****************/
/*
Enter your choice
1)Enqueue
2)Dequeue
3)Display
1
Enter the details of the student
Reg. No. : 8940
Branch: Computer
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
1
Enter the details of the student
Reg. No. : 7845
Branch: Production
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
3
Queue contents
Sr.No.  Reg. No.    Branch
-----------------------------
1       8940        Computer
2       7845        Production
-----------------------------
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
2
Removed student
Registration No. : 8940
Branch: Computer
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
1
Enter the details of the student
Reg. No. : 9024
Branch: AI&DS
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
3
Queue contents
Sr.No.  Reg. No.    Branch
-----------------------------
1       7845        Production
2       9024        AI&DS
-----------------------------
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
2
Removed student
Registration No. : 7845
Branch: Production
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
3
Queue contents
Sr.No.  Reg. No.    Branch
-----------------------------
1       9024        AI&DS
-----------------------------
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
2
Removed student
Registration No. : 9024
Branch: AI&DS
Do you want to continue: y
Enter your choice
1)Enqueue
2)Dequeue
3)Display
3
Queue contents
Queue Empty
Do you want to continue: n
*/
