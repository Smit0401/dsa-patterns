class Solution {
public:
    int maxElement(vector<int>& piles){
        int maxi = -1;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>maxi) maxi = piles[i];
        }
        return maxi;
    }
    bool canEat(vector<int>& piles, int k, int h){
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            hours = hours + ceil((double)piles[i]/(double)k);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles);
        int ans = high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(canEat(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
