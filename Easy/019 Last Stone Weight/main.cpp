class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max Heap
        priority_queue<int, vector<int> > pq;
        for(auto stone: stones) pq.push(stone);
        int x, y, diff;
        while(pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x!=y) {
                diff = y-x;
                if(diff<0) diff *= -1;
                pq.push(diff);
            }
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};