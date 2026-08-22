class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int start = mp.begin()->first;
            for(int i = 0; i < groupSize;i++){    
                int card = start + i;
                if(mp.find(card)==mp.end()){
                    return false;
                }
                mp[card]--;
                if(mp[card]==0){
                    mp.erase(card);
                }
            }
        }
        return true;
    }
};