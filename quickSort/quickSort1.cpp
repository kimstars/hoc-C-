#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


void quickSort(int Data[], int l, int r){
    if(l <= r){
        int key = Data[(l + r)/2];
        int i = l;
        int j = r;
        while(i <= j){
            while(Data[i] < key) i++;
            while(Data[j] > key) j--;
            if(i <= j){
                swap(Data[i], Data[j]);
                i++;
                j--;
            }
        }
        if(l < j){
            quickSort(Data, l, j);
        }
        if(r > i){
            quickSort(Data, i, r);
        }
    }
}

void genArr(int a[], int n){

    for(int i = 0; i < n; i++){
        a[i] = rand()%100 + 1;
    }
}

void  printArr(int a[]){
    for(int i = 0; a[i] ; i++){
        cout << a[i] << " ";
    }
}



int main(){
    int n;
    srand(time(0));

    cout << "nhap so phan tu : ";
    cin >> n;
    int a[n+1];
    genArr(a,n);

    printArr(a);

    cout << "\nafter quicksort \n";
    quickSort(a, 0 , n-1);
    printArr(a);


}