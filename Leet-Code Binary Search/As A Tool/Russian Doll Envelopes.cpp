class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        // Step 1: Sort
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // height descending if width same
                 return a[0] < b[0];     // width ascending
             });

        // Step 2: LIS on heights
        vector<int> lis;
        for (auto& e : envelopes) {
            int h = e[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};
