#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void genArr(int arr[], int n){
	int i;
	for (i = 0;i < n; i++){
		arr[i] = rand()%1000+1;
	}
}

void printArr(int arr[], int n){
	int i;	
	for (i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key  = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){ // tang dan 
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){
	srand(time(0));
	int n; 
	scanf("%d", &n);
	int arr[n];
	
	genArr(arr,n);
	insertionSort(arr,n);
	printArr(arr,n);
	return 0;	
	
}
