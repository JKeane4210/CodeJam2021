//
// Created by Jonny Keane on 3/27/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, N, Q;
    cin >> T >> N >> Q;
    for (int i = 0; i < T; ++i) {
        int size = 3;
        int data[N];
        cout << "1 2 3" << endl;
        int qRes;
        cin >> qRes;
        if (qRes == 2) {
            data[0] = 1; data[1] = 2; data[2] = 3;
        } else if (qRes == 1) {
            data[0] = 2; data[1] = 1; data[2] = 3;
        } else {
            data[0] = 1; data[1] = 3; data[2] = 2;
        }
        int addition = 4;
        while (size != N) {
            int left = 0;
            int right = size - 1;
            qRes = addition;
            while (qRes == addition && left < right) {
                cout << data[left] << ' ' << data[right] << ' ' << addition << endl;
                cin >> qRes;
                ++left;
            }
            --left;
            if (qRes == addition) {
                data[size] = data[right];
                data[right] = addition;
            } else if (qRes == data[left]) {
                for (int j = size - 1; j >= left; --j) {
                    data[j + 1] = data[j];
                }
                data[left] = addition;
            } else { // right
                data[size] = addition;
            }
            ++addition;
            ++size;
        }
        for(int j : data) {
            cout << j << ' ';
        }
        cout << endl;
        int judgeScore;
        cin >> judgeScore;
    }

    return 0;
}