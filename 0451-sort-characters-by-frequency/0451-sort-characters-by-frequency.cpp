class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto &x : s){
            mpp[x]++;
        }
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        string res ="";
        for(auto &x : vec){
            res.append(x.second,x.first);
        }
        return res;
    }
};