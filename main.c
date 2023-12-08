#include <stdio.h>

void swap(int *arr,int left,int right){
    int tempData = arr[left];
    arr[left] = arr[right];
    arr[right] = tempData;
}

void pointerSwap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *arr,int length){
    for (int i = 0; i < length; i++) {
        for (int k = 0; k < length -1; k++) {
            if(arr[k] > arr[k+1]){
                swap(arr,k,k+1);
            }

        }
    }
}

void BubbleSortWithWhile(int *arr,int length){
    while(length > 1){
        for (int k = 0; k < length -1; k++) {
            if(arr[k] > arr[k+1]){
                swap(arr,k,k+1);
            }

        }
        length--;
    }
}

void SelectionSort(int *arr, int length){

    for (int i = 0; i < length; i++) {
        int minIndex = i;
        for (int j = i; j < length; j++) {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr,i,minIndex);
    }
}

void SelectionSortWithPointer(int *arr, int length){
    int * min;
    for (int i = 0; i < length; i++) {
        min = &arr[i];
        for (int j = i; j < length; j++) {
            if(arr[j] < *min){
                min = &arr[j];
            }
        }
        pointerSwap(min,&arr[i]);
    }

}


void InsertionSort(int *arr, int length){
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n-1; i++) {
        int j = i + 1;
        if(arr[i] >arr[i+1]){
            while(j >0 && arr[j] < arr[j-1]){
                swap(arr,j,j-1);
                j--;
            }
        }
    }
}

void insertionSort2(int * arr,int length){
    for (int i = 0; i < length - 1; i++) {
        if(arr[i] > arr[i+1]){
            for (int j = i; j >= 0; j--) {
                if(arr[j] > arr[j+1]){
                    swap(arr,j,j+1);
                }
                else{
                    break;
                }
            }
        }
    }
}


int Pivot(int *arr,int left,int right){
    int pivot = arr[left];
    int i = left-1;
    int j = right+1;

    while(i < j){
        while(arr[++i] < pivot){}
        while(arr[--j] > pivot){}
        if(i >= j){
            return j;
        }
        swap(arr,i,j);

    }
}


void QuickSortLeftPivot(int *arr,int left,int right){
    int pivot = Pivot(arr,left,right);
    if(left < right){
        QuickSortLeftPivot(arr,left,pivot);
        QuickSortLeftPivot(arr,pivot+1,right);
    }
    else{
        return;
    }


}



void main() {
    int arr[] = {5,2,7,6,1,3,9};
    //BubbleSortWithWhile(arr,6);

    //SelectionSortWithPointer(arr,7);

    //InsertionSort(arr,7);
    insertionSort(arr,7);

    //QuickSortLeftPivot(arr,0,6);



}
