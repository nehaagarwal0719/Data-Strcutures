#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include<stdbool.h> 
#include<string.h>
#include<stdarg.h>

struct sNode
{
	int data;
	struct sNode* next;
};

struct sNode* slist;

struct sNode* savail_node() 
{ 
	struct sNode* snew_Node;
    snew_Node=(struct sNode*)malloc(sizeof(struct sNode));
   if(snew_Node!=0){
    	return snew_Node;
    }
    else
    {
    	printf("Overflow");
    	return 0;
    }
} 

void push(int item) 
{ 
	struct sNode* temp=savail_node();
     temp->data=item;
     temp->next=slist;
     slist=temp;
     printf("%d pushed to stack\n", item); 
} 

int pop() 
{ 
    struct sNode* temp;
    int popped;

    if(slist==NULL){
      printf("Stack already empty");
      exit(0);
    }
    
    popped=slist->data;
    temp=slist->next;  
    free(slist);      
    slist = temp ;  
    return popped;
}

int peek() 
{ 
    if(slist==0)
      printf("Empty");
    return slist->data; 
} 
void st_traverse(){

  struct sNode* ptr=slist;
   if(slist==0)
    printf("Empty");
   else{
  while(ptr!=NULL){
    printf("%d\n", ptr->data);
    ptr=ptr->next;
  }
}
}

void stack(char str[], int num, ...){

  va_list valist;

  char ins[] = "INS";
  char del[] = "DEL";
  char len[] =  "LEN";
  char srch[] = "SEARCH";
  char top[]="TOP";


  //Insertion
  if(strcmp(str,ins) == 0){
    
         va_start(valist, num);
         for(int i=0;i<num;i++){
             push(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Inserting %d element(s) \n",num );
          st_traverse();
  }


   //Deletion
   if(strcmp(str,del) == 0){
         va_start(valist, num);
          for(int i=0;i<num;i++){
             pop(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Deleting %d element(s) \n",num );
          st_traverse();
    }

    //Top Element
    if(strcmp(str,top) == 0){
         va_start(valist, num);
          for(int i=0;i<num;i++){
             peek(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Top element is ");
          st_traverse();
    }
  
}



/*int main() 
{   
    stack("INS", 3,10,20,30);
    stack("DEL",2);
    stack("TOP",0);     
    return 0; 
} */