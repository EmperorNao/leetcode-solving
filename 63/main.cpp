/*
63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/description/

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> memory_;
    int m_;
    int n_;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m_ = obstacleGrid.size();
        n_ = obstacleGrid[0].size();
        memory_.clear();
        memory_.resize(m_);
        for (int rowidx = 0; rowidx < m_; ++rowidx) {
            memory_[rowidx].resize(n_);
            std::fill(memory_[rowidx].begin(), memory_[rowidx].end(), -1);
        }
        memory_[m_ - 1][n_ - 1] = 1;

        return findNumberOfPaths(obstacleGrid);
    }

    int findNumberOfPaths(vector<vector<int>>& obstacleGrid) {
        return find(obstacleGrid, 0, 0);
    }

    int find(vector<vector<int>>& obstacleGrid, int row, int col) {
        if (row >= m_ || col >= n_) {
            return 0;
        }
        if (obstacleGrid[row][col] == 1) {
            return 0;
        }
        if (memory_[row][col] == -1) {
            memory_[row][col] = find(obstacleGrid, row + 1, col) + find(obstacleGrid, row, col + 1);
        }
        return memory_[row][col];
    }
};

int main() {
  std::cout << "Solved!";
}
