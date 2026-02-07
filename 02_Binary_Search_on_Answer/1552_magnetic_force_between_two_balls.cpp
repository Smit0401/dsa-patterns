// 1552. Magnetic Force Between Two Balls
// Difficulty: Medium
// Pattern: Binary Search on Answer
// Time: O(n log range)
// Space: O(1)

class Solution {
public:
    bool canDistribute(vector<int>& position, int m , int F){
        int count = 1;
        int last = position[0];
        for(int i=0;i<position.size();i++){
            if((position[i]-last) >= F){
                count++;
                last = position[i];
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position.back() - position.front();
        int ans = 0;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(canDistribute(position,m,mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
