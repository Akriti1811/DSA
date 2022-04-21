/*
Majority Element (Voting Algorithm)
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
Constraints:
n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int cand=-1,vote=0,c=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(vote==0)
            {
                cand=nums[i];
                vote++;
            }
            else
            {
                if(nums[i]==cand)
                    vote++;
                else
                    vote--;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand)
             c++;
        }
        if(c>n/2)
            return cand;
        return -1;
    }
};