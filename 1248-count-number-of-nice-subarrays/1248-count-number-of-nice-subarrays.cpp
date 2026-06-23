class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }

    int atmost(vector<int>& nums, int k) {
        int l = 0, c = 0,ans = 0;
        for(int r = 0; r<nums.size();r++){
            if(nums[r]%2!=0){
                c++;
            }
            while(c>k){
                if(nums[l]%2!=0){
                    c--;
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};