//
// Created by Jonny Keane on 3/26/21.
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
    int c;
    cin >> c;
    for(int i = 0; i < c; ++i) {
        int l;
        cin >> l;
        int arr[l];
        for(int j = 0; j < l; ++j) {
            cin >> arr[j];
        }
        int cost = 0;
        for (int j = 0; j < l - 1; ++j) {
            int min = arr[j];
            int ind = j; // the minimum index
            for (int k = j; k < l; ++k) {
                if (arr[k] < min) {
                    min = arr[k];
                    ind = k;
                }
            }
            cost += ind - j + 1;
            for (int k = 0; k < (ind - j + 1) / 2; ++k) { // rev
                int temp = arr[k + j];
                arr[k + j] = arr[ind - k];
                arr[ind - k] = temp;
            }
        }
        printf("Case #%i: %i", i + 1, cost);
        cout << endl;
    }

    return 0;
}