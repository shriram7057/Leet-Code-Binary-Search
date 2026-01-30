class SnapshotArray {
public:
    vector<vector<pair<int,int>>> history;
    int currentSnap;

    SnapshotArray(int length) {
        history.resize(length);
        currentSnap = 0;
        for (int i = 0; i < length; i++) {
            history[i].push_back({0, 0}); // initial value
        }
    }
    
    void set(int index, int val) {
        history[index].push_back({currentSnap, val});
    }
    
    int snap() {
        return currentSnap++;
    }
    
    int get(int index, int snap_id) {
        auto &vec = history[index];
        int left = 0, right = vec.size() - 1;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= snap_id) {
                ans = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
