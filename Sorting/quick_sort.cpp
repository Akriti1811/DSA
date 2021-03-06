/*

Quick Sort 

Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position low and its ending position high.

Implement the partition() and quickSort() functions to sort the array.


Example 1:

Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input: 
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10

Your Task: 
You don't need to read input or print anything. Your task is to complete the functions partition()  and quickSort() which takes the array arr[], low and high as input parameters and partitions the array. Consider the last element as the pivot such that all the elements less than(or equal to) the pivot lie before it and the elements greater than it lie after the pivot.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 103
1 <= arr[i] <= 104

*/


void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int pi=partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot=arr[high];
       int i=low;
       for(int j=low;j<high;j++)
       {
           if(arr[j]<pivot)
           {
               swap(arr[i],arr[j]);
               i++;
           }
       }
       swap(arr[i],arr[high]);
       return i;
    }