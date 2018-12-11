#include <stdio.h>

int *arr;

void alloc(int n){
    arr=(int *)malloc(sizeof(int)*n);
}
void quicksort(int arr[], int left, int right, int n){
    if(left<right){
        int pivot=(left+right)/2;
        int parti=partition(arr, left, right, pivot);
        quicksort(arr, left, parti-1, n);
        quicksort(arr, parti, right, n);
    }



}

int partition(int arr[], int left, int right, int pivot){
    while(left<=right){
        while(arr[left]<arr[pivot])
            left++;
        while(arr[right]>arr[pivot])
            right--;
        if(left<=right){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }
    return left;
}

void main(){
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    alloc(n);
    printf("Enter the array elements...\n");
    int i;
    for(i=0; i<n; i++){
        printf("Enter %dth element: ",i+1);
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1, n);
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
}
