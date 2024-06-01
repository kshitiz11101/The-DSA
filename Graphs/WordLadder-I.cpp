class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(startWord);
        int ans=0;
        while(!q.empty()){
            string word=q.front().first;
            int freq=q.front().second;
            q.pop();
            if(word==targetWord){
                return freq;
            }
            // hat initial word
            for(int i=0;i<word.size();i++){
                char original=word[i];
                // aat
                // bat
                // cat.......... zat
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    // it exists in the set
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,freq+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
