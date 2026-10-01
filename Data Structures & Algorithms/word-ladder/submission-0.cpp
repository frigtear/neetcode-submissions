class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        std::queue<std::pair<int, std::string>> q;
        std::set<int> visited = {};
        q.push({1, beginWord});

        wordList.push_back(beginWord);
        visited.insert(wordList.size() - 1);
                
        while (!q.empty()){

            auto val = q.front();
            std::string otherWord = val.second;
            int time = val.first;
            std::cout << otherWord << " " << time << " " << std::endl;
            q.pop();

            for (size_t i = 0; i < wordList.size(); i++){
                if (visited.contains(i)){
                    continue;
                }

                int differences = 0;
                for (int j = 0; j < beginWord.size(); j++ ){

                    if (wordList[i][j] != otherWord[j]){
                        differences ++;
                    }
                    if (differences > 1){
                        break;
                    }
                }

                if (differences == 1){
                   // std::cout << wordList[i] << " " << std::endl;
                    if (wordList[i] == endWord){
                        return time + 1;
                    }
                    visited.insert(i);
                    q.push({time + 1, wordList[i]});
                }

            }

        }

        return 0;
    }
};
