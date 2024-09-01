#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxScore(const vector<int>& heights, const vector<int>& scores, int K) {
    int N = heights.size();
    vector<int> dp(N, 0);
    dp[0] = scores[0];
    for (int i = 1; i < N; i++) {
        int maxPrevScore = 0;
        for (int j = 0; j < i; j++) {
            if (heights[j] - heights[i] <= K && heights[j] >= heights[i]) {
                maxPrevScore = max(maxPrevScore, dp[j]);
            }
        }
        dp[i] = scores[i] + maxPrevScore;
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    vector<int> scores(N); 
    for (int i = 0; i < N; i++) {
        cin >> heights[i] >> scores[i];
    }
    int result = maxScore(heights, scores, K);
    cout << result << endl;

    return 0;
}
