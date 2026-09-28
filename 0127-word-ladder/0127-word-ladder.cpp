class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present
        if (!st.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Remove beginWord if present
        st.erase(beginWord);

        while (!q.empty()) {
            
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Try changing every character
            for (int i = 0; i < word.length(); i++) {
                
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    
                    word[i] = c;

                    // Found a valid next word
                    if (st.count(word)) {
                        
                        if (word == endWord)
                            return steps + 1;

                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};