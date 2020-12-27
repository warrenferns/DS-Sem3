//Name - Warren Fernandes
//Roll No. - 8940
//Dynamic Implementation of Stack
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  float a;
  struct node *next;
}Node;

typedef struct {
  Node *tos;
}DStack;

int isEmpty(DStack *p)
{
  if(p->tos == NULL)
    return 1;
   else
    return 0;
}

void push(DStack *ph, float x)
{
  Node *p = (Node *)malloc(sizeof(Node));
  p->a = x;
  if(isEmpty(ph)){
    ph->tos = p;
    p->next = NULL;
    printf("The pushed element is %0.3f ",x);
  }
  else{
    p->next = ph->tos;
    ph->tos = p;
    printf("The pushed element is %0.3f ",x);
  }
}

float pop(DStack *pp)
{
  Node *p;
  int x;
  if(isEmpty(pp)){
    printf("Stack Overflow\n");
    return -1;
  }
  else {
    p=pp->tos;
    x = p->a;
    pp->tos = p->next;
    free(p);
    return x;
  }
}

void display(DStack s){
  int i;
  Node *p;
  p = s.tos;
  while(p!=NULL){
    printf("%0.3f\t", p->a);
    p = p->next;
  }

}

int size(DStack s){
    int count = 0;
    Node *p;
    p = s.tos;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}
float peek(Node *p){
    return p->a;
}

 int main()
 {
   DStack s;
   s.tos = NULL;
   int option=0;
   float x,data;
   char ch = 'y';

   while(ch =='Y' || ch == 'y')
   {
     ch = 'n';
     printf("\nEnter the choice: 1)Push  2)Pop  3)Display 4)Size\n");
     scanf("%d",&option);
     switch(option)
     {
       case 1:
        printf("Enter the element to push: ");
        scanf("%f",&x);
        push(&s,x);
       break;
       case 2:
        data = pop(&s);
        printf("The poped element is %0.3f",data);
       break;
       case 3:
        printf("The elements of the Stack are ");
        display(s);
       break;
       case 4:
            printf("The size is %d",size(s));
            break;
       case 5:
            printf("Peek: %0.3f",peek(s.tos));
            break;
       default:
        printf("Invalid choice");
        exit(0);
     }
      printf("\nDo you want to continue?(Y/n): ");
      scanf(" %c",&ch);
   }
   return 0;
 }

/////////////OUTPUT/////////////////
/*
Enter the choice: 1)Push    2)Pop   3)Display
1
Enter the element to push: 10
The pushed element is 10.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
1
Enter the element to push: 20
The pushed element is 20.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
1
Enter the element to push: 30
The pushed element is 30.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
3
The elements of the Stack are 30.000    20.000  10.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
2
The poped element is 30.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
2
The poped element is 20.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
1
Enter the element to push: 40
The pushed element is 40.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
3
The elements of the Stack are 40.000    10.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display
2
The poped element is 40.000
Do you want to continue?(Y/n): n*/
