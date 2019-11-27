#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>

struct dNode
{
	int data;
	struct dNode *prev;
	struct dNode *next;
};

struct dNode* dlist=NULL;
int pos;


//checking if memory is available 
 struct dNode* davail_node(void){
   	  struct dNode* node;

      node=(struct dNode*)malloc(sizeof(struct dNode));
      if(node!=0)
      	return node;
      
      else
      {
      	printf("Overflow");
      	return 0;
      }

 }

//Insertion
void dl_insert(int item){

 struct dNode* temp= davail_node();
 struct dNode *ptr=dlist,*prev_node;int c=1;;
 temp->data=item;


//inserting at beginning
 if(pos==1){
 temp->next=dlist;
 temp->prev=NULL;

  if (dlist != NULL) 
    dlist->prev = temp;  

 dlist=temp;
}

//insert node at end
else if(pos==-1){
  temp->next=NULL;
   if(dlist==NULL){
      printf("hi\n");
      temp->prev=NULL;
      dlist=temp;
      return;
    }

  while(ptr->next!=NULL){
    	ptr=ptr->next;
  }

   ptr->next=temp;
   temp->prev=ptr;
}

//insert node at a specific function
else{ 
   while(ptr->next!=NULL && c!=pos){
      prev_node=ptr;
      ptr=ptr->next;
      c++;
   }
   temp->next=prev_node->next;
   prev_node->next=temp;
   temp->prev=prev_node;

   if(temp->next!=NULL)
    temp->next->prev=temp;
}
}

//Deletion
void dl_delete(){
    int deleted,c=1;
    struct dNode *ptr=dlist, *prev_node;
    

    if(dlist==NULL){
      printf("List already empty");
      return;
    }

    //deleting a node from beginning
    if(pos==1){
    deleted= dlist->data;
    dlist=dlist->next;
    dlist->prev=NULL;
    printf("%d deleted from beginning successfully\n" ,deleted);
    }
 
    //deleting node from end
    else if(pos==-1){
     
     if(ptr->next==NULL){
         deleted= dlist->data;
         dlist=dlist->next;
         dlist->prev=NULL;
         printf("%d deleted from end successfully\n" ,deleted);
     }

     while(ptr->next!=NULL  ){
        prev_node=ptr;
        ptr=ptr->next;
     }
      
      deleted=ptr->data;
      prev_node->next=NULL;
      free(ptr);
      printf("%d deleted from end successfully\n" ,deleted);   
  }

    //delete_after
    else{
    
     if(ptr->next==NULL){
         deleted= dlist->data;
         dlist=dlist->next;
         dlist->prev=NULL;
         printf("%d deleted successfully\n" ,deleted);
     }

     while(ptr->next!=NULL && c!=pos){
         c++;
        prev_node=ptr;
        ptr=ptr->next;
     }
    
      deleted=ptr->data;  
      prev_node->next=ptr->next;
      ptr->next->prev=prev_node;
      free(ptr);
      printf("%d deleted successfully from %d position\n" ,deleted,pos);
  }
}  

   //Deleting by key
  void dl_delete_key(int item){
    struct dNode* prev;
    struct dNode* temp;
    temp=dlist;
    int deleted;

    if(dlist==NULL){
      printf("List already empty");
      return;
    }

    if (dlist->next==NULL){    
         deleted= dlist->data;
         dlist=dlist->next;
         dlist->prev=NULL;
         printf("%d deleted successfully\n" ,deleted);
      }

    while(temp->next!=NULL && temp->data!=item){
      prev=temp;
      temp=temp->next;
     }

     deleted=temp->data;
     if(temp==NULL) return;
     prev->next=temp->next;
     free(temp);
    printf("%d deleted successfully\n" ,deleted);
  }


  //length of linked list
  void dlength(){

    struct dNode* temp; 
    int length=1;
    temp=dlist;
    while(temp->next!=NULL){
      length++;
      temp=temp->next;
    } 
     printf("Length of double linked list is %d\n", length);
  }
  
  //searching a key
  void dsearch(int item){
   
   int count=0,pos[10],i=0;
   struct dNode* temp=dlist;

   if(dlist->data==item){
       pos[count]=i;
         count++;
   }

   while(temp->next!=NULL){
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



//traversing list in both directions
void traverse()  
{  
    struct dNode* last;  
    struct dNode* ptr=dlist;
    if(ptr==NULL){
      printf("Empty\n");
      return;
    }
    printf("Traversal in forward direction \n");  
    while (ptr != NULL) {  
        printf(" %d ", ptr->data);  
        last = ptr;  
        ptr = ptr->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }  
    printf("\n");
}



void dllist(char str[], int index, int num, ...){

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
             dl_insert(va_arg(valist,int));
          }
          va_end(valist); 
          printf("Inserting %d element(s) \n",num );
          traverse();
  }

  //Deletion through key
   if(strcmp(str,del_key) == 0){        
        va_start(valist, num);
        for(int i=0;i<num;i++){
          dl_delete_key(va_arg(valist,int));
        }
        va_end(valist);      
        printf("Deleting %d element(s) by value \n", num);
        traverse();
  }

  //Deletion through position
   if(strcmp(str,del_pos) == 0){
      va_start(valist, num);
      pos=index;
      for(int i=0;i<num;i++){
        dl_delete(va_arg(valist,int));
      }
      va_end(valist); 
      printf("Deleting %d element(s) through position\n", num);
      traverse();
  }

  if(strcmp(str,len) == 0){
    va_start(valist, num);
    dlength(va_arg(valist,int));
    va_end(valist);
  }

  if(strcmp(str,srch) == 0){
    va_start(valist, num);
     for(int i=0;i<num;i++){
          dsearch(va_arg(valist,int));
      } 
    va_end(valist);
  }
}


/*int main(){
	//creating linked list
   dllist("INS",1,0);
   
  //insert at beginning three elements 
  dllist("INS",1,3,1,5,22);

  //insert at end one element 
   dllist("INS",-1,1,555);

  //insert one element at second position
   dllist("INS",2,1,33);
    

   //deletion from beginning
   dllist("DEL_POS",1,1);

   //deletion from end
   dllist("DEL_POS",-1,1);

   //deletion of element at second position
   dllist("DEL_POS",2,1);

   //deleting element by key
   dllist("DEL_KEY",2,1);

   //length of linked list
   dllist("LEN",0,0);

   //searching a value in linked list
   dllist("SEARCH",0,1,33);

	return 0;
}*/