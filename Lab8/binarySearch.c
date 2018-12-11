#include <stdio.h>

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
 void main()
{
   int i, first, last, middle, n, search, array[100];

   printf("Enter number of elements\n");
   scanf("%d",&n);

   printf("Enter %d integers\n", n);

   for (i = 0; i < n; i++)
      scanf("%d",&array[i]);
    quicksort(array, 0, n-1, n);
    printf("The sorted array will be...\n");
    for(i=0; i<n; i++)
      printf("%d ", array[i]);
   printf("\nEnter value to find\n");
   scanf("%d", &search);

   first = 0;
   last = n - 1;
   middle = (first+last)/2;

   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);


}
