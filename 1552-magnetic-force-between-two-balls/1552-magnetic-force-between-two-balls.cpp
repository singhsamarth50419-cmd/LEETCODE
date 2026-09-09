class Solution {
public:

    bool isPossible(vector<int>& arr, int m, int minAllowedDist) {

        int cows = 1;
        int lastStallPos = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] - lastStallPos >= minAllowedDist) {
                cows++;
                lastStallPos = arr[i];
            }
        }

        return cows >= m;
    }

    int maxDistance(vector<int>& arr, int m) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int st = 1;
        int end = arr[n - 1] - arr[0];
        int ans = -1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (isPossible(arr, m, mid)) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};