/*

Matrix Block Sum

Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100

*/

//Naive Solution

	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                for(int r=max(i-k,0);r<=min(i+k,row-1);r++)
                {
                    for(int c=max(j-k,0);c<=min(j+k,col-1);c++)
                      ans[i][j]+=mat[r][c];
                }
            }
        }
        return ans;
    }



//Prefix Sum 

	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        
        for(int j=1;j<col;j++)    
        {
            for(int i=0;i<row;i++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
         
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mat[i][j]+=mat[i-1][j];
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i][j]=mat[min(row-1,i+k)][min(col-1,j+k)];
                if(i-k-1>=0 && j-k-1>=0)
                ans[i][j]+=mat[i-k-1][j-k-1];
                if(i-k-1>=0)
                ans[i][j]-=mat[i-k-1][min(col-1,j+k)];
                if(j-k-1>=0)
                ans[i][j]-=mat[min(row-1,i+k)][j-k-1];
            }
        }
        return ans;
    }

