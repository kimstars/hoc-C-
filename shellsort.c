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


void shellSort(int arr[], int n){
	int k = n / 2;
	int i;
	for (;k > 0; k /= 2){
		for (i = k; i < n; i++){
			int temp = arr[i];
			int j;
			for (j = i; j >= k && arr[j - k] > temp; j -= k){
				arr[j] = arr[j - k];
			}
			arr[j] = temp;
		}
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	genArr(arr,n);
	shellSort(arr,n);
	printArr(arr,n);
}












