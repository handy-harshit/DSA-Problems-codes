    bool static mycmp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++){
            v.push_back({start[i],end[i]});
        }
        // for(int i=0; i<n; i++){
        //     cout << v[i].first << " " << v[i].second << endl;
        // }
        
        sort(v.begin(),v.end(), mycmp);
        
        int ans =1;
        int prev = 0;
        for(int curr=1; curr<n; curr++){
            if(v[curr].first > v[prev].second){
                ans++;
                prev = curr;
            }
        }
        return ans;
    }