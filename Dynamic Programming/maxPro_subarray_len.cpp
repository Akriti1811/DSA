/*

Maximum Length of Subarray With Positive Product

Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/


    int getMaxLen(vector<int>& nums) 
    {
        
        
        int pos=0,neg=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                pos=0,neg=0;
            }
            else if(nums[i]>0)
            {
                pos++;
                neg=(neg==0)?0:neg+1;
            }
            else
            {
                int temp=pos;
                pos=(neg==0)? 0:neg+1;
                neg=temp+1;       
            }
            ans=max(ans,pos);
        }
        return ans;
    }




    int getMaxLen(vector<int>& nums) 
    { 
        int n=nums.size();
        int pos[n],neg[n];
        pos[0]=(nums[0]>0)?1:0,neg[0]=(nums[0]<0)?1:0;
        int ans=pos[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                pos[i]=0,neg[i]=0;
            }
            else if(nums[i]>0)
            {
                pos[i]=pos[i-1]+1;
                neg[i]=(neg[i-1]==0)?0:neg[i-1]+1;
            }
            else
            {
                int temp=pos[i-1];
                pos[i]=(neg[i-1]==0)? 0:neg[i-1]+1;
                neg[i]=temp+1;       
            }
            ans=max(ans,pos[i]);
        }
        return ans;
    }