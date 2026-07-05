#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  for (int i=0; i<nums.size(); i++) {
    for (int j=i+1; j<nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
            return {i,j};
        }
    }
  }
  return {};
}

void sortColors_012s(vector<int>& nums) {
    int cnt_zero = 0;
    int cnt_one = 0;
    int cnt_two = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == 0) cnt_zero++;
        if (nums[i] == 1) cnt_one++;
        if (nums[i] == 2) cnt_two++;
    }
    for (int i=0; i<cnt_zero; i++) {
        nums[i] = 0;
    }
    for (int i=cnt_zero; i<cnt_zero+cnt_one; i++) {
        nums[i] = 1;
    }
    for (int i=cnt_zero+cnt_one; i<nums.size(); i++) {
        nums[i] = 2;
    }
}
// optimized way of sorting 0s,1s and 2s --> Dutch National Flag Algorithm.
void sortColors(vector<int>& nums) {
  int n = nums.size();
  int mid = 0;
  int low = 0;
  int high = n-1;

  while (mid <= high) {
      if (nums[mid] == 0) {
          swap(nums[mid], nums[low]);
          mid++, low++;
      }
      else if (nums[mid] == 1) {
          mid++;
      }
      else { // 2.
          swap(nums[mid],nums[high]);
          high--;
      }
  }
}

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for (int value=0; value<n; value++) {
        int frequency = 0;
        for (int num=0; num<n; num++) {
            if (nums[num] == nums[value]) {
                frequency++;
            }
        }
        if (frequency > n/2) {
            return nums[value];
        }
    }
    return -1;
}

// optimized sol
int majorityElement(vector<int>& nums) {
    int freq = 0;
    int ans = 0; 
    for (int i=0; i<nums.size(); i++) {
        if (freq == 0) {
            ans = nums[i];
        }
        if (ans == nums[i]) {
            freq++;
        }
        else { // when ans is != nums[i].
            freq--;
        }
    }
    return ans;
}

int maxSubArray(vector<int>& nums) {
    // brute approach
    int n = nums.size();
    int max_sum = 0;
    for (int st=0; st<n; st++) {
        int cu_sum = 0;
        for (int end=st; end<n; end++) {
            cu_sum+=nums[end];
            max_sum = max(cu_sum, max_sum);
        }
    }
    return max_sum;
}

int maxSubArray(vector<int>& nums) {
    // kadane's algo --> most optimized
    int max_sum = INT_MIN;
    int curr_sum = 0;
    int n = nums.size();
    for (int i=0; i<n; i++) {
    curr_sum+=nums[i];
    max_sum = max(curr_sum,max_sum);
    if (curr_sum < 0) {
        curr_sum = 0;
    }
    }
    return max_sum; 
}

// Best time to buy and sell stocks.
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int best_buy = prices[0];
    int max_profit = 0;
    for (int i=1; i<n; i++) {
        if (prices[i] < best_buy) {
            best_buy = min(best_buy, prices[i]);
        }
        if (prices[i] > best_buy) {
            max_profit = max(max_profit, prices[i] - best_buy);
        }

    }
    return max_profit;
}

//Rearrange Array Elements by Sign.
vector<int> rearrangeArray(vector<int>& nums) {
   list<int> list_pos; // empty list.
   list<int> list_neg; // empty list.

    int n = nums.size();
    for (int num=0; num<n; num++) {
        if (nums[num]>=0) {
            list_pos.push_back(nums[num]);
        }
        else {
            list_neg.push_back(nums[num]);
        }
    }
        int i=0;
        for (int val : list_pos) {
            nums[i] = val;
            i += 2;
        }
        int y=1;
        for (int val : list_neg) {
            nums[y] = val;
            y += 2;
        }
        return nums;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = -1;
    for(int i=n-2; i>=0; i--) {
        if (nums[i] < nums[i+1]) {
            index = i;
            break;
        }
        else return reverse(nums.begin(), nums.end());
    }
        for (int i=n-1; i>=index+1; i--) {
            if (nums[i] > nums[index]) {
                swap (nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
}

// everything on the right of the element should be smaller.
vector<int> leaders(vector<int>& nums) {
    vector<int> ans;
    int leaders = INT_MIN;
    int n = nums.size();
    for (int i=n-1; i>=0; i--) {
        if (nums[i] > leaders) {
            leaders = nums[i];
            ans.push_back(nums[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int n = nums.size();
    int longest = 1;
    int lst_smaller = INT_MIN;
    int seq_cnt = 0;

    sort(nums.begin(), nums.end());

    for (int i=0; i<=n-1; i++) {
        if (nums[i] - 1 == lst_smaller) {
            seq_cnt++;
            lst_smaller = nums[i];
        }
        else if (nums[i] != lst_smaller) {
            seq_cnt = 1;
            lst_smaller = nums[i];
        }
        longest = max(longest, seq_cnt);
    }
    return longest;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i=0; i<n; i++) {
        st.insert(nums[i]);
    }

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

void setZeroes(vector<vector<int>>& matrix, int n, int m) {
    // better approach
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (row[i] ==1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    // int col[m] = matrix[0][..];
    // int row[n] = matrix[..][0];
    int col0 = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith row
                matrix[i][0] = 0;
                // mark jth row
                if (j != 0 ) {
                    matrix[0][j] = 0;
                    }
                else {
                    col0 = 0;
                }
            }
        }
    }
    for (int i=1; i<n; i++) {
    for (int j=1; j<m; j++) {
        if (matrix[i][j] != 0 ) {
            // check for col and row
            if (matrix[i][0]==0 || matrix[0][j]==0) {
                matrix[i][j] = 0;
            }
        } 
    }
    }
    if (matrix[0][0] == 0) {
    for (int j=0; j<m; j++) {
        matrix[0][j] = 0;
    }
    }
    if (col0 == 0) {
    for (int i=0; i<n; i++) {
        matrix[i][0] = 0;
    }
    }
}

// Rotate the matrix --> optimal approach.
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose of the matrix.
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reversing the rows of the matrix.
    for (int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(); // no. of rows.
    int n = matrix[0].size(); // no. of columns.
    vector<int> ans;

    int s_row = 0;
    int end_row = m-1;
    int s_col = 0;
    int end_col = n-1;

    while (s_row <= end_row && s_col <= end_col) {
        // top
        for (int j=s_col; j<=end_col; j++) {
            ans.push_back(matrix[s_row][j]);
        }
        // right
        for (int i=s_row+1; i<=end_row; i++) {
            ans.push_back(matrix[i][end_col]);
        }
        // Bottom
        for (int j=end_col-1; j>=s_col; j--) {
            if (s_row == end_row) {
                break;
            }
            ans.push_back(matrix[end_row][j]);
        }
        // left
        for (int i=end_row-1; i>=s_row+1; i--) {
            if (s_col == end_col) {
                break;
            }
            ans.push_back(matrix[i][s_col]);
        }

        s_row++;
        end_row--;
        s_col++;
        end_col--;
    }
    return ans;
}

// --> subarray sums equals K.
// brute force approach.
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for (int i=0; i<=n-1; i++) {
        int sum = 0;
        for (int j=i; j<=n-1; j++) {
            sum+=nums[j];
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

// 3sum-->leetcode
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        int n = nums.size();
        int i = 0;
        while (i<n-2) {
            int sum = -nums[i];

            if (i>0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }

            int j = i+1;
            int k = n-1;
            while (j<k) {
                if (nums[j] + nums[k] < sum) {
                    j++;
                }
                else if (nums[j] + nums[k] > sum) {
                    k--;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j<k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j<k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
            i++;
        }
        return res;
    }
};
// 3-closest sum

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0;
        int sum = 0;
        int diff = 0;
        int max_diff = INT_MAX;
        int res_sum = 0;

        while (i<n-2) {
            int j = i+1;
            int k = n-1;
            while (j<k) {
                sum = nums[i]+nums[j]+nums[k];
                if (sum == target) {
                    return sum;
                }
                else if (sum < target) {
                    j++;
                    diff = abs(sum - target);
                    if (diff <= max_diff) {
                        max_diff = diff;
                        res_sum = sum;
                    }
                }
                else {
                    k--;
                    diff = abs(sum - target);
                    if (diff <= max_diff) {
                        max_diff = diff;
                        res_sum = sum;
                    }
                }
            }
            i++;
        }
        return res_sum;
    }
};

int main () {
  int n; 
  cin >> n;
  int arr[n];
  for (int i=0; i<=n-1; i++) {
    cin >> arr[i];
  }
}