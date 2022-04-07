/*
Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        vector<int>a;
        int l=0,k=0,m=mat.size(),n=mat[0].size();
        while(k<m && l<n)
        {
            for(int i=l;i<n;i++)
                a.push_back(mat[k][i]);
            k++;
            for(int i=k;i<m;i++)
                a.push_back(mat[i][n-1]);
            n--;
            if(k<m)
            {
                for (int i=n-1;i>=l;i--)
                    a.push_back(mat[m-1][i]);
                m--;
            }
            if(l<n)
            {
                for(int i=m-1;i>=k;i--)
                    a.push_back(mat[i][l]);
                l++;
            }
        }
        return a;
    }
};