class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long sumSkill = accumulate(skill.begin(), skill.end(), 0L);
        long prevWizardDone = sumSkill * mana[0];
        int n = skill.size(), m = mana.size();
        for (int j = 1; j < m; ++j) {
            long prevPotionDone = prevWizardDone;
            for (int i = n - 2; i >= 0; --i) {
                prevPotionDone -= (long)skill[i+1] * mana[j-1];
                prevWizardDone = max(prevPotionDone, prevWizardDone - (long)skill[i] * mana[j]);
            }
            prevWizardDone += sumSkill * mana[j];
        }
        return prevWizardDone;
    }
};
