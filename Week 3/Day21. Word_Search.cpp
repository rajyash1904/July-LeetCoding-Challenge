/*

Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

class Solution {
public:
     bool isSafe(int N, int M, int i, int j){
        return (i<N) && (i>=0) && (j>=0) && (j<M);
    }
    bool backtrack(vector<vector<char>>& board,string& word,int pos,int i,int j)
    {
        if(word[pos]!=board[i][j]){
            return false;
        }
        if(pos==word.length()-1){
            return true;
        }
		// to avoid using of this character again in the backtracking
        board[i][j] = '#';
        if(isSafe(board.size(), board[0].size(), i+1, j)){
            if(backtrack(board, word, pos+1, i+1, j))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i-1, j)){
            if(backtrack(board, word, pos+1, i-1, j))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i, j+1)){
            if(backtrack(board, word, pos+1, i, j+1))
                return true;
        }
        if(isSafe(board.size(), board[0].size(), i, j-1)){
            if(backtrack(board, word, pos+1, i, j-1))
                return true;
        }
		// Reassigning the character as backtracking is complete.
        board[i][j] = word[pos];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0])
                    if(backtrack(board, word, 0, i, j))
                        return true;
            }
        }
        return false;
    }
};