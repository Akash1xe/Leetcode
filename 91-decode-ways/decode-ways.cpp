/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HW-y3gvQTVQ
    Company Tags                : Facebook, Uber, Google, Facebook, Microsoft
    Leetcode Link               : https://leetcode.com/problems/decode-ways/
    Four approaches             : Memoized, Top Down, Better Top Down, O(1) space DP
*/

/************************************************************************ C++ ***************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(n) after memoization (without memoization - O(2^n)
//S.C : O(101) ~= O(1)
class Solution {
public:
    int t[101];
    int solve(int i, string &s, int &n) {
        if(t[i] != -1) {
            return t[i];
        }

        if(i == n) {
            return t[i] = 1; //one valid split done
        }

        if(s[i] == '0') {
            return t[i] = 0; //not possible to split
        }

        int result     = solve(i+1, s, n);
        
        if(i+1 < n) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                result += solve(i+2, s, n);
        }

        
        return t[i] = result;

    }

    int numDecodings(string s) {
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        return solve(0, s, n);
        

    }
};
