/*

Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690

*/




    int nthUglyNumber(int n) 
    {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        vector<int>ugly(n);
        ugly[0]=1;
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++)
        {
            ugly[i]=min(ugly[p2]*2,min(ugly[p3]*3,ugly[p5]*5));
            if(ugly[i]==ugly[p2]*2)
                p2++;
            if(ugly[i]==ugly[p3]*3)
                p3++;
            if(ugly[i]==ugly[p5]*5)
                p5++;
        }
        return ugly[n-1];
    }