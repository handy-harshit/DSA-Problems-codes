class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    /*Done using Adjancy list & Greedy approch .. T.C = nlogn*/
    vector<int> JobScheduling(Job arr[], int n){ 
        vector < int > deadline[101];
        vector < int > ans;
        for(int i=0;i<n;i++) deadline[arr[i].dead].push_back(arr[i].profit);
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=1;i<=100;i++){
            for(int j=0;j<deadline[i].size();j++){
                if(minH.size()==i){
                    int x = minH.top();
                    if(x<deadline[i][j]){
                        minH.pop();
                        minH.push(deadline[i][j]);
                    }
                }
                else{
                    minH.push(deadline[i][j]);
                }
            }
        }
        int sum = 0;
        int jb = minH.size();
        while(!minH.empty()){
            sum += minH.top();
            minH.pop();
        }
        ans.push_back(jb);
        ans.push_back(sum);
        return ans;
    }
    
    /*copy solution takes n*maxdeadline */
    /*first correct ans of submissions*/
};