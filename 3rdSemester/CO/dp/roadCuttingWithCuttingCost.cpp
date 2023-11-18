#include <bits/stdc++.h>
using namespace std;

#define mx 100

struct rod {
    int len, price;
} rods[100];

vector<int> dp(mx, -1);

int rod_cut(struct rod rods[], int n, int cutting_cost, vector<int>& selected_segments) {
    if (dp[n] >= 0) {
        return dp[n];
    }

    if (n == 0) {
        dp[n] = 0;
    } else {
        int q = INT_MIN;
        int best_cut = -1;

        for (int i = 0; i < n; i++) {
            int current_cut = rods[i].price + rod_cut(rods, n - i - 1, cutting_cost, selected_segments) - cutting_cost;
            if (current_cut > q) {
                q = current_cut;
                best_cut = i;
            }
        }

        dp[n] = q;
        if (best_cut != -1) {
            selected_segments[n] = best_cut;
        }
    }

    return dp[n];
}

void print_cut_segments(const vector<int>& selected_segments, int n) {
    while (n > 0) {
        int cut = selected_segments[n];
        cout << "Cut rod of length " << rods[cut].len << " for price " << rods[cut].price << endl;
        n = n - rods[cut].len;
    }
}

int main() {
    freopen("rodCost.txt", "r", stdin);

    int num, cutting_cost;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> rods[i].len >> rods[i].price;
    }

    cin >> cutting_cost;

    int n;
    cin >> n;

    vector<int> selected_segments(mx, -1);
    int res = rod_cut(rods, n, cutting_cost, selected_segments);

    cout << "Maximum value: " << res << endl;
    cout << "Cutting segments:" << endl;
    print_cut_segments(selected_segments, n);

    return 0;
}
