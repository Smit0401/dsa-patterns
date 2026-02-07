// 410. Split Array Largest Sum
// Difficulty: Hard
// Pattern: Binary Search on Answer
// Time: O(n log sum)
// Space: O(1)

// Minimize the maximum 
class Solution {
public:
    int maxElement(vector<int>& nums){
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
        }
        return maxi;
    }
    int sum(vector<int>& nums){
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        return s;
    }
    bool isPossible(vector<int>& nums, int num, int k){
        int sum = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > num){
                sum = nums[i];
                count++;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = maxElement(nums);
        int high = sum(nums);
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(nums,mid,k)){
                ans = mid;
                high = mid - 1;
                
            }
            else low = mid + 1;
        }
        return ans;
    }
};
