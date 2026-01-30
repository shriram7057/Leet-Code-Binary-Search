class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            int l = 0, r = tails.size();
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (tails[mid] < num)
                    l = mid + 1;
                else
                    r = mid;
            }
            if (l == tails.size())
                tails.push_back(num);
            else
                tails[l] = num;
        }

        return tails.size();
    }
};
