class Solution {
public:

    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i] = !st.empty()?st.top():n;
            st.push(i);
        }
        return ans;
    }

    vector<int> PSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]> arr[i]) st.pop();
            ans[i] = !st.empty()?st.top():-1;
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for(int i = 0;i<n;i++){
            int left = i - psee[i];
            int right = nse[i]- i;
            int value = (1LL * left * right * arr[i])%mod;
            sum = (sum + value)%mod;
        }
        return sum;
    }
};