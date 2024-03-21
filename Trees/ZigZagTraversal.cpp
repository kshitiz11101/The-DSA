class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	queue<Node*>q;
    	bool leftToright=true;
    	q.push(root);
    	if(root==NULL){
    	    return result;
    	}
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>ans(size);
    	for(int i=0;i<size;i++){
    	    Node*temp=q.front();
    	    q.pop();
    	    int index=leftToright ? i : size-i-1;
    	    ans[index]=temp->data;
    	    if(temp->left){
    	        q.push(temp->left);
    	    }
    	    if(temp->right){
    	        q.push(temp->right);
    	    }

    	}
    leftToright=!leftToright;
    // 	direction change
    		for(auto i:ans){
    		    result.push_back(i);
    		}
    	}
    	return result;
    }
};
