class Solution {
private:
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> results;

    void generatePaths(const string& word, vector<string>& currentPath) {
        currentPath.push_back(word);
        
        if (parents.find(word) == parents.end()) {
            vector<string> finalPath = currentPath;
            reverse(finalPath.begin(), finalPath.end());
            results.push_back(finalPath);
        } else {
            for (const string& parentWord : parents[word]) {
                generatePaths(parentWord, currentPath);
            }
        }
        
        currentPath.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);
        
        unordered_map<string, int> distance;
        distance[beginWord] = 0;
        
        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string currentWord = q.front();
                q.pop();

                if (currentWord == endWord) {
                    found = true;
                }
                
                string tempWord = currentWord;
                for (int j = 0; j < tempWord.length(); ++j) {
                    char originalChar = tempWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tempWord[j] = c;
                        
                        if (wordSet.count(tempWord)) {
                            if (distance.find(tempWord) == distance.end()) {
                                distance[tempWord] = distance[currentWord] + 1;
                                q.push(tempWord);
                                parents[tempWord].push_back(currentWord);
                            } 
                            else if (distance[tempWord] == distance[currentWord] + 1) {
                                parents[tempWord].push_back(currentWord);
                            }
                        }
                    }
                    tempWord[j] = originalChar;
                }
            }
            if (found) {
                break;
            }
        }
        
        if (found) {
            vector<string> currentPath;
            generatePaths(endWord, currentPath);
        }
        
        return results;
    }
};