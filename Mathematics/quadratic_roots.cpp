/*
Given a quadratic equation in the form ax2 + bx + c. Find its roots.

Note: Return the maximum root followed by the minimum root.

Example 1:

Input:
a = 1
b = -2
c = 1
Output: 1 1
Explanation:
Roots of equation x2-2x+1 are 1 and 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) 
    {
        vector<int> root;
        long long d=(b*b-4*a*c);
        if(d<0)
        root.push_back(-1);
        else
        {
        int p=(floor((-b+sqrt(d))/(2*a)));
        int q=(floor((-b-sqrt(d))/(2*a)));
        if(p>q)
        {
            root.push_back(p);
            root.push_back(q);
        }
        else
        {
            root.push_back(q);
            root.push_back(p);
        }
        }
        return root;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  