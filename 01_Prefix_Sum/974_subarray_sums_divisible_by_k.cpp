// 974. Subarray Sums Divisible by K
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap
// Time: O(n)
// Space: O(n)


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;   // base case

    int sum = 0;
    int count = 0;

    for (int x : nums) {
        sum += x;
        int rem = sum % k;
        if (rem < 0) rem += k;
        if (mp.find(rem) != mp.end()) {
            count += mp[rem];
        }

        mp[rem]++;
    }

    return count;
    }
};

