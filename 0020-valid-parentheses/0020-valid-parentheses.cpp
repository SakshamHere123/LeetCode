class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size = s.size();
        if(size%2==1) return false;
        for(char x : s){
            if(x=='(' || x == '{' || x == '['){
                st.push(x);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((x==')' && ch =='(')||
                (x=='}' && ch =='{')||
                (x==']' && ch =='[')){
                    continue;
                }
                else return false;
            }
        }
        return st.empty();
    }
};