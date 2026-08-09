class Solution {
public:

    int findMax(vector<int> &v){
        int n = v.size();
        int maxi = INT_MIN;
        for(int i = 0; i< n; i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }

    long long calcTotalHrs(vector<int> &v, int h){
        long long totalHrs = 0;
        int n = v.size();
        for(int i = 0; i< n;i++){
            totalHrs += ceil((double)(v[i])/(double)(h));
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while(low<=high){
            int mid = (low + high)/2;
            long long totalH = calcTotalHrs(piles,mid);
            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};