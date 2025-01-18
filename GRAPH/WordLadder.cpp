class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // making a queue which holds the word and steps in pair
        queue<pair<string, int> > q;
        q.push({beginWord, 1});

        // made a set which carries all the string of wordList
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i=0; i<word.length(); i++){
                char original = word[i];

                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }

                }
                // we are doing this so that when loop runs again the word would be tha same 
                word[i] = original;
            }
            
        }
        return 0;
    }
};