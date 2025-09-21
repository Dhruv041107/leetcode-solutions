class Solution {
public:
    bool isValid(string word) {
        string vowels = "aeiouAEIOU";
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        string allowed = vowels + consonants + "0123456789";

        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (allowed.find(c) == string::npos) {
                return false;
            }
            if (vowels.find(c) != string::npos) {
                hasVowel = true;
            }
            if (consonants.find(c) != string::npos) {
                hasConsonant = true;
            }
        }
        return hasVowel && hasConsonant;
    }
};
