// Min-Heap data structure in C
#include <stdio.h>
#include<stdarg.h>
#include<string.h>
    int sizemin = 0;
    int array[20];
    void swapmin(int *a, int *b){
      int temp = *b;
      *b = *a;
      *a = temp;
    }
    void heapifymin(int array[], int sizemin, int i){
      if (sizemin == 1){
        printf("Single element in the heap");
      }else{
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < sizemin && array[l] < array[smallest])
          smallest = l;
        if (r < sizemin && array[r] < array[smallest])
          smallest = r;
        if (smallest != i){
          swapmin(&array[i], &array[smallest]);
          heapifymin(array, sizemin, smallest);
        }
      }
    }
    void insertmin(int data){
      if (sizemin == 0){
        array[0] = data;
        sizemin += 1;
      }else{
        array[sizemin] = data;
        sizemin += 1;
        for (int i = sizemin / 2 - 1; i >= 0; i--){
          heapifymin(array, sizemin, i);
        }
      }
    }
    void minheapdelete(int data){
      int i;
      for (i = 0; i < sizemin; i++){
        if (data == array[i])
          break;
      }
      swapmin(&array[i], &array[sizemin - 1]);
      sizemin -= 1;
      for (int i = sizemin / 2 - 1; i >= 0; i--){
        heapifymin(array, sizemin, i);
      }
    }
    void printminheap(){
      for (int i = 0; i < sizemin; ++i)
        printf("%d ", array[i]);
      printf("\n");
    }
    
    void minheap(char str[], int num, ...){
    	va_list valist;
    	char ins[] = "INS";
	char del[] = "DEL";
			
	//insertion
	if(strcmp(str,ins) == 0){
	va_start(valist, num);
		for(int i=0;i<num;i++){
			insertmin(va_arg(valist,int));
		    }
		va_end(valist);
		printf("Min-Heap array from left to right: ");
		printminheap();
		printf("\n");
	}
	
	//Deletion
	if(strcmp(str,del) == 0){
	va_start(valist, num);
		for(int i=0;i<num;i++){		
			minheapdelete(va_arg(valist,int));
			}
		va_end(valist); 
	  printf("After deleting an element: ");
		printminheap();
		printf("\n");
	}
				
}
    /*int main(){
    
    minheap("INS",5,3,4,9,5,2);

    minheap("INS",5,1,6,7,7,11);

	minheap("DEL",1,9);
	
	minheap("DEL",3,7,3,11);
	
	return 0;
    }*/


