// 523. Continuous Subarray Sum
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap (Modulo)
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //if(nums.size()<=2) return false;
        bool flag = false;

        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(mp.find(rem)!=mp.end()){
                if(i - mp[rem] >= 2) flag = true;
                
            }
            else{
                mp[rem] = i;
            }
        }

        return flag;
    }
};
