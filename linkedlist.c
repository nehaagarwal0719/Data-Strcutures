#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#include<string.h>
#include<stdarg.h>

//declaring Node
  struct Node{
  int data;
  struct Node* next;
   };

int pos;
struct Node* list =NULL;

//checking if memory is available 
 struct Node* avail_node(void){
   	  struct Node* node;

      node=(struct Node*)malloc(sizeof(struct Node));
      if(node!=0)
      	return node;
      
      else
      {
      	printf("Overflow");
      	return 0;
      }

 }

 //function to print the list
void ll_traverse(){

  struct Node* ptr;
  printf(" Linked list :");
  if(list==0)
    printf("Empty\n");
   else{
  ptr=list;
  while(ptr!=NULL){
    printf("%d->", ptr->data);
    ptr=ptr->next;
  }
  printf("NULL\n");
}
}

 //inserting a node 
 void ll_insert(int item)
 {
    struct Node* temp= avail_node();
    struct Node *ptr=list, *prev_node;
    int c=1;

    temp->data=item;

    //At the beginning
    if(pos==1){ 
    temp->next=list;
    list=temp;
   }
   
   //At the end
   else if(pos==-1){
    temp->next=NULL;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=temp;
   } 

 //function to insert after a node
   else{
    while(ptr->next!=NULL && c!=pos){
        c++;
        prev_node=ptr;
        ptr=ptr->next;
    }
    
    temp->data=item;
    temp->next=prev_node->next;
    prev_node->next=temp;
 }

}


 //Deletion
 void ll_delete(){
    int c=1;
    struct Node* temp;
    struct Node *ptr=list, *prev_node;

    if(list==NULL){
      printf("List already empty");
      return;
    }

    //deleted from beginning
    if(pos==1){
    temp=list->next;  //changed head
    free(list);       // free old head
    list = temp ; 
  }


   //Delete from end
   if(pos==-1){ 
     if(ptr->next==NULL){
        temp=list->next;
        list = temp ; 
     }

     while(ptr->next!=NULL  ){
        prev_node=ptr;
        ptr=ptr->next;
     }

      prev_node->next=NULL;
      free(ptr);
    
  }

  //delete_after
    else{

     if(ptr->next==NULL){
        temp=list->next;
        list = temp ; 
     }

     while(ptr->next!=NULL && c!=pos){
         c++;
        prev_node=ptr;
        ptr=ptr->next;
     }

      prev_node->next=ptr->next;
      free(ptr);
     }
  }




  //Deleting by key
  void delete_key(int item){
    struct Node* prev;
    struct Node* temp;
    temp=list;

    if(list==NULL){
      printf("List already empty");
      return;
    }

    if (list->next==NULL){    
        temp=list->next;  
        free(list);       
        list = temp ; 
      }

    while(temp->next!=NULL && temp->data!=item){
      prev=temp;
      temp=temp->next;
     }
     if(temp==NULL) return;
     prev->next=temp->next;
     free(temp);

  }

  //length of linked list
  void length(){

    struct Node* temp; 
    int length=1;
    temp=list;
    while(temp->next!=NULL){
      length++;
      temp=temp->next;
    } 
     printf("Length of linked list is %d\n", length);
  }
  
  //searching a key
  void search(int item){
   
   int count=0,pos[10],i=0;
   struct Node* temp=list;
  
   while(temp!=NULL){
      if(temp->data==item){
        pos[count]=i;
         count++;
       }
       i++;
      temp=temp->next;
    }
      if (count == 0)
      printf("%d not found\n",item);
     else{
      printf("%d found %d time(s)\n ",item,count );
      printf("position(s) are :");
      for(i=0;i<count;i++){
        printf("%d",pos[i]);
      }
      printf("\n");
     } 
   }





void llist(char str[], int index, int num, ...){

  va_list valist;

  char ins[] = "INS";
  char del_key[] = "DEL_KEY";
  char del_pos[] = "DEL_POS";
  char len[] =  "LEN";
  char srch[] = "SEARCH";


  //Insertion
  if(strcmp(str,ins) == 0){
    
         va_start(valist, num);
         pos=index;
         for(int i=0;i<num;i++){
             ll_insert(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Inserting %d element \n",num );
          ll_traverse();
  }

 //Deletion through position
   if(strcmp(str,del_pos) == 0){
         va_start(valist, num);
         pos=index;
          for(int i=0;i<num;i++){
             ll_delete(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Deleting %d element(s) by position\n",num );
          ll_traverse();
    }
  

  //Deletion through key
   if(strcmp(str,del_key) == 0){
        va_start(valist, num);
        for(int i=0;i<num;i++){
          delete_key(va_arg(valist,int));
        }
        va_end(valist);   

          printf("Deleting %d element(s) by index \n",num );
        ll_traverse();   
      }

  

  if(strcmp(str,len) == 0){
    va_start(valist, num);
    length(va_arg(valist,int));
    va_end(valist);
  }

  if(strcmp(str,srch) == 0){
    va_start(valist, num);
     for(int i=0;i<num;i++){
          search(va_arg(valist,int));
      } 
    va_end(valist);
  }
  
}

/*int main(){

   //creating linked list
   llist("INS",1,0);
   
   //insert at beginning four elements 
   llist("INS",1,4,1,2,7,8);

   //insert at end one element i.e 3
   llist("INS",-1,1,3);
   
   //insert at second position 
   llist("INS",2,1,22);

   //delete from beginning 1 element
   llist("DEL_POS",1,1);

   //delete from end 1 element
   llist("DEL_POS",-1,1);

   //deleting from second position
   llist("DEL_POS",2,1);

   //delete value 1
   llist("DEL_KEY",0,1);

   //length of linked list
   llist("LEN",0,0);

   //searching a value in linked list
   llist("SEARCH",0,1,2);
  
 }*/

  