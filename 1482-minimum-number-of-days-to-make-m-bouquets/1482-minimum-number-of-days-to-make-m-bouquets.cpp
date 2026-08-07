class Solution {
public:

    bool isPossible(vector<int> &bloomDay, int day, int m , int k){
        int cnt = 0, noOfB = 0;
        for(auto &i : bloomDay){
            if(i<=day){
                cnt++;
                if(cnt == k){
                    noOfB++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }
        return noOfB>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        long long p = 1LL*m*k;
        if(n<p) return -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(isPossible(bloomDay,mid,m,k)){
                high = mid -1;
            }
            else {low = mid +1;}
        }
        return low;
    }
};