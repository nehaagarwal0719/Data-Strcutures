#include <stdio.h> 
#include <stdlib.h> 
#include<stdbool.h> 
#include<string.h>
#include<stdarg.h>

struct QNode
{
   int data;
   struct  QNode *next;
}*front = NULL,*rear = NULL;

void enQueue(int item){
   struct QNode *qnew_node;
   qnew_node = (struct QNode*)malloc(sizeof(struct QNode));
   qnew_node->data = item;
   qnew_node -> next = NULL;
   if(front == NULL)
      front = rear = qnew_node;
   else{
      rear -> next = qnew_node;
      rear = qnew_node;
   }
   //printf("\nInsertion is Success!!!\n");
}
void deQueue(){
   if(front == NULL)
      printf("Queue is Empty! Cannot delete element\n");
   else{
      struct QNode *temp = front;
      front = front -> next;
      //printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void qu_traverse(){
   if(front == NULL)
      printf("Empty\n");
   else{
   	struct QNode *temp = front;
   	while(temp->next != NULL){
		printf("%d--->",temp->data);
		temp = temp -> next;
	}
   printf("%d--->NULL",temp->data);
   }
}

void qu_front(){ 
	if(front == NULL){
		printf("NULL\n");
	}
	else{
	struct QNode *temp = front;
	printf("%d",temp->data);
	}
} 

void queue(char str[], int num, ...){

  va_list valist;

  char ins[] = "INS";
  char del[] = "DEL";
  char len[] = "LEN";
  char search[] = "SRC";
  char top[] = "TOP";


  //Insertion
  if(strcmp(str,ins) == 0){
    
         va_start(valist, num);
         for(int i=0;i<num;i++){
             enQueue(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Inserting %d element(s) \n",num );
	       printf("Queue: ");
          qu_traverse();
  }


   //Deletion
   if(strcmp(str,del) == 0){
         va_start(valist, num);
          for(int i=0;i<num;i++){
             deQueue();
          }
	  printf("\nDeleted %d elements from the Queue",num);
          va_end(valist); 
          //printf("Deleting %d element(s) \n",num);
	  printf("\nQueue: ");
          qu_traverse();
    }

    //Top Element
   if(strcmp(str,top) == 0){      
          printf("\nFront element is ");
          qu_front();
     }
}
/*int main(){
  //QUEUE
   printf("QUEUE\n");
   //Creating an Empty Queue
   queue("INS",0);
   //Inserting 3 Elements in Queue from the end
   queue("INS",3,1,2,3);
   //Returning the Top element
   queue("TOP",0);
   //Deleting 2 Elements from the Queue from the beginning 
   queue("DEL",2);
   
   return 0;

}*/