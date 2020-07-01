/*

Arranging Coins

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

/*
*Solution 1
*Time: O(N)
*Space:O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int i = 1;
        while(n) {
            n = n - i;
            if(n < 0) {
                break;
            }
            count++;
            i = i + 1;
        }
        return count;
    }
};

/*
*Solution 2
*Time: O(1)
*Space:O(1)
*/

class Solution {
public:
    int arrangeCoins(int n) 
    {
        return static_cast<int>(1.4142135623730951454746218587388284504413604736328125 * sqrt(0.125 + n) - 0.5);
    }
};