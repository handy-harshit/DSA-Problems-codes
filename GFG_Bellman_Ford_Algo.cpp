class Solution {
public:
    int d[101];
    int e1,e2,wt;
    
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    for(int i=0; i<n; i++)d[i] = INT_MAX;
	    d[0] = 0;
	    for(int count=0; count<n-1; count++){
	        for(int j=0; j<edges.size(); j++){
	        
    	        e1 = edges[j][0];
    	        e2 = edges[j][1];
    	        wt = edges[j][2];
	            if(d[e1] != INT_MAX && d[e2] > (d[e1] + wt)){
	                d[e2] = d[e1] + wt;
	            }
	            
	        }
	    }
	    for(int i=0; i<edges.size(); i++){
	        e1 = edges[i][0];
	        e2 = edges[i][1];
	        wt = edges[i][2];
	        if(d[e1] != INT_MAX && d[e2] > (d[e1] + wt))return 1;
	    }
	    return 0;
	            
	}
};