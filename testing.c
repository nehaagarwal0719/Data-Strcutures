
#include "cads.h"
#include <stdio.h>
#define TABLE_SIZE 13
#define PRIME 7 
#define MAX 1000 
int main(){

/*
1st : INS or DEL
2nd : '1' for at beginning and '-1' for from end
3rd : total 'n' numbers want to insert 
4,5,6,7,... : the 'n' number of integers
*/
 
   // LINKED LIST 

  printf("linked list functions\n");

   //creating linked list
   llist("INS",1,0);
   
   //insert at beginning four elements 
   llist("INS",1,4,1,2,7,8);

   //insert at end one element i.e 3
   llist("INS",-1,1,3);
   
   //insert at second position 
   llist("INS",2,1,22);

   //delete from beginning 1 element
   //llist("DEL_POS",1,1);

   //delete from end 1 element
   //llist("DEL_POS",-1,1);

   //deleting from second position
   //llist("DEL_POS",2,1);

   //delete value 1
   llist("DEL_KEY",0,1);

   //length of linked list
   llist("LEN",0,0);

   //searching a value in linked list
   llist("SEARCH",0,1,2);


    
    //cllist("INS",1,0);

    //insert at beginning two elements i.e 1 and 2
    /*cllist("INS",1,4,1,2,3,4);

    //insert at end one element i.e 33
    cllist("INS",-1,1,800);
    
    //insert at second position one element i.e 0
    cllist("INS",2,1,0);
    //deleting from beginning
    cllist("DEL_POS",1,1);

    //deleting from end
    cllist("DEL_POS",-1,1); 

    //delete from between
   cllist("DEL_POS",2,1);

    //deleting through key
    cllist("DEL_KEY",0,1,0);

    
    //length of linked list
   cllist("LEN",0,0);

   //searching a value in linked list
   cllist("SEARCH",0,1,1);

   */

   printf("\n\nDOUBLE LINKED LIST\n");
   //DOUBLE LINKED LIST
   //creating double linked list
   dllist("INS",1,0);
   
   //insert at beginning three elements 
   dllist("INS",1,2,1,5);

   //insert at end one element 
  dllist("INS",-1,1,555);

   //insert one element at second position
   dllist("INS",2,1,33);
    
   
   //deletion from beginning
   dllist("DEL_POS",1,1);
   
   //deletion from end
   dllist("DEL_POS",-1,1);

   //deletion of element at second position
   //dllist("DEL_POS",2,1);

   //deleting element by key
   dllist("DEL_KEY",2,1);

   //length of linked list
   dllist("LEN",0,0);

   //searching a value in linked list
   dllist("SEARCH",0,1,33);
  
   
   //STACK
   printf("\n\nSTACK\n");
   //pushing elements in stack
   stack("INS", 2,10,20);

   //poppinge elements out of stack
   stack("DEL",2);

   //finding out the top element in stack
   stack("TOP",0);     
   

   //QUEUE
    printf("\n\nQUEUE\n");
   //Creating an Empty Queue
   queue("INS",0);
   //Inserting 3 Elements in Queue from the end
   queue("INS",2,1,2);
   //Deleting 2 Elements from the Queue from the beginning 
   queue("DEL",2);
   //Returning the Top element
   queue("TOP",0);
   
   

   //CIRCULAR QUEUE
    printf("\n\nCIRCULAR QUEUE\n");
   //inserting four elements 
    CQueue("INS",2,10,20);
   //deleting two elements 
    CQueue("DEL",2);
   //front element of queue
    CQueue("FRT",0);


printf("MATRIX\n");
	int A[][5] = {{2,4,6,8},
			 {1,3,5,7},
			 {1,5,7,9},
			 {2,3,5,6}};

	int B[][5] = {{1,3,5,7},
			 {1,2,3,4},
			 {5,6,7,8},
			 {2,6,7,8}};


	int C[][5] = {{2,4,6},
			  {1,3,5},
			  {1,5,7}};
		   
	int D[][5] = {{1,3,5},
			  {1,2,3},
			  {5,6,7}};

	int E[][5] = {{2,4},
			  {1,3}};

	int F[][5] = {{4,8},
			  {3,7}};

	int G[][5] = {{2,4},
			  {1,3}};

	//add
	matrix("ADD",4,A,B);

	//subtract
	matrix("SUB",3,C,D);

	//multiply
	matrix("MUL",2,E,F);	

	//check whether equal or not
	matrix("ECK",2,E,G);

	matrix("ECK",2,E,F);


   //hash
     //normal hashing
    //insertion 
    hash("HASH",0,3,1,2,3);
    //search
    hash("HASH",1,1,2);
    //display
   hash("HASH",2,0);
   
    //chaining
    //insertion
    hash("CHASH",0,2,15,2);
    //search
    hash("CHASH",1,1,4);
    //display
    hash("CHASH",2,0);
     

    //Double Hashing
    //insertion
    hash("DHASH",0,2,3,4);
    //search
    hash("DHASH",1,1,3);
    //display
    hash("DHASH",2,0);

    //graph
	printf("GRAPH\n");
     graph("INS");
     graph("BFS");
     graph("CYCLE");
     graph("DFS");
     graph("CYCLE");

	//TREE
	printf("\nBinary Search Tree\n");
	tree("INS",5,20,30,15,12,17);
	tree("INS",5,23,24,25,26,13);
	tree("SEARCH",1,13);
	tree("DEL",1,15);
	tree("SEARCH",1,13);
	tree("HEIGHT",0);
   
	//MAX-HEAP
	printf("Max-Heap\n");
	maxheap("INS",5,3,4,9,5,2);
  	maxheap("INS",5,1,6,7,7,11);
	maxheap("DEL",1,9);
	maxheap("DEL",3,7,3,11);
	
	//MIN-HEAP
	printf("Min-Heap\n");
	minheap("INS",5,3,4,9,5,2);
    	minheap("INS",5,1,6,7,7,11);
	minheap("DEL",1,9);
	minheap("DEL",3,7,3,11);
	  
    return 0;
}
