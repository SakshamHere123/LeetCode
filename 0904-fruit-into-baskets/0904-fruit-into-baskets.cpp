class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int n = fruits.size();
        int l = 0;
        int len = 0, maxi = INT_MIN;
        for(int r = 0;r<n;r++){
            basket[fruits[r]]++;
            while(basket.size()>2){
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            len = r - l + 1;
            maxi = max(maxi, len);
        }
    return maxi;
    }
};