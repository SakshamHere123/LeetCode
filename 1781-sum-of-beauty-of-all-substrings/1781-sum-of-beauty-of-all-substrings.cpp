class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans=0;
        for(int i = 0;i<n;i++){
            vector<int> freq(256,0);
            for(int j = i;j<n;j++){
                freq[s[j]-'a']++;

                int maxi = 0, mini =INT_MAX;
                for(auto &f : freq){
                    if(f>0){
                        maxi = max(maxi,f);
                        mini = min(mini,f);
                    }
                } 
                ans += maxi-mini;
            }
        }
        return ans;
    }
};