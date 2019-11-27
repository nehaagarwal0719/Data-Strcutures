
#include <stdio.h> 
#include <stdlib.h> 
#include<stdbool.h> 
#include<string.h>
#include<stdarg.h>

struct CQNode{
    int data;
    struct CQNode *next;
}*cfront = NULL,*crear = NULL;
 
void c_enQueue(int item){
    if(cfront==NULL || crear==NULL)
    {
        //create a new node
        struct CQNode *cqnew_node;
        cqnew_node = (struct CQNode*)malloc(sizeof(struct CQNode));
 
        cqnew_node->data = item;
        cqnew_node->next = NULL;
 
        //as it is single node, both pointers
        //point to the same node
        cfront = cqnew_node;
        crear = cqnew_node;
    }
    else
    {
        struct CQNode *cqnew_node;
        cqnew_node = (struct CQNode*)malloc(sizeof(struct CQNode));
        cqnew_node->data = item;
        crear->next = cqnew_node;
        
        cqnew_node->next = cfront;
        crear = cqnew_node;
    }
}
void c_deQueue(){
	if(cfront==NULL)
		printf("Queue is Empty! Cannot delete element\n");
  else if(cfront ==crear){
      cfront=crear=NULL;
  }
	else{
      struct CQNode *temp = cfront;
      cfront = cfront -> next;
      //printf("\nDeleted element: %d\n", temp->data);
      free(temp);
      }
}

void cqu_traverse(){
    if(cfront == NULL){
	printf("Empty\n");
    }
    else{
    	struct CQNode *temp = cfront;
    	do{
        	printf("%d--->",temp->data);
        	temp = temp->next;
        }   while(temp != crear->next);
        printf("[front] ");
    }
}
 
void cqu_front(){ 
	if(cfront == NULL){
		printf("NULL\n");
	}
	else{
	struct CQNode *temp = cfront;
	printf("%d\n",temp->data);
	}
} 
 
void CQueue(char str[], int num, ...){

  va_list valist;

  char ins[] = "INS";
  char del[] = "DEL";
  char top[] = "FRT";


  //Insertion
  if(strcmp(str,ins) == 0){
    
         va_start(valist, num);
         for(int i=0;i<num;i++){
             c_enQueue(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Inserting %d element(s) \n",num );
	         printf("Queue: ");
          cqu_traverse();
  }


   //Deletion
   if(strcmp(str,del) == 0){
         va_start(valist, num);
          for(int i=0;i<num;i++){
             c_deQueue();
          }
	  printf("\nDeleted %d elements from the Queue\n",num);
          va_end(valist); 
          //printf("Deleting %d element(s) \n",num);
	      printf("Queue: ");
          cqu_traverse();
    }

    //Front Element
   if(strcmp(str,top) == 0){      
          printf("\nFront element is ");
          cqu_front();
     }
}
/*int main(){
    //inserting four elements 
    CQueue("INS",6,10,20,30,40,50,60);
   //deleting two elements 
    CQueue("DEL",2);
    //front element of queue
    CQueue("FRT",0);
    return 0;
}
*/