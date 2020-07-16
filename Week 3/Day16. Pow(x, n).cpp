/*

Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

*/

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0) return (double)1.0;
        
        if(n==1) return x;
        bool flag=0;
        if(n<0) 
        {
            flag=1;
            n=abs(n);
        }
        if(n%2==0) 
        {
            double k=myPow(x,n/2);
            if(flag) return (1/(k*k));
            else return k*k;
        }
    
        if(flag) return 1/(myPow(x,n/2)*myPow(x,n/2 +1));
        
        return myPow(x,n/2)*myPow(x,n/2 +1);
    
        
    }
};