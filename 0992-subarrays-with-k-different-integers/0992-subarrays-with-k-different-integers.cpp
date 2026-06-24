class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums,k-1);
    }

     int atmost(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int c =0, l =0;
        for(int r = 0; r<nums.size();r++){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            c += (r-l+1);
        }
        return c;
    }
};