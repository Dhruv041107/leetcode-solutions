#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sum = 0;                        
    int X;                                    
    set<pair<int,int>> mainSet, secSet;       

    void insertPair(pair<int,int> p) {
        if ((int)mainSet.size() < X || p > *mainSet.begin()) {
            sum += 1LL * p.first * p.second;
            mainSet.insert(p);
            if ((int)mainSet.size() > X) {
                auto smallest = *mainSet.begin();
                sum -= 1LL * smallest.first * smallest.second;
                mainSet.erase(mainSet.begin());
                secSet.insert(smallest);
            }
        } else {
            secSet.insert(p);
        }
    }
    void removePair(pair<int,int> p) {
        if (mainSet.find(p) != mainSet.end()) {
            sum -= 1LL * p.first * p.second;
            mainSet.erase(p);

            if (!secSet.empty()) {
                auto largest = *secSet.rbegin();
                secSet.erase(largest);
                mainSet.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else if (secSet.find(p) != secSet.end()) {
            secSet.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        X = x;                        
        unordered_map<int,int> freq;  
        vector<long long> result;

        int i = 0, j = 0;
        sum = 0;
        mainSet.clear();
        secSet.clear();

        while (j < n) {
            if (freq[nums[j]] > 0)
                removePair({freq[nums[j]], nums[j]});

            freq[nums[j]]++;
            insertPair({freq[nums[j]], nums[j]});

            if (j - i + 1 == k) {
                result.push_back(sum);
                removePair({freq[nums[i]], nums[i]});
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                else
                    insertPair({freq[nums[i]], nums[i]});

                i++;
            }
            j++;
        }
        return result;
    }
};
