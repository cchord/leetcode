// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// For example,
// Given board =
//
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include "gtest/gtest.h"

#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<vector<char>>* board_;
    int r_ = 0;
    int c_ = 0;
  public:
    bool exist(vector<vector<char>>& board, string word) {
        r_ = board.size();
        if (!r_)
            return false;
        c_ = board[0].size();
        if (!c_)
            return false;
        board_ = &board;
        for (int i = 0; i < r_; ++i)
            for (int j = 0; j < c_; ++j)
                if(dfs(i, j, word.begin(), word.end()))
                    return true;
        return false;
    }

    bool dfs(int i, int j, string::iterator b, string::iterator e) {
        if (i < 0 || i >= r_ || j < 0 || j >= c_)
            return false;

        if (*b != (*board_)[i][j])
            return false;

        if (e - b == 1)
            return true;

        (*board_)[i][j] = '#';
        auto exist = dfs(i-1, j, b+1, e) || dfs(i+1, j, b+1, e) ||
                     dfs(i, j-1, b+1, e) || dfs(i, j+1, b+1, e);
        (*board_)[i][j] = *b;
        return exist;
    }
};

#include <iostream>

TEST(WordSearch, 1) {
    Solution s;
    vector<vector<char>> board{ {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
}
