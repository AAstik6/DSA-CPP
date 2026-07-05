#include<iostream>
#include<vector>
using namespace std;

int floorSqrt(int n)  {
    if (n==0) return 0;
    long long low = 1;
    long long high = n;
    long long ans = -1;
    while (low<=high) {
        long long mid = (low+high)/2;

        if (mid*mid <= n) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}


// 875. Koko Eating Bananas
int Find_max_ele(vector<int>& piles) {
    int n = piles.size();
    int max_val = -1;
    for (int i=0; i<=n-1; i++) {
        max_val = max(max_val, piles[i]);
    }
    return max_val;
}

long long Calculate_total_hours(vector<int>& piles, int hour) {
    long long total_hour = 0;
    int n = piles.size();
    for (int i=0; i<=n-1; i++) {
        total_hour += ceil(double(piles[i])/double(hour));
    }
    return total_hour;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = Find_max_ele(piles);
    int ans = INT_MAX;

    while(low<=high) {
        int mid = (low+high)/2;
        long long total_hour = Calculate_total_hours(piles, mid);

        if (total_hour <= h) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

// 1482. Minimum Number of Days to Make m Bouquets
bool is_possible(vector<int>& v, int m, int k, int day) {
    int num_bags = 0;
    int cnt = 0;
    int n = v.size();
    for (int i=0; i<=n-1; i++) {
        if (v[i] <= day) cnt++;
        else {
            num_bags += cnt/k;
            cnt = 0;
        }
    }
    num_bags += cnt/k;
    if (num_bags >= m) return true;
    else return false;
}

int min_ele(vector<int>& v) {
    int mini = INT_MAX;
    int n = v.size();
    for (int i=0; i<=n-1; i++) {
        mini = min(mini, v[i]);
    }
    return mini;
}

int max_ele(vector<int>& v) {
    int n = v.size();
    int maxi = -1;
    for (int i=0; i<=n-1; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int minDays(vector<int>& bloomDay, long long m, long k) {
    int ans = -1;
    int n = bloomDay.size();

    if (n < m*k) return -1;

    int low = min_ele(bloomDay);
    int high = max_ele(bloomDay);

    while(low<=high) {
        int mid = (low+high)/2;
        if(is_possible(bloomDay, m, k, mid) == true) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

class Solution {
public:

    int largest_num(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int sum_of_d(vector<int>& nums, int mid) {
        int sum_of_div = 0;
        int n = nums.size();
        for (int i=0; i<=n-1; i++) {
            sum_of_div += (nums[i] + mid -1)/mid;
        }
        return sum_of_div;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = largest_num(nums);
        long long smallest_div = -1;

        while (low <= high) {
            int mid = (low + high)/2;
            int result = 0;

            if (sum_of_d(nums, mid) <= threshold) {
                smallest_div = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return smallest_div;
    }
};

// 1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    int Max_ele(vector<int>& weights) {
        int n = weights.size();
        int maxi = INT_MIN;
        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }

    int sum_wt(vector<int>& weights) {
        int n = weights.size();
        int sum = 0;
        for (int i=0; i<=n-1; i++) {
            sum += weights[i];
        }
        return sum;
    }

    int daysReq(vector<int>& weights, int mid) {
        int n = weights.size();
        int day = 1;
        int load = 0;
        for (int i=0; i<=n-1; i++) {
            if (load + weights[i] > mid) {
                day++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = Max_ele(weights);
        int high = sum_wt(weights);
        int ans = 0;

        while(low<=high) {
            int mid = (low+high)/2;
            if (daysReq(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

class Solution {
public:
    int Max_ele(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    bool can_we_place(vector<int> &nums, int k, int mid) {
        int n = nums.size();
        int cow_cnt = 1;
        int first_cow = nums[0];
        for (int i=1; i<=n-1; i++) {
            if (nums[i] - first_cow >= mid) {
                cow_cnt++;
                first_cow = nums[i];
            }
        }

            if (cow_cnt >= k) return true;
            else return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        // BS approach.
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums[n-1] - nums[0];
        int min_dist = 0;

        while (low <= high) {
            int mid = (low + high)/2;
            if (can_we_place(nums, k, mid) == true) {
                low = mid+1;
                min_dist = mid;
            }
            else high = mid-1;
        }
        return min_dist; // can also return high, as high points to the ans when the loop ends.
    }
};

// Book Allocation problem.
// Brute force
class Solution {
public:
    int max_ele(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int sum_of_ele(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0; i<=n-1; i++) {
            sum += nums[i];
        }
        return sum;
    }
    int is_possible(vector<int> &nums, int pages, int m) {
        int n = nums.size();
        int cnt_stu = 1;
        int total_pages = 0;

        for (int i=0; i<=n-1; i++) {
            if (total_pages + nums[i] <= pages) {
                total_pages+= nums[i];
            }
            else {
                cnt_stu++;
                total_pages = nums[i];
            }
        }
        return cnt_stu;
    }
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = max_ele(nums);
        int high = sum_of_ele(nums);
        if (m == 1) return high;
        if (m > n) return -1;

        for (int i=low; i<=high; i++) {
            int cnt_stu = is_possible(nums, i, m);
            if (cnt_stu <= m) return i;
        }
        return -1;
    }
};

// Book Allocation problem.
// BS approach.
class Solution {
public:
    int max_ele(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int sum_of_ele(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0; i<=n-1; i++) {
            sum += nums[i];
        }
        return sum;
    }
    bool is_possible(vector<int> &nums, int pages, int m) {
        int n = nums.size();
        int cnt_stu = 1;
        int total_pages = 0;

        for (int i=0; i<=n-1; i++) {
            if (total_pages + nums[i] <= pages) {
                total_pages+= nums[i];
            }
            else {
                cnt_stu++;
                total_pages = nums[i];
            }
        }
        if (cnt_stu <= m) return true;
        else return false;
    }
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = max_ele(nums);
        int high = sum_of_ele(nums);
        int ans = -1;
        if (m == 1) return high;
        if (m > n) return -1;

        while (low <= high) {
            int mid = (low + high)/2;

            int cnt_student = is_possible(nums, mid, m);
            if (cnt_student == true) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// 410. Split Array Largest Sum
class Solution {
public:
    int max_ele(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int sum_of_ele(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i=0; i<=n-1; i++) {
            sum+=nums[i];
        }
        return sum;
    }
    bool max_min_sum(vector<int>& nums, int mid, int k) {
        int n = nums.size();
        int sum = 0;
        int cnt = 1;

        for(int i=0; i<=n-1; i++) {
            if (sum + nums[i] <= mid) {
                sum+=nums[i];
            }
            else {
                cnt++;
                sum = nums[i];
            }
        }
        if (cnt <= k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = max_ele(nums);
        int high = sum_of_ele(nums);
        int ans = 0;

        while(low<=high) {
            int mid = (low+high)/2;
            int cnt = max_min_sum(nums, mid, k);
            if (cnt == true) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};

// painters partioned prob.
class Solution {
public:
    long long max_ele(vector<int> &nums) {
        int n = nums.size();
        long long maxi = INT_MIN;

        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    long long sum_of_ele(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (int i=0; i<=n-1; i++) {
            sum+=nums[i];
        }
        return sum;
    }

    bool is_possible(vector<int>& nums, long long mid, int A) {
    int n = nums.size();
    int cnt_painter = 1;
    long long sum = 0;

    for(int i=0; i<=n-1; i++) {
        if (nums[i] + sum <= mid) {
            sum+=nums[i];
        }
        else {
            sum = nums[i];
            cnt_painter++;
        }
    }
    if (cnt_painter <= A) return true;
    else return false;
}

    long long paint(int A, long long B, vector<int>& nums) {
        // Your code goes here
        int n = nums.size();
        long long low = max_ele(nums);
        long long high = sum_of_ele(nums);
        long long ans = 0;

        if (A == 1) return sum_of_ele(nums) * B;

        while(low<=high) {
            long long mid = (low + high)/2;
            bool cnt_painter = is_possible(nums, mid, A);
            if (cnt_painter == true) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans * B;
    }
};

