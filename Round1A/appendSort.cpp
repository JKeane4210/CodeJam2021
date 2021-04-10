//
// Created by Jonny Keane on 4/9/21.
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

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        string nums[l];
        for (int j = 0; j < l; ++j) {
            cin >> nums[j];
        }
        long long ops = 0;
        for (int j = 1; j < l; ++j) {
            string prev = nums[j - 1];
            if (nums[j].length() < prev.length() || (nums[j].length() == prev.length() && nums[j] <= prev)) { // "12" < "2"
                if (nums[j] == prev.substr(0, nums[j].size())) {
                    string rest = prev.substr(nums[j].length(), prev.size() - nums[j].size());
                    long long end = rest.size() - 1;
                    while (rest[end] == '9' && end >= 0) {
                        rest[end] = '0';
                        end--;
                    }
                    if (end >= 0) {
                        long long pastLength = nums[j].size();
                        rest[end] = (char)(rest[end] + 1);
                        nums[j] = nums[j] + rest;
                        ops += nums[j].size() - pastLength;
                        continue;
                    }
                }
                long long dif = prev.size() - nums[j].size();
                for (long long k = 0; k < dif; ++k) {
                    nums[j] = nums[j] + '0';
                }
                ops += dif;
                if (nums[j].length() < prev.length() || (nums[j].length() == prev.length() && nums[j] <= prev)) {
                    nums[j] = nums[j] + '0';
                    ++ops;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << ops << nl;
    }
    return 0;
}
