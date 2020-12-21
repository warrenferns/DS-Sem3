//Name- Warren Fernandes
//Roll No.- 8940
//Implementation of LinkedList

#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node{
  int a;
  struct node *next;
}Node;

typedef struct{
  Node *start;
}LL;

void insatbeg(LL *lptr, int x){
  Node *n = (Node *)malloc(sizeof(Node));
  n->a = x;
  n->next = lptr->start;
  lptr->start = n;
}

void insatend(LL *lptr, int x){
  Node *m;
  Node *n = (Node *)malloc(sizeof(Node));
  n->next = NULL;
  n->a = x;
  if(lptr->start == NULL)
    lptr->start = n;
  else{
    m = lptr->start;
    while(m->next!=NULL){
      m = m->next;
    }
    m->next = n;
  }
}

int lengthofLL(LL l){
  Node *q;
  int len=0;
  q = l.start;
  while(q!=NULL){
    len++;
    q = q->next;
  }
  return len;
}

void insatn(LL *lptr, int x, int n){
  Node *m;
  Node *o = (Node *)malloc(sizeof(Node));
  o->a = x;
  if(n == 0){
    insatbeg(lptr, x);
    return;
  }
  if(n < 0 || n > lengthofLL(*lptr)){
    printf("Invalid");
    return;
  }
  else{
    int i;
    m = lptr->start;
    for(i=1; i<n;i++){
      m = m->next;
    }
    o->next = m->next;
    m->next = o;
  }

}

void delnode(LL *lptr, int x){
  Node *q = lptr->start;
  Node *p = NULL;
  while(q!=NULL){
    if(q->a == x)
      break;
    p = q;
    q = q->next;
  }
  if(q == NULL)
    printf("Data to be deleted not found");
  else{
    if(lptr->start == q)
      lptr->start = q->next;
    else
      p->next = q->next;
    free(q);
  }
}

void reverse(LL *lptr){
  Node *p,*q,*r;
  p = NULL;
  q = lptr->start;
  while(q!=NULL){
    r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
  lptr->start = p;
}

void concate(LL *l1, LL l2){
  Node *c;
  if(l2.start == NULL)
    return;
  if(l1->start == NULL)
    l1->start = l2.start;
  else{
    c = l1->start;
    while(c->next != NULL)
      c = c->next;
    c->next = l2.start;
  }
}

void display(LL l){
  Node *d;
  d = l.start;
  while(d!=NULL){
    printf("%d\t",d->a);
    d = d->next;
  }
}

void display_alt(Node *q){
    if(q==NULL){
        return;
    }
    printf("%d ", q->a);
    if(q->next==NULL)
        return;
    display_alt(q->next->next);
}


int main() {
  LL l1,l2,l3;
  l1.start=NULL;
  l2.start=NULL;
  l3.start=NULL;
  int choice,ele,n,i,dat[SIZE];
  do
  {
    printf("\nEnter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
      printf("Enter the element to be added at the beginning of the linked list :");
      scanf("%d",&ele);
      insatbeg(&l1,ele);
    break;
    case 2 :
      printf("Enter the element to be added at the end of the linked list :");
      scanf("%d",&ele);
      insatend(&l1,ele);
    break;
    case 3 :
      printf("After how many nodes do you want to enter the new node: ");
      scanf("%d",&n);
      printf("Enter the element to be added at position %d of the linked list :",n);
      scanf("%d",&ele);
      insatn(&l1,ele,n);
    break;
    case 4 :
      printf("The Linkedlist is :\n");
      display(l1);
    break;
    case 5 :
      printf("Enter the data to be deleted:");
      scanf("%d",&ele);
      delnode(&l1,ele);
    break;
    case 6 :
      printf("The total nodes in the linked list are : %d\n",lengthofLL(l1));
    break;
    case 7 :
      reverse(&l1);
      display(l1);
    break;
    case 8 :
      printf("Enter the length of linked list you want to concate: ");
      scanf("%d", &n);
      printf("Enter %d values: ", n);
      for(i=0;i<n;i++){
        scanf("%d",&dat[i]);
        insatend(&l2, dat[i]);
      }
      concate(&l1,l2);
      printf("The concatenated linked list is :\n");
      display(l1);
    break;
    case 9:
      exit(0);
      break;
    case 10:
        display_alt(&l1.start);


    default:
      printf("Invalid choice");
      exit(0);

    }

  }
  while (choice<10);
  return 0;
}


/*Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
1
Enter the element to be added at the beginning of the linked list :10

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
2
Enter the element to be added at the end of the linked list :15

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
1
Enter the element to be added at the beginning of the linked list :5

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
2
Enter the element to be added at the end of the linked list :20

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
4
The Linkedlist is :
5   10  15  20
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
3
After how many nodes do you want to enter the new node: 2
Enter the element to be added at position 2 of the linked list :12

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
4
The Linkedlist is :
5   10  12  15  20
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
7
20  15  12  10  5
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
8
Enter the length of linked list you want to concate: 3
Enter 3 values: 3
2
1
The concatenated linked list is :
20  15  12  10  5   3   2   1
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
6
The total nodes in the linked list are : 8

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
7
1   2   3   5   10  12  15  20
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
5
Enter the data to be deleted:12

Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
4
The Linkedlist is :
1   2   3   5   10  15  20
Enter your choice : 1.Insert at beg LL1 2.Insert at end 3. Insert after n nodes 4.Display 5.Delete Data 6.Count Nodes 7.Reverse 8.Concat 2 LL 9.Exit
9*/
