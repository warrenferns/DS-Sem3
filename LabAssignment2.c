//NAME - WARREN FERNANDES
//ROLL NO - 8940
//Parenthesis matching

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
typedef struct
{
  char a[SIZE];
  int tos;
}Stack;

//pushes the element into the stack
void push(Stack *ph, char x)
{
    ph->tos++;
    ph->a[ph->tos] = x;
}

//pops the element from the stack
char pop(Stack *pp)
{
    return pp->a[pp->tos--];
}

int main() {
  Stack s;
  s.tos = -1;
  char exp[SIZE];
  char data;
  int i;

    printf("\nEnter the expression: ");
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
      if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
      {
        push(&s,exp[i]);
      }
      if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
      {
        if(s.tos!=-1)
        {
          data = pop(&s);
          switch(exp[i])
          {
            case ')':
              if(data!='(')
              {
                printf("Corresponding '(' missing.");
                exit(0);
              }
            break;
            case '}':
              if(data!='{')
              {
                printf("Corresponding '{' missing.");
                exit(0);
              }
            break;
            case ']':
              if(data!='[')
              {
                printf("Corresponding '[' missing.");
                exit(0);
              }
             break;
          }
        }
        else
        {
          printf("Corresponding '(' or '{' or '[' missing.");
          exit(0);
        }
      }
      else
        continue;
    }
    if(s.tos!=-1)
      printf("Corresponding ')' or '}' or ']' missing.");
    else
      printf("Balanced expression.");

  return 0;
}

//*********OUTPUT TEST CASES****************
/*
1) Enter the expression: (a+{b-c}/d])
Corresponding '[' missing.

2)Enter the expression: (a/[b*c]+{d-e}
Corresponding ')' or '}' or ']' missing.

3)Enter the expression: ({a*b/c}-[d-e]+(f/g))
Balanced expression.
*/
