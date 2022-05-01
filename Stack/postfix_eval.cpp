/*
Evaluation of Postfix Expression 
Easy Accuracy: 53.28% Submissions: 32792 Points: 2
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105

0 ≤ |Si|≤ 9 (And given operators)

*/


int evaluatePostfix(string s)
    {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' )
            {
                int p=st.top()-'0';
                st.pop();
                int q=st.top()-'0';
                st.pop();
                
                int sum=0;
                if(s[i]=='+')
                sum=p+q;
                else if(s[i]=='-')
                sum=q-p;
                else if(s[i]=='*')
                sum=p*q;
                else
                sum=q/p;
                
                st.push(sum+'0');
            }
            else
            st.push(s[i]);
        }
        int res=st.top()-'0';
        return res;
    }