// 493. Reverse Pairs
// Pattern: Merge Sort + Counting
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int merge(vector<int>& nums, int st, int mid, int end) {
        int count = 0;
        int j = mid + 1;

        // Step 1: Count reverse pairs
        for (int i = st; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Step 2: Merge the two sorted halves
        vector<int> temp;
        int i = st;
        j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= end) temp.push_back(nums[j++]);

        for (int k = st; k <= end; k++) {
            nums[k] = temp[k - st];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;

        int left = mergeSort(nums, st, mid);
        int right = mergeSort(nums, mid + 1, end);
        int cross = merge(nums, st, mid, end);

        return left + right + cross;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
