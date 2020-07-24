/*

Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other
elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

1. The order of the result is not important. So in the above example, [5, 3] is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant 
   space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        vector<int> sol;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto x : mp)
        {
            if(x.second==1) sol.push_back(x.first);
        }
        return sol;
    }
};