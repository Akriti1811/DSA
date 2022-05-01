/*
Infix to Postfix 
Easy Accuracy: 51.65% Submissions: 18473 Points: 2
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 ≤ |str| ≤ 105

*/

string infixToPostfix(string s) 
    {
        map<char,int> m {{'+',1},{'-',1},{'*',2},{'/',2},{'^',3}};
        stack<char>st;
        st.push('(');
        string p="";
        s+=')';
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            st.push(s[i]);
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    p+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
            {
                char ch=st.top();
                while(!st.empty() && st.top()!='(' && m[s[i]]<=m[ch])
                {
                    p+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else
            p+=s[i];
        }
        return p;
    }