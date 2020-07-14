/*

Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    void help(vector<int> &A,vector<vector<int>> &sol,vector<int> curr,int k)
    {
        if(k>=A.size()){
            return;
        }else{
            for(int i=k;i<A.size();i++){
                curr.push_back(A[i]);
                sol.push_back(curr);
                help(A,sol,curr,i+1);
                curr.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& A) 
    {
        vector<vector<int>> sol;
        vector<int> curr;
        sol.push_back(curr);
        if(A.size()==0) return sol;
        //sort(A.begin(),A.end());
        help(A,sol,curr,0);
        return sol;
        
    }
};