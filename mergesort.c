#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void print(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void genArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		arr[i] = rand()%100 + 1;
	}
}


void merge(int arr[], int l, int m, int r){// gop hai arr con [l->m] va [m+1-> r]
	int i, j, k;
	int n1 = m - l + 1;// so phan tu doan 1
	int n2 = r - m;
	int left[n1], right[n2]; // tao cac mang tam
	
	for (i = 0; i < n1; i++){
		left[i] = arr[l + i];
	}
	for (i = 0; i < n2; i++){
		right[i] = arr[m + 1 + i];
	}
	i = j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){ // main sort
	if (l < r){
		int m = l + (r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}


int main(){
	srand(time(0));
	int n;
	scanf("%d",&n);
	int arr[n];
	genArr(arr,n);
	mergeSort(arr,0,n-1);
	print(arr,n);
	
	
	return 0;
}
