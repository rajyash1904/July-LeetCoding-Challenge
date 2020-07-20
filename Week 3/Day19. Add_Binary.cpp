/*

Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1. Each string consists only of '0' or '1' characters.
2. 1 <= a.length, b.length <= 10^4
3. Each string is either "0" or doesn't contain any leading zero.

*/

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n=a.size();
        int m=b.size();
        string sol;
        int i=n-1;
        int j=m-1;
        int carry=0;
        while(i>=0 || j>=0)
        {
            int k=0;
            if(i>=0)
            {
                if(a[i]=='1')
                    k+=1;
                i--;
            }
            if(j>=0)
            {
                if(b[j]=='1')
                    k+=1;
                j--;
            }
            k+=carry;
            
            switch (k)
            {
                case 0:
                    sol.insert(sol.begin(),'0');
                    carry=0;
                    break;
                case 1: 
                    sol.insert(sol.begin(),'1');
                    carry=0;
                    break;
                case 2:
                    sol.insert(sol.begin(),'0');
                    carry=1;
                    break;
                case 3:
                    sol.insert(sol.begin(),'1');
                    carry=1;
                    break;
            }
        }
        
        if(carry==1) sol.insert(sol.begin(),'1');
        return sol;
    }
};