/*

All Paths From Source to Target

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

1. The number of nodes in the graph will be in the range [2, 15].
2. You can print different paths in any order, but you should keep the order of nodes inside one path.

*/

class Solution {
public:
    
    void help(vector<vector<int>> &g,vector<vector<int>> &sol,vector<int> curr,int k)
    {
        if(k==g.size()-1)
        {
            sol.push_back(curr);
            return;
        }
        
        for(auto x : g[k])
        {
            curr.push_back(x);
            help(g,sol,curr,x);
            curr.pop_back();
        }
        return;
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> sol;
        vector<int> curr;
        curr.push_back(0);
        help(graph,sol,curr,0);
        return sol;
    }
};