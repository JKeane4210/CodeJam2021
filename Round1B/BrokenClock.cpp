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

ll hrTicksPerNano = 1;
ll minTicksPerNano = 12;
ll secTicksPerNano = 720;
//ll nanoPerNanoTick = 3600E9;
ll nanoPerSec = 1E9;
ll nanoPerMin = nanoPerSec * 60;
ll nanoPerHr = nanoPerMin * 60;

void solve(ll a, ll b, ll c) {
    cout << (a / hrTicksPerNano) / nanoPerHr << nl;
    cout << (b / minTicksPerNano) / nanoPerMin << nl;
    cout << (c / secTicksPerNano) /nanoPerSec << nl;
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }

    return 0;
}