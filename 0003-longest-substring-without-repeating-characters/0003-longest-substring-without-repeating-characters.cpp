class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(256,-1);
        int l = 0; 
        int r = 0; 
        int maxLen = 0;
        while(r<n){
            if(hash[s[r]]!=-1){
                l = max(hash[s[r]]+1,l);
            }
            int len = r - l +1;
            maxLen = max(len,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};