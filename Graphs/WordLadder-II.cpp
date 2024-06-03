//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        set<string>s(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnlevel;
        usedOnlevel.push_back(beginWord);
        int level=0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            // erase all words that has been used in the prev level to transform
            if(vec.size()>level){
                level++;
                for(auto it:usedOnlevel){
                    s.erase(it);
                }
            }
           
            string word=vec.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(s.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=ch;
                
            }
            
        }
        return ans;
        
        
    }
};
