class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    if(n==0) return ans;
    vector<int>current = intervals[0];

    for(int i=0;i<n;i++){
        if(intervals[i][0] <= current[1]){
            //overlapping case
            current[1]=max(current[1],intervals[i][1]);
        }
        else{
            ans.push_back(current);
            current=intervals[i];
        }
    }
    ans.push_back(current);
    return ans;

    }

};
