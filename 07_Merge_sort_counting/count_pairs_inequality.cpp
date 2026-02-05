// 2426. Number of Pairs Satisfying Inequality
// Pattern: Merge Sort + Counting
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    long long merge(vector<long long>& arr, int st, int mid, int end, int diff) {
        long long count = 0;
        int i = st;

        // Step 1: Count valid pairs
        for (int j = mid + 1; j <= end; j++) {
            while (i <= mid && arr[i] <= arr[j] + diff) {
                i++;
            }
            count += (i - st);
        }

        // Step 2: Merge two sorted halves
        vector<long long> temp;
        int p1 = st, p2 = mid + 1;

        while (p1 <= mid && p2 <= end) {
            if (arr[p1] <= arr[p2])
                temp.push_back(arr[p1++]);
            else
                temp.push_back(arr[p2++]);
        }

        while (p1 <= mid) temp.push_back(arr[p1++]);
        while (p2 <= end) temp.push_back(arr[p2++]);

        for (int i = st; i <= end; i++)
            arr[i] = temp[i - st];

        return count;
    }

    long long mergeSort(vector<long long>& arr, int st, int end, int diff) {
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;

        long long left = mergeSort(arr, st, mid, diff);
        long long right = mergeSort(arr, mid + 1, end, diff);
        long long cross = merge(arr, st, mid, end, diff);

        return left + right + cross;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> arr(n);

        // Step 0: transform the problem
        for (int i = 0; i < n; i++) {
            arr[i] = (long long)nums1[i] - nums2[i];
        }

        return mergeSort(arr, 0, n - 1, diff);
    }
};
