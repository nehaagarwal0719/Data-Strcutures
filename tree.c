//Author: Praveen Gupta
// Part of Cosmos by OpenGenus Foundation

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

//Defining Node
typedef struct node{
	int data;
	struct node *left;
	struct node *right;

}node;

node *head=NULL;

//Creates a new Node
node *newNode(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

//Adds the new node to the appropriate position
node *create(node *head,int data){

	if (head==NULL){
		head = newNode(data);
	}
	else if(data<=head->data){
		head->left = create(head->left,data);
	}
	else{
		head->right = create(head->right,data);
	}
	return head;
}

//Prints tree
void print(node *head){
	if(head==NULL)
	{
		return;
	}
	printf("%d(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}

//treesearches for an element in the tree
int treesearch(node *head, int data){
	if(head==NULL)
		return 0;
	if(head->data==data)
		return 1;
	if(data<head->data)
		return treesearch(head->left, data);
	else
		return treesearch(head->right, data);
}

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 


//Deletes a subtree with head as the parameter
node *deleteTree(node *head){
	if(head==NULL)
		return NULL;

	deleteTree(head->left);
	deleteTree(head->right);
	free(head);
	return NULL;
}

//Deletes the node and its children's
node *Tdelete(node *head, int data){
	if(head==NULL){
		printf("\nNot found\n");
	}

	//if(head->data==data){
		//head = deleteTree(head);
	//}
	
	else if(data<head->data)
		head->left = Tdelete(head->left, data);
	
	else if(data>head->data)
		head->right = Tdelete(head->right, data);
    else
    	// node with only one child
    	{
    	  if (head->left == NULL) 
           { 
            struct node *temp = head->right; 
            free(head); 
            return temp; 
           } 
        else if (head->right == NULL) 
        { 
            struct node *temp = head->left; 
            free(head); 
            return temp; 
        } 
        
        //two children
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(head->right); 
  
        // Copy the inorder successor's content to this node 
        head->data = temp->data; 
  
        // Delete the inorder successor 
        head->right = Tdelete(head->right, temp->data); 
    }
	return head;
}


//Finds the height of the tree
int height(node *head) 
{
   if (head==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int left_height = height(head->left);
       int right_height = height(head->right);
 
       /* use the larger one */
       if (left_height > right_height) 
           return(left_height+1);
       else return(right_height+1);
   }
} 
void tree(char str[], int num, ...){
//No need of index as there is nothing like inserting from the beginning & from the end. 

	
	va_list valist;

  char ins[] = "INS";
  char del[] = "DEL";
  char ht[] =  "HEIGHT";
  char srch[] = "treesearch";
  
  //Insertion
  if(strcmp(str,ins) == 0){
	va_start(valist, num);
		for(int i=0;i<num;i++){
			head = create(head,va_arg(valist,int));
          }
    va_end(valist);
    print(head);
    printf("\n");
	}
  
  //Deletion
  if(strcmp(str,del) == 0){
	va_start(valist, num);
			head = Tdelete(head,va_arg(valist,int));
	va_end(valist); 
    print(head);
    printf("\n");
	}
  
  //treesearch if Yes/No
  if(strcmp(str,srch) == 0){
	va_start(valist, num);
		for(int i=0;i<num;i++){
				treesearch(head,va_arg(valist,int)) ? printf("Found in tree\n"):printf("Not Found in tree\n");
          }
	va_end(valist); 
	}

  //Height of the Tree
  if(strcmp(str,ht) == 0){
	va_start(valist, num);
		printf("The height of BST is: %d ",height(head));
	va_end(valist); 
	printf("\n");
	}
}
/*int main(){

tree("INS",5,20,30,15,12,17);

tree("INS",5,23,24,25,26,13);

tree("treesearch",1,13);

tree("DEL",1,15);

tree("treesearch",1,13);

tree("HEIGHT",0);

return 0;
}*/
