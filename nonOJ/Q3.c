#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
   int color;                 //completed
   struct Node *next;
} Node;
typedef Node *LinkedList;

void print(LinkedList l){
   while(l -> next != NULL){
      printf("%d ", l->color);
      printf("-> ");
      l = l->next;
   }
   printf("%d", l->color);
}

LinkedList insertNode(LinkedList l, int color_data){
   Node *n = (Node *)malloc(sizeof(Node));
   n->color = color_data;
   n->next = NULL;
   if(l==NULL)
      return n;
   Node *temp = l;
   while(temp->next != NULL){
      temp = temp->next;
   }
   temp->next = n;
   return l;
}

LinkedList delete(LinkedList l, int x){
   if(l==NULL)
      return l;
   if(l->color == x){
      Node *temp = l;
      l = l->next;
      free(temp);
      return l;
   }
   Node *prev = l;
   Node *temp = l;
   while(temp!=NULL && temp->color != x){
      prev = temp;
      temp = temp->next;
   }
   if(temp!=NULL){ // not reached null means there exists such node 
      prev->next = temp->next;
      free(temp);
   }
   return l;
}

LinkedList removeDuplicates(LinkedList l){
   Node *temp = l;
   while(temp != NULL && temp->next != NULL){
      Node *t = temp;
      while(t->next != NULL){
         if(t->next->color == temp->color){
            Node *del = t->next;
            t->next = del->next;
            free(del);
         }
         else
            t = t->next;
      }
      temp = temp->next;
   }
   return l;
}

int main(){
   int n, color;
   LinkedList l = NULL;
   scanf("%d", &n);
   for (int i = 0; i < n; i++){
      scanf("%d", &color);
      l = insertNode(l, color);
   }
   // print(l);
   // printf("\n");
   l = removeDuplicates(l);
   print(l);
   return 0;
}