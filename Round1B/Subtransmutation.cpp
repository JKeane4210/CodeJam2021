//
// Created by Jonny Keane on 4/25/21.
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

pair<int, int> performSpell(int A, int B, int i) {
    return make_pair(i - A, i - B);
}

void solve(int c) {
    int N, A, B;
    cin >> N >> A >> B;
    multiset<int> vals;
    int max;
    for (int i = 1; i <= N; ++i) {
        int valCount;
        cin >> valCount;
        for (int j = 0; j < valCount; ++j) {
            vals.insert(i);
            max += i;
        }
    }
    if (vals.size() == 1) {
        cout << "Case #" << c + 1 << ": " << N << nl;
        return;
    }
    int test = N + 1;
    while (test <= max) {
        priority_queue<int> pq;
        multiset<int> valsCopy(vals);
        pq.push(test);
        while (!pq.empty() && !valsCopy.empty()) {
            int curr = pq.top();
            pq.pop();
            pair<int, int> spell = performSpell(A, B, curr);
            if (spell.first > 0) {
                if (valsCopy.count(spell.first) != 0) {
                    auto itr = find(valsCopy.begin(), valsCopy.end(), spell.first);
                    if (itr != valsCopy.end()) {
                        valsCopy.erase(itr);
                    }
                } else {
                    pq.push(spell.first);
                }
            }
            if (spell.second > 0) {
                if (valsCopy.count(spell.second) != 0) {
                    auto itr = find(valsCopy.begin(), valsCopy.end(), spell.second);
                    if (itr != valsCopy.end()) {
                        valsCopy.erase(itr);
                    }
                } else {
                    pq.push(spell.second);
                }
            }
        }
        if (valsCopy.empty()) {
            cout << "Case #" << c + 1 << ": " << test << nl;
            return;
        }
        ++test;
    }
    cout << "Case #" << c + 1 << ": IMPOSSIBLE" <<nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i);
    }

    return 0;
}