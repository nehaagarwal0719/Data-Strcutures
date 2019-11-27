// Max-Heap data structure in C
#include <stdio.h>
#include<stdarg.h>
#include<string.h>
    int sizemax = 0;
    int array[20];
    void swapmax(int *a, int *b){
      int temp = *b;
      *b = *a;
      *a = temp;
    }
    void heapifymax(int array[], int sizemax, int i){
      if (sizemax == 1){
        printf("Single element in the heap");
      }else{
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < sizemax && array[l] > array[largest])
          largest = l;
        if (r < sizemax && array[r] > array[largest])
          largest = r;
        if (largest != i){
          swapmax(&array[i], &array[largest]);
          heapifymax(array, sizemax, largest);
        }
      }
    }
    void insertmax(int data){
      if (sizemax == 0){
        array[0] = data;
        sizemax += 1;
      }else{
        array[sizemax] = data;
        sizemax += 1;
        for (int i = sizemax / 2 - 1; i >= 0; i--){
          heapifymax(array, sizemax, i);
        }
      }
    }
    void maxheapdelete(int data){
      int i;
      for (i = 0; i < sizemax; i++){
        if (data == array[i])
          break;
      }
      swapmax(&array[i], &array[sizemax - 1]);
      sizemax -= 1;
      for (int i = sizemax / 2 - 1; i >= 0; i--){
        heapifymax(array, sizemax, i);
      }
    }
    void printmaxheap(){
      for (int i = 0; i < sizemax; ++i)
        printf("%d ", array[i]);
      printf("\n");
    }
    
    void maxheap(char str[], int num, ...){
    	va_list valist;
    	char ins[] = "INS";
			char del[] = "DEL";
			
			//insertion
			if(strcmp(str,ins) == 0){
			va_start(valist, num);
				for(int i=0;i<num;i++){
					insertmax(va_arg(valist,int));
				    }
				va_end(valist);
				printf("Max-Heap array from left to right: ");
				printmaxheap();
				printf("\n");
			}
			
			  //Deletion
			if(strcmp(str,del) == 0){
			va_start(valist, num);
				for(int i=0;i<num;i++){		
					maxheapdelete(va_arg(valist,int));
						}
			va_end(valist); 
			  printf("After deleting an element: ");
				printmaxheap();
				printf("\n");
			}
				
    }
  /*  int main(){
    
    	maxheap("INS",5,3,4,9,5,2);

    	maxheap("INS",5,1,6,7,7,11);

	maxheap("DEL",1,9);
			
	maxheap("DEL",3,7,3,11);
	
	return 0;
    }
*/

