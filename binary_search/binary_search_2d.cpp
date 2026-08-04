class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = m-1;
        int col = 0;
        while (row >= 0 && col <= n-1) {
            int search_num = matrix[row][col];
            if (search_num == target) return true;
            else if(search_num < target) col++;
            else row--;
        }
        return false;
    }
};


class Solution {
public:
    int number_count(vector<vector<int>>& matrix, int guess) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = m-1;
        int col = 0;
        int num_cnt = 0;

        while (row >= 0 && col <= n-1) {
            int search_index = matrix[row][col];
            if (search_index > guess) row--;
            else if (search_index <= guess) {
                num_cnt+= row+1;
                col++;
            }
        }
        return num_cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;
        int low = matrix[0][0];
        int high = matrix[m-1][n-1];

        while (high >= low) {
            int guess = (high + low)/2;
            int count = number_count(matrix, guess);
            if (count < k) low = guess+1;
            else {
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};