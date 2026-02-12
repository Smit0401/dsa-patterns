// 1614. Maximum Nesting Depth of Parentheses
// Difficulty: Easy
// Pattern: Depth Counter
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for(char c : s){
            if(c == '('){
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if(c == ')'){
                depth--;
            }
        }
        return maxDepth;
    }
};
