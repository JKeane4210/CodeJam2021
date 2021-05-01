//
// Created by Jonny Keane on 5/1/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;
    int data[N];
    for (int i = 0; i < N; ++i) {
        cin >> data[i];
    }
    sort(data, data + N);
    if (N == 1) {
        cout << "Case #" << t << ": " << (double)(K - 1)/(double)K << nl;
        return;
    }
    int deltas[N + 1];
    int deltas2[N - 1];
    for (int i = 0 ; i < N - 1; ++i) {
        deltas[i] = (data[i + 1] - data[i])/ 2;
        deltas2[i] = data[i + 1] - data[i] - 1;
    }
    deltas[N - 1] = K - data[N - 1];
    deltas[N] = data[0] - 1;
    sort(deltas, deltas + N + 1);

    cout << "Case #" << t << ": " << max((double) (deltas[N] + deltas[N - 1]) / (double) K,
                                         (double)*max_element(deltas2, deltas2 + N - 1)/(double)K) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }

    return 0;
}