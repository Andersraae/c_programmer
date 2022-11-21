#include <stdio.h> 
#include <stdlib.h> 

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printList(int L[], int size);

int main(int argc, char const *argv[])
{
    int arr[] = {5, 0, 4, 3, 6, 7, 1, 9, 50};
    int sizeArr = sizeof(arr)/sizeof(arr[0]);

    printf("Givet listen med stoerrelsen %d: ", sizeArr);
    printList(arr, sizeArr);

    mergeSort(arr, 0, sizeArr - 1);

    printf("Er den sorterede liste ");
    printList(arr, sizeArr);

    return 0;
}

void merge(int arr[], int l, int m, int r){
    int arr1[m - l + 1];
    int arr2[r - m];
    int i = 0, j = 0, k = 0;

    for(int in = 0; in < m - l + 1; in++){
        arr1[in] = arr[l + in];
    }
    for(int in = 0; in < r - m; in++){
        arr2[in] = arr[m + 1 + in];
    }

    while (i < m - l + 1 && r - m)
    {
        if(arr1[i] <= arr2[j]){
            arr[l + i + j] = arr1[i];
            i++;
        } else {
            arr[l + i + j] = arr2[j];
            j++;
        }
    }
    if (i == m - l + 1)
    {
        for (k = j; k < r - m - 1; k++)
        {
            arr[l + i + k] = arr2[k];
        } 
        
    } else {
            for (k = i; k < m - l + 1; k++)
            {
                arr[l + j + k] = arr1[k];
            }
            
        }
    
}

void mergeSort(int arr[], int l, int r){
    if (l < r)
    {
        int m = (r + l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printList(int L[], int size){ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", L[i]); 
    printf("\n"); 
} 
