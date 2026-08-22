class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mpp;
        for(int i = 0; i< tasks.size();i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it : mpp){
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle = n+1;
            int taskDone = 0;
            while(taskDone<cycle && !pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                if(freq>0){
                    temp.push_back(freq);
                }
                time++;
                taskDone++;
            }
            if(!temp.empty()){
                for(int it : temp){
                    pq.push(it);
                }
            }
            if(!pq.empty()){
                time+=cycle-taskDone;
            }
        }
        return time;
    }
};