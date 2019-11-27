#include <stdio.h>  
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define TABLE_SIZE 13
#define PRIME 7 
#define MAX 1000 
  
bool has[MAX + 1][2]; 
int a[50],n; 
int value;
int hashTable[TABLE_SIZE]={ -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
int curr_size=0; 
struct hnode *hhead[TABLE_SIZE]={NULL},*z;

//hashing - index mapping  
void insert_h(int val) 
{ 
        if (val >= 0)  
            has[val][0] = 1; 
       else
            has[abs(val)][1] = 1; 
} 

void search_h(int value) 
{ 
    if(value>0){
    if (has[value][0] == 1) 
        printf("value is present");
    }
    else if(value<0){
        if (has[value][1] == 1) 
        printf("value is present");
    }
    else
        printf("value is not present");
} 


//Solving collision through chaincode
struct hnode
{
    int data;
    struct hnode *next;
};



//insert using chaincode
void insert_cc(int key)
{
  struct hnode * newnode=(struct hnode*)malloc(sizeof(struct hnode));
    printf("Inside the function\n");
    int i;
    i=key%TABLE_SIZE;
    printf("%d\n",i );
    
    printf("test0\n");
    newnode->data=key;
    newnode->next = NULL;
    printf("test1\n");
    if(hhead[i] == NULL)
        hhead[i] = newnode;
    else
    {
        printf("test2\n");
        z=hhead[i];
        while(z->next != NULL)
        {
           z=z->next;
        }
        printf("test3\n");
        z->next=newnode;
    }
}
  
//search function 
  void search_cc(int key)
    {
    int index; 
    index=key%TABLE_SIZE;
    if(hhead[index] == NULL)
        printf("\n Search element not found\n");
    else
    {
        for(z=hhead[index];z!=NULL;z=z->next)
        {
            if(z->data == key)
                {
                    printf("search element found\n");
                    break;
                }
        }
        if(z==NULL)
            printf("\n Search element not found\n");
   
    }
}

//display function
void display_cc()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nentries at index %d\n",i);
               if(hhead[i] == NULL)
               {
               printf("NULL");
               
               }
               else
               {
                              for(z=hhead[i];z!=NULL;z=z->next)
                              printf("%d->",z->data);
               }
          }
         
}


//Double Hashing
// function to check if hash table is full 

bool isFull() 
 { 
    // if hash size reaches maximum size 
    return (curr_size == TABLE_SIZE); 
  } 
  
 // function to calculate first hash 
int hash1(int key) 
 { 
    return (key % TABLE_SIZE); 
  } 
  
// function to calculate second hash 
int hash2(int key) 
 { 
    return (PRIME - (key % PRIME)); 
 } 

 int initi(){
  for (int i=0; i<TABLE_SIZE; i++) 
       hashTable[i] =-1;   
 }

void insert_dd(int key) 
  {          
     // if hash table is full 
   //initi();
     if (isFull()) 
        return; 

     // get index from first hash 
    int index = hash1(key); 
    
    // if collision occurs 
    if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % 
                                        TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
        
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
    // function to display the hash table 
    void display_dd() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashTable[i] != -1) 
                printf("%d --> %d\n",i ,hashTable[i]);
            else
                printf("%d\n",i);
        } 
    } 

    void search_dd(int value){
        int f;
        for(int i=0;i < TABLE_SIZE; i++){
            if(hashTable[i] == value){
                f=1;
                printf("Value is present\n");
                break;
            }
        }
             if(f==0)
             printf("Value is not present\n");
    }
    

void hash(char str[], int index, int num, ...){

  va_list valist;

  char has1[] = "HASH";
  char chas[] = "CHASH";
  char dhas[] ="DHASH";
  //Insertion

  if(strcmp(str,has1) == 0){

      va_start(valist, num);
       if(index==0){
        for(int i=0;i<num;i++)
          insert_h(va_arg(valist,int));
       }
       else if( index==1){
          for(int i=0;i<num;i++)
          search_h(va_arg(valist,int));
       }
        else if( index==2 ){
           for( int i=0;i<50;i++){
                printf("%d",has[i][0]);
           }
       }
    va_end(valist); 
   }

    if(strcmp(str,chas) == 0){

      va_start(valist, num);
       if(index==0){
          printf("Insertion1\n");
           for(int i=0;i<num;i++){
              insert_cc(va_arg(valist,int));
                 printf("Insertion2\n");
         }
       }
       else if( index==1){
        for(int i=0;i<num;i++)
          search_cc(va_arg(valist,int));
       }
        else if( index==2 ){

           display_cc();
       }
    va_end(valist); 
   }

   if(strcmp(str,dhas) == 0){
  
      va_start(valist, num);

       if(index==0){
         for(int i=0;i<num;i++){
              insert_dd(va_arg(valist,int));
         }
       }    
       else if( index==1 ){
          for(int i=0;i<num;i++)
          search_dd(va_arg(valist,int));
       }
        else if( index==2 ){
          display_dd();
       }
    va_end(valist); 
   }
}
 

/*int main() 
{  
    int i;
   // printf("Enter quantity of data \n");
    //scanf("%d",&n);

    /*printf("Enter data\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   */
   // printf("hi\n");
   //for (int i=0; i<TABLE_SIZE; i++) 
     // printf("%d",hashTable[i]);   
    
    //normal hashing
    //insertion 
    //hash("HASH",0,3,1,2,3);
    //search
    //hash("HASH",1,1,2);
    //display
    //hash("HASH",2,0);
   /*
    //chaining
    //insertion
    hash("CHASH",0,3,1,2,5);
    //search
    hash("CHASH",1,1,4);
    //display
    hash("CHASH",2,0);
     
    //Double Hashing
    //insertion
    hash("DHASH",0,2,3,4);
    //search
    //hash("DHASH",1,1,3);
    //display
    hash("DHASH",2,0);
  
    return 0; 
} */
