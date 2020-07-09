/*

Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

https://assets.leetcode.com/uploads/2018/10/12/island.png

*/

class Solution {
public:
    int neighbour(vector<vector<int>>& grid,int i,int j)
    {
        int count=0;
        if(i>0 && grid[i-1][j]) count++;
        if(j>0 && grid[i][j-1]) count++;
        if(i<grid.size()-1 && grid[i+1][j]) count++;
        if(j<grid[i].size()-1 && grid[i][j+1]) count++;
        
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int peri=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    peri+=4- neighbour(grid,i,j);
                }
            }
        }
        return peri;
    }
};