// #include <stdio.h> 
// #include <stdlib.h> 

// void Merge(int L[], int start, int slut, int midt);
// void MergeSort(int L[], int start, int slut);
// void printList(int L[], int size);

// int main(void){ 
//     int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
//     int L_size = sizeof(L) / sizeof(L[0]); 
    
//     printf("Givet listen \n"); 
//     printList(L, L_size); 
    
//     MergeSort(L, 0, L_size - 1); 
    
//     printf("Er den sorterede liste \n"); 
//     printList(L, L_size); 
//     return 0; 
// } 

// void Merge(int L[], int start, int slut, int midt){
//     int L1[midt - start +1], L2[slut - midt]; 
//     int i,j,k;
    
//     for(i = 0; i < midt - start + 1; i++){
//         L1[i] = L[start + i];
//     }
//     for(i = 0; i < slut-midt; i++){
//         L2[i] = L[midt + 1 + i];
//     }
//     i = 0;
//     j = 0;
//     while (i < midt - start + 1 && j < slut -midt)
//     {
//         if(L1[i] <= L2[j]){
//             L[start + i + j] = L1[i];
//             i++;
//         }
//         else{
//             L[start + i + j] = L2[j];
//             j++;
//         }
//     }
    
//     if(i == midt - start + 1){
//         for(k = j; k < slut -midt - 1;k++){
//             L[start + i + k] = L2[k];
//         }
//     }
//     else{
//         for(k = i; k < midt-start +1;k++){
//             L[start + j + k] = L1[k];
//         }
//     }
// }

// void MergeSort(int L[], int start, int slut){
//     int m;
//     if (start < slut){
//         m = (start + slut)/2;
//         MergeSort(L, start, m);
//         MergeSort(L, m + 1, slut);
//         Merge(L, start, slut, m);
//     }

// }

// void printList(int L[], int size){ 
//     int i; 
//     for (i = 0; i < size; i++) 
//         printf("%d ", L[i]); 
//     printf("\n"); 
// } 



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
            // printf("Her er noget %d \n", arr2[k]);
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
