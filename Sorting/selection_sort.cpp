/*
Selection Sort
*/

void selectionSort(int a[], int n)
    {
       for(int i=0;i<n;i++)
       {
           int min_ind=i;
           for(int j=i+1;j<n;j++)
           {
               if(a[j]<a[min_ind])
               min_ind=j;
           }
           swap(&a[i],&a[min_ind]);
       }
    }