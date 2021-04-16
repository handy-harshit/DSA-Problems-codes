class Solution
{
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<pair<double,pair<int,int>>> maxH;
        
        for(int i=0; i<n; i++){
            maxH.push({((double)arr[i].value/arr[i].weight),{arr[i].value,arr[i].weight}});
        }
        
        double res =0;
        
        for(int i=0; i<n; i++){
            int curr_v = maxH.top().second.first;
            int curr_w = maxH.top().second.second;
            maxH.pop();
            
            if(curr_w <= W){
                W-=curr_w;
                res+= curr_v;
            }
            else {
                res+= curr_v * ((double)W/curr_w);
                return res;
            }
        }
        return res;
        
    }
        
};