class Solution {
public:
    vector<long long> prefix;
    long long total;

    Solution(vector<int>& w) {
        total = 0;
        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        long long r = rand() % total + 1;
        return lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
    }
};
