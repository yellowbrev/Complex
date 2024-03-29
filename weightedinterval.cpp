#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int N, M;
int S[MAXN], F[MAXN], W[MAXN], dp[MAXN], prev[MAXN], selected[MAXN], len;

int main() {
    cout << "Enter the number of intervals: ";
    cin >> N;
    cout << "Enter the maximum end time: ";
    cin >> M;
    for (int i = 0; i < N; i++) {
        cout << "Interval #" << i+1 << ":" << endl;
        cout << "Enter the start time: ";
        cin >> S[i];
        cout << "Enter the end time: ";
        cin >> F[i];
        cout << "Enter the weight: ";
        cin >> W[i];
    }
    for (int i = 0; i < N; i++) {
        dp[i] = W[i];
        prev[i] = -1; // only declare prev array once
        for (int j = 0; j < i; j++) {
            if (F[j] <= S[i] && dp[j] + W[i] > dp[i]) {
                dp[i] = dp[j] + W[i];
                prev[i] = j;
            }
        }
    }
    int ans = 0, last = -1;
    for (int i = 0; i < N; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            last = i;
        }
    }
    while (last != -1) {
        selected[len++] = last;
        last = prev[last];
    }
    cout << "The maximum total weight is: " << ans << endl;
    cout << "Selected intervals: ";
    for (int i = 0; i < len; i++) {
        cout << selected[i]+1 << " ";
    }
    cout << endl;
    return 0;
}
