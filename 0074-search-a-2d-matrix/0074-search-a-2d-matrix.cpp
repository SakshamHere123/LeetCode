class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target){
                high = mid - 1;
            }
            else{
                ans = mid;
                low = mid + 1;
            }
        }
        if(ans==-1) return false;
        int idx = ans;
        low = 0;
        high = m -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(matrix[idx][mid]==target) return true;
            if(matrix[idx][mid]>target){
                high = mid - 1;
            }
            else{
                ans = mid;
                low = mid + 1;
            }
        }
        return false;
    }
};