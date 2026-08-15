//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int bottom_up_2(string&s, int n) {
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0]=='0'?0:1;
        
        for(int i = 2; i<=n; i++) {            
            if(s[i-1] != '0')
                t[i] += t[i-1];
                
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                t[i] += t[i-2];
            
        }
        return t[n];
    }
    
    int numDecodings(string &s) {
        int n = s.length();
        vector<int> t(n+1, -1);
        return bottom_up_2(s, n);
    }
};