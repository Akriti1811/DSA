/*
Merge Sort
Given an array of integers nums, sort the array in ascending order.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
public:
    void merge(vector<int>& a,int l,int mid,int r)
    {
        int n1=mid-l+1;
        int n2=r-mid;
        int left[n1],right[n2];
        for(int i=0;i<n1;i++)
            left[i]=a[l+i];
        for(int j=0;j<n2;j++)
            right[j]=a[mid+1+j];
        int i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(left[i]<=right[j])
                a[k++]=left[i++];
            else
                a[k++]=right[j++];
        }
        while(i<n1)
            a[k++]=left[i++];
        while(j<n2)
            a[k++]=right[j++];
         
    }
    void mergesort(vector<int>& a,int l, int r)
    {
        if(l<r)
        {
            int mid=l+((r-l)/2);
            mergesort(a,l,mid);
            mergesort(a,mid+1,r);
            merge(a,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};