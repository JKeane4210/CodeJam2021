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

string x2(string bin) {
    return bin + "0";
}

string not_(string bin_, bool trim=true) {
    string bin = bin_;
    for (int i = 0; i < bin.size(); ++i) {
        if (bin[i] == '0') {
            bin[i] = '1';
        } else {
            bin[i] = '0';
        }
    }
    if (trim) {
        while (bin.size() > 1 && bin[0] == '0') {
            bin = bin.substr(1);
        }
    }
    return bin;
}

int notTrim(string s, string e) {
    int ops = 0;
    while (s != e && ops < e.size() * 2) {
        s = not_(s);
        ++ops;
    }
    return ops == e.size() * 2 ? - 1 : ops;
}

void solve(int t) {
    string s, e;
    cin >> s >> e;
    int index = 0;
    bool isInverted = false;
    for (int i = 0 ; i < min(e.size(), s.size()); ++i) {
        if (s.substr(s.size() - 1 - i) == e.substr(0, i + 1)) {
            index = i + 1;
            isInverted = false;
        }
        if (s.substr(s.size() - 1 - i) == not_(e.substr(0, i + 1), false)) {
            index = i + 1;
            isInverted = true;
        }
    }
//    cout << index << "*" << endl;
    int ops = 0;
    string prevS;
    while (s != e && prevS != s) {
        prevS = s;
        if (e[index] == '1') {
            if (!isInverted) {
                s = not_(s);
                ++ops;
                isInverted = !isInverted;
            }
            while (e[index] == '1') {
                s = x2(s);
                ++ops;
                ++index;
            }
            s = not_(s);
            ++ops;
        } else {
            if (isInverted) {
                s = not_(s);
                ++ops;
                isInverted = !isInverted;
            }
            while (e[index] == '0') {
                s = x2(s);
                ++ops;
                ++index;
            }
        }
        int notTrimRes = notTrim(s,e);
        if (notTrimRes != -1) {
            ops += notTrimRes;
            cout << "Case #" << t << ": " << ops << endl;
            return;
        }
    }
    if (prevS != s) {
        cout << "Case #" << t << ": " << ops << endl;
    } else {
        cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    }
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
