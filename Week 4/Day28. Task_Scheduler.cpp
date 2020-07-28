/*

Task Scheduler

You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

1. The number of tasks is in the range [1, 10000].
2. The integer n is in the range [0, 100].

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& t, int n) 
    {
        map<char,int> m;
        for(int i=0;i<t.size();i++)
        {
            m[t[i]]++;
        }

        priority_queue<int> pq;
        for(auto x :m)
        {
            pq.push(x.second);
        }
        int ans = 0;
        int cycle = n+1;
        while(!pq.empty())
        {
            vector<int> temp;
            int time = 0;
            for(int i=0;!pq.empty() && i<cycle;i++)
            {
                temp.push_back(pq.top());
                pq.pop();
                time++;
            }
            for(int i=0;i<temp.size();i++)
            {
                temp[i]--;
                if(temp[i]) pq.push(temp[i]);
            }
            ans+= pq.empty() ? time :cycle ;
        }
        return ans;
    }
};