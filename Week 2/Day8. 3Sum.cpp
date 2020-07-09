/*

3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
   Hide Hint #1  
So, we essentially need to find three numbers x, y, and z such that they add up to the given value. 
If we fix one of the numbers say x, we are left with the two-sum problem at hand!
   
   Hide Hint #2  
For the two-sum problem, if we fix one of the numbers, say x
, we have to scan the entire array to find the next number y ,which is value - x
where value is the input parameter. Can we change our array somehow so that this search becomes faster?
   
   Hide Hint #3  
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? 
Like maybe a hash map to speed up the search?

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=i+1;
        int k=n-1;
        vector<vector<int>> sol;
        if(n<3) return sol;
        while(nums[i]<=0 && i<n-2)
        {
            j=i+1;
            k=n-1;
            int sum=(-1)*nums[i];
            //vector<int> curr;
            //curr.push_back(nums[i]);
            while(j<k)
            {
                int tot=nums[j]+nums[k];
                if(tot==sum)
                {
                    sol.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
                else if(tot>sum) k--;
                else j++;
            }
            i++;
            while(i<n-2 && nums[i]==nums[i-1]) i++;
        }
        return sol;    
    }
};