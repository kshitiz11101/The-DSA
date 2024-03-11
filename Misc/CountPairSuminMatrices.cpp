class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int count=0;
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int a=mat1[i][j];
	            m[a]++;
	        }
	        
	    }
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int b=mat2[i][j];
	            if(m[x-b]==1){
	                count++;
	            }
	        }
	        
	    }
	    return count;
	}
};
