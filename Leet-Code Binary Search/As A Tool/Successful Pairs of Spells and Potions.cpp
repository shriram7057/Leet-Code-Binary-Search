class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;

        for (int s : spells) {
            long long need = (success + s - 1) / s; // ceiling division
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            res.push_back(m - idx);
        }

        return res;
    }
};
