#include<iostream>
#include<set>
#include <unordered_map>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}

int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high) {
            int mid = (low + high)/ 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid+1;
        }
        return ans;
}

int upperBound(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// Search Insertion position.
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high) {
    int mid = (low + high) / 2;

    if (nums[mid] >= target) {
        ans = mid;
        high = mid-1;
    }
    else low = mid+1;
    }
    return ans;  
}


vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int floor = -1;
    int ceil = -1;

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == x) {
            floor = nums[mid];
            ceil = nums[mid];
            break;
        }
        else if (nums[mid] < x) {
            floor = nums[mid];
            low = mid + 1;
        }
        else {
            ceil = nums[mid];
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

// 34. Find First and Last Position of Element in Sorted Array
int lower_bound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

int upperBound(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int x) {
    int n = nums.size();
    int lb = lower_bound(nums, x);
    // x = Target.
    if (lb == n || nums[lb] != x) {
        return {-1, -1};
    }
    return {lb, upperBound(nums, x) - 1};
}

int first_occurence(vector<int>& arr, int n, int target) {
        int low = 0;
        int high = n-1;
        int first = -1;

        while (low <= high) {
            int mid = (low+high)/2;

            if (arr[mid] == target) {
                first = mid;
                high = mid-1;
            }
            else if (arr[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return first;
    }
int last_occurence(vector<int>& arr, int n, int target) {
    int low = 0;
    int high = n-1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] == target) {
            last = mid;
            low = mid+1;
        }
        else if (arr[mid] > target) high = mid-1;
        else {
            low = mid+1;
        }
    }
    return last;
}
pair<int, int> firstAndlastPosition(vector<int>& arr, int n, int target){
    int first = first_occurence(arr, n, target);
    if (first == -1) return {-1, -1};
    int last = last_occurence(arr, n, target);

    return {first, last};
}
int countOccurrences(vector<int>& arr, int target) {
    int n = arr.size();
    pair<int, int> answer = firstAndlastPosition(arr, n, target);
    if (answer.first == -1) return 0;
    else {
        return (answer.second - answer.first)+1;
    }
}

// 33. Search in Rotated Sorted Array --> without duplicates.
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = (low+high)/2;
        if (nums[mid] == target) return mid;

        else if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        else {
            if (target >= nums[mid] && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

bool search_2(vector<int>& nums, int target) {
    int low = 0;
    int n = nums.size();
    int high = n-1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (nums[mid] == target) return true;

        if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
            high--;
            low++;
            continue;
        }
        
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target <= nums[mid]) high = mid-1;
            else low = mid+1;
        }

        else {
            if (target >= nums[mid] && target <= nums[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return false;
}

 // 153. Find Minimum in Rotated Sorted Array
int findMin(vector<int>& nums) {
    int low = 0;
    int n = nums.size();
    int high = n-1;

    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low+high)/2;

        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]);
            low = mid+1;
        }
        else {
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}

// Find out how many times the array is rotated
int findKRotation(vector<int> &nums)  {
    int low = 0;
    int n = nums.size();
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (nums[low] <= nums[high]) {
            if (nums[low] < ans) {
                ans = nums[low];
                index = low;
            }
        }

        else if (nums[low] <= nums[mid]) {
            if (nums[low] < ans) {
                ans = nums[low];
                index = low;
            }
            low = mid+1;
        }

        else {
            if (nums[mid] < ans) {
                ans = nums[mid];
                index = mid;
            }
            high = mid-1;
        }
    }
    return index;
}

// 540. Single Element in a Sorted Array
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n-2;

    while (low <= high) {
        int mid = (low + high)/2;

        if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return nums[mid];

        // the element is on the right side, eliminate the left side.
        if ((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1])) {
            low = mid+1;
        } 
        
        // the element is on the left side. eliminate the right side.
        else {
            high = mid-1;
        }
    }
    return -1;
}

// peak element.
int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;

        while (low <= high) {
            int mid = (low+high)/2;

            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;

            else if (nums[mid] > nums[mid-1]) {
                low = mid+1;
            }
            else if (nums[mid] > nums[mid+1]) {
                high = mid-1;
            }
            else high = mid-1;
        }
        return -1;
    }

// 852. Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int res = 0;

        while (low<=high) {
            int mid = (low+high)/2;
            if (arr[mid] < arr[mid+1]) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};

// koko eating banana - 875.
class Solution {
public:
    int Max_ele(vector<int>& piles) {
        int n = piles.size();
        int maxi = -1;
        for(int i=0; i<=n-1; i++) {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    long long banana_eating_speed(vector<int>& piles, int mid) {
        int n = piles.size();
        long long total_hour = 0;
        for (int i=0; i<=n-1; i++) {
            total_hour += ceil(double(piles[i])/double(mid));
        }
        return total_hour;
    }

class Solution {
public:
    bool checking_speed(vector<int>& piles, int mid, int h) {
        int n = piles.size();
        long long hr = 0;
        for (int i=0; i<n; i++) {
            hr+= piles[i]/mid;
            if (piles[i]%mid != 0) hr++;   
        }
        if (hr <= h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_ele = INT_MIN;
        for (int i=0; i<n; i++) {
            max_ele = max(piles[i], max_ele);
        }

        int high = max_ele;
        int low = 1;
        int min_sp = INT_MAX;
        
        while (high>=low) {
            int mid = (high+low)/2;
            bool check = checking_speed(piles, mid, h);
            if (check == true) {
                min_sp = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return min_sp;
    }
};


class Solution {
public:
    bool is_possible(vector<int>& bloomDay, int day, int k, int m) {
        int n = bloomDay.size();
        int cnt = 0;
        int num_bags = 0;

        for (int i=0; i<=n-1; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            }
            else {
                num_bags += cnt/k;
                cnt = 0;
            }
        }
        num_bags += cnt/k;
        if (num_bags >= m) return true;
        else return false;
    }
    int min_val(vector<int>& bloomDay) {
        int mini = INT_MAX;
        int n = bloomDay.size();

        for (int i=0; i<=n-1; i++) {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }

    int max_val(vector<int>& bloomDay) {
        int n = bloomDay.size();
        int maxi = INT_MIN;

        for (int i=0; i<=n-1; i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }

    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long n = bloomDay.size();
        if (m*k > n) return -1;

        int low = min_val(bloomDay);
        int high = max_val(bloomDay);
        int ans = -1;

        while (low<=high) {
            int mid = (low+high)/2;
            if (is_possible(bloomDay, mid, k, m) == true) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// GFG - agressive cows.
class Solution {
  public:
    bool check_dist(vector<int>& arr, int mid, int k) {
        int n = arr.size();
        int cow_cnt = k-1;
        int diff = 0;
        int pres_cow = arr[0];
        for (int i=1; i<n; i++) {
            diff = abs(arr[i] - pres_cow);
            if (diff >= mid) {
                cow_cnt--;
                pres_cow = arr[i];
            }
        }
        if (cow_cnt <= 0) return true;
        return false;
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int res = 0;
        for (int i=0; i<n; i++) {
            mini = min(mini, arr[i]);
        }
        for (int i=0; i<n; i++) {
            maxi = max(maxi, arr[i]);
        }
        
        int low = 0;
        int high = maxi- mini;
        
        while (high>=low) {
            int mid = (high+low)/2;
            if (check_dist(arr, mid, k) == true) {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};

class Solution {
  public:
    long long highest_ele(vector<int>& arr) {
        long long total_pages = 0;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            total_pages+= arr[i];
        }
        return total_pages;
    }
    
    int max_ele(vector<int>& arr) {
        int max_val = INT_MIN;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            max_val = max(max_val, arr[i]);
        }
        return max_val;
    }
    
    bool check_valid(vector<int>& arr, long long mid, int k) {
        int num_stu = 1;
        long long sum = 0;
        int n = arr.size();
        
        for (int i=0; i<n; i++) {
            sum+= arr[i];
            if (sum > mid) {
                num_stu++;
                sum = arr[i];
            }
        }
        if (num_stu > k) return false;
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        long long res = -1;
        if (k > n) return -1;
        long long low = max_ele(arr);
        long long high = highest_ele(arr);
        
        while (high >= low) {
            long long mid = (high + low)/2;
            bool check = check_valid(arr, mid, k);
            if (check == false) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};