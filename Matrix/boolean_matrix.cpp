/*
Boolean Matrix 
Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.

Example 1:
Input:
R = 2, C = 2
matrix[][] = {{1, 0},
              {0, 0}}
Output: 
1 1
1 0 
Explanation:
Only cell that has 1 is at (0,0) so all 
cells in row 0 are modified to 1 and all 
cells in column 0 are modified to 1.

Example 2:
Input:
R = 4, C = 3
matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}
Output: 
1 1 1
1 1 1
1 1 1
1 0 0 
Explanation:
The position of cells that have 1 in
the original matrix are (0,0), (1,0)
and (2,0). Therefore, all cells in row
0,1,2 are and column 0 are modified to 1. 

Your Task:
You dont need to read input or print anything. Complete the function booleanMatrix() that takes the matrix as input parameter and modifies it in-place.
Expected Time Complexity: O(R * C)
Expected Auxiliary Space: O(R + C) 
*/

void booleanMatrix(vector<vector<int> > &mat)
    {
        int r=mat.size(),c=mat[0].size();
        int row=0,col=0;
    for(int i=0;i<r;i++)
    {
        if(mat[i][0]==1)
        col=1;
    }
    for(int i=0;i<c;i++)
    {
        if(mat[0][i]==1)
        row=1;
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(mat[i][j]==1)
            {
                mat[0][j]=1;
                mat[i][0]=1;
            }
        }
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(mat[i][0]==1||mat[0][j]==1)
                mat[i][j]=1;
        }
    }
    if(row)
    for(int i=0;i<c;i++)
        mat[0][i]=1;
    if(col)
    for(int i=0;i<r;i++)
        mat[i][0]=1;
     
    }