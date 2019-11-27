#include "cads.h"
#include <stdio.h>//printf
#include<string.h>//strcmp
#include<stdlib.h>//malloc
int i,j,k;
int result[5][5];
int flag;
  
void matrix(char str[], int size, int one[][5], int two[][5]){

	char add[] = "ADD";
	char sub[] = "SUB";
	char mul[] = "MUL";
	char chkequal[] = "ECK";

	if(strcmp(str,add) == 0){
		//addition
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				result[i][j] = one[i][j] + two[i][j];
			}
		}
		//display
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				printf(" %d",result[i][j]);	
			}
		printf("\n");
		}
	printf("\n");
	}
	else if(strcmp(str,sub) == 0){
		//subtraction
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				result[i][j] = one[i][j]-two[i][j];
			}
		}
		//display
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				printf(" %d",result[i][j]);	
			}
		printf("\n");
		}
	printf("\n");	
	}
	else if(strcmp(str,mul) == 0){
		//multiplication
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				result[i][j] = 0;
				for(k=0;k<size;k++){					
				result[i][j] += one[i][k]*two[k][j];
				}
			}
		}
		//display
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				printf(" %d",result[i][j]);	
			}
		printf("\n");
		}
	printf("\n");	
	}
	else if(strcmp(str,chkequal) == 0){
		//check equal
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(one[i][j] != two[i][j]){
				flag=0;
				}else{
				flag=1;
				}				
			}
		}
		if(flag==0){
		printf("\nThese are two different matrices");
		}
		if(flag==1){
		printf("\nThe matrices are identical");
		}		
	printf("\n");	
	}
	else{
		printf("Wrong option! Please try again...");
	}	
	printf("\n");
}
 

//MATRIX
/*int main(){
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

	return 0;
}*/