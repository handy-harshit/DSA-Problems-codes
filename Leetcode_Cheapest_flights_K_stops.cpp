class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minH;
        
        minH.push(make_tuple(0,src,0));  // cost,node,stops;
        
        while(!minH.empty()){
            auto [cost,node,stops] = minH.top(); minH.pop();
            
            if(node == dst) return cost;
            
            if(stops > K)continue;           //as te (k+1)th will be the dest. node ,therefore we will not push further ancestor of those node whose stops value will be greater than k
            for(auto child : adj[node]){
                auto [v,w] = child;
                minH.push(make_tuple(cost+w, v, stops+1));
            }
        }
        
        return -1;
    }
};