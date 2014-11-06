/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int result[101][101] = {0};
        for (int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                        if ( result[i][j] > 0) continue;
                        if (i == 1 || j == 1){
                                result[i][j] = 1;
                        }       
                        else{   
                                result[i][j] = result[i][j-1] + result[i-1][j];
                        }       
                }       
        }       
        return result[m][n];
    } 
};
