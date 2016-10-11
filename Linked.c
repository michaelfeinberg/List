#include <stdio.h>
#include <stdlib.h>

struct node { int n; struct node *next; };

void print_list(struct node *header){
  if(header==NULL){
    printf("%p\n",header);
  }else{
    while(header->next != NULL){
      struct node curr = *header;
      printf("%d, ",curr.n);
      header = header->next;
    }
    printf("%d\n",header->n);
  }
}

struct node * insert_front(int newData, struct node *header){
  struct node *newHead = (struct node *)malloc(sizeof(struct node));
  newHead->n = newData;
  newHead->next = header;
  return newHead;
}

struct node * free_list(struct node *header){
  
  struct node * holder;
  while(header->next != NULL){
    holder = header->next;
    free(header);
    header = holder;
  }
  free(header);
  return header;
}

int main(){
  struct node *head = (struct node *)malloc(sizeof(struct node));
  
  head->n = 0;
  head->next = NULL;
  //Check print_list : Working

  print_list(head);

  //Check insert_front: Working

  struct node *newHead = insert_front(15,head);
  print_list(newHead);  

  //Check free_list : Working
  struct node *freedList = free_list(newHead);
  print_list(freedList);
}
