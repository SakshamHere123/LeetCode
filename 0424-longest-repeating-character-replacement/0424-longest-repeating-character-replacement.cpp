class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,maxlen = 0, c= 0;
        vector<int> freq(26,0);

        for(int r = 0; r < s.length();r++){
            freq[s[r]-'A']++;
            c = max(c, freq[s[r]-'A']);
            while((r-l+1)-c > k){   
                freq[s[l]-'A']--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};