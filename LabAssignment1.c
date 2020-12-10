//NAME - WARREN FERNANDES
//ROLL NO - 8940
//Implementation of Stack using array

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct
{
  float a[SIZE];
  int tos;
}Stack;

//checks whether stack is empty or not
int isEmpty(Stack *p)
{
  if(p->tos == -1)
    return 1;
   else
    return 0;
}
//checks whether the stack is full or not
int isFull(Stack *p)
{
  if(p->tos == SIZE-1)
    return 1;
   else
    return 0;
}

//pushes the element into stack
void push(Stack *ph, float x)
{
  if(isFull(ph)==1)
    printf("Stack overflow\n");
  else
  {
    ph->tos++;
    printf("The pushed element is %0.3f ",x);
    ph->a[ph->tos] = x;
  }
}

//pops the tos from the stack
float pop(Stack *pp)
{
  if(isEmpty(pp)==1)
    printf("Stack Overflow\n");
  else
    return pp->a[pp->tos--];
}

//returns the peek element
float peek(Stack s)
{
  if(s.tos == -1)
    printf("Stack empty");
  else
    return s.a[s.tos];
}

//displays the elements
void display(Stack s)
{
	int i;
   for(i = s.tos; i>=0; i--)
    printf("%0.3f\t", s.a[i]);
}

int size(Stack s)
{
  return (s.tos+1);
}

 int main()
 {
   Stack s;
   s.tos = -1;
   int option=0;
   float x,data;
   char ch = 'y';

   while(ch =='Y' || ch == 'y')
   {
     ch = 'n';
     printf("\nEnter the choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size\n");
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
        printf("The top of stack element is %0.3f", peek(s));
       break;
       case 5:
        printf("The size of the stack is %d", size(s));
       break;
     }
      printf("\nDo you want to continue?(Y/n): ");
      scanf("%s",&ch);
   };
 }

 // *********OUTPUT TEST CASES**************
 /*
 Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
1
Enter the element to push: 10
The pushed element is 10.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
1
Enter the element to push: 20
The pushed element is 20.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
1
Enter the element to push: 30
The pushed element is 30.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
1
Enter the element to push: 40
Stack overflow

Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
3
The elements of the Stack are 30.000000 20.000000   10.000000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
4
The top of stack element is 30.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
2
The poped element is 30.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
5
The size of the stack is 2
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
2
The poped element is 20.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
2
The poped element is 10.000
Do you want to continue?(Y/n): y

Enter the choice: 1)Push    2)Pop   3)Display   4)Peek  5)Size
2
Stack Overflow
The poped element is 0.000
Do you want to continue?(Y/n): n

*/
