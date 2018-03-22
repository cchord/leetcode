// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
// // For example,
// Given words = ["oath","pea","eat","rain"] and board =
//
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].

#include "gtest/gtest.h"

#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

namespace {

class Solution {
    vector<vector<char>>* board_;
    int r_ = 0;
    int c_ = 0;

    vector<string> res;

    struct TrieNode {
        TrieNode* children[26] = {0};
        string word;
    };

    TrieNode *root_ = new TrieNode();

    void buildTrie(vector<string>& words) {
        for (auto &w : words) {
            TrieNode *cur = root_;
            for (auto &c : w) {
                int i = c-'a';
                if (!cur->children[i])
                    cur->children[i] = new TrieNode();
                cur = cur->children[i];
            }
            cur->word = w;
        }
    }

    void dfs(int i, int j, TrieNode *n) {
        if (i < 0 || i >= r_ || j < 0 || j >= c_ || !n)
            return;
        char c = (*board_)[i][j];
        if (c == '#')
            return;
        if (!n->children[c-'a'])
            return;
        auto child = n->children[c-'a'];
        if(!child->word.empty()) {
            res.push_back(child->word);
            child->word = "";
        }

        (*board_)[i][j] = '#';
        dfs(i-1, j, child);
        dfs(i+1, j, child);
        dfs(i, j-1, child);
        dfs(i, j+1, child);
        (*board_)[i][j] = c;
    }

  public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r_ = board.size();
        if (!r_)
            return res;
        c_ = board[0].size();
        if (!c_)
            return res;
        if (words.size() == 0)
            return res;
        board_ = &board;

        buildTrie(words);
        for (int i = 0; i < r_; ++i)
            for (int j = 0; j < c_; ++j)
                dfs(i,j,root_);

        return res;
    }
};

TEST(WordSearch2, 1) {
    Solution s;
    vector<vector<char>> board{ {'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'} };
    vector<string> words{"eat", "oath"};
    auto res = s.findWords(board, words);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
}

}
