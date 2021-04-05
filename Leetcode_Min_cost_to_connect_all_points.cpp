class Solution {
public:
    struct edge {
        int a;
        int b;
        int wt;
    };
    
    struct mycmp{
      bool operator()(edge &a, edge &b){
          return a.wt > b.wt;
      }  
    };

    
   int find(int a){
        if(parent[a] == -1)return a;
        return parent[a] = find(parent[a]);
    }
    
    priority_queue<edge, vector<edge>, mycmp> minH;
    int parent[1000001];
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                edge e = {i,j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) };
                minH.push(e);
            }
        }
        
        for(int i=0; i<n; i++)parent[i] = -1;
         
        int a,b,s=0,ans=0;                        
    
        while(s < n-1){
            edge curr = minH.top();minH.pop();
            a = find(curr.a);
            b = find(curr.b);
            
            if(a != b){
                ans+= curr.wt;
                parent[a] = b;
                s++;
            }
        }
        
        return ans;
                              
    }
};