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

