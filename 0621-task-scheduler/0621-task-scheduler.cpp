class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freqMap;
        for(auto task:tasks){
            freqMap[task]++;
        }

        priority_queue<pair<int,char>,vector<pair<int,char> >>maxHeap;
        
        for(auto e:freqMap){
            maxHeap.push({e.second,e.first});
        }
        int time=0;
        while(!maxHeap.empty()){
            int cycle=n+1;
            vector<pair<int,char>>temp;

            while(cycle > 0&& !maxHeap.empty()){
                auto [freq,ch]=maxHeap.top();maxHeap.pop();

                freq--;
                cycle--;
                time++;

                temp.push_back({freq,ch});
            }
            for(auto lefttask:temp){
                if(lefttask.first>0){
                    maxHeap.push(lefttask);
                }
            }
            if(!maxHeap.empty()){
                time+=cycle;
            }
        }
        return time;
    }
};