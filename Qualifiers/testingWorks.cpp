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

    // code here
    cout << "hello world" << endl;

    return 0;
}

//            for (int j = 0; j < N - 1; ++j) {
//                cout << steps[j] <<  " ";
//            }
//            cout << nl;
//                if (C - (j + 1) >= (N - 1) - j) {
//                    steps[j  - 1] = j + 1;
//                    C -= j + 1;
//                } else {
//                    cout << "*" << C - ((N - 1) - j) << nl;
//                    steps[j - 1] = C - ((N - 1) - j);
//                    C -= (N - 1) - j;
//                }


//        int addition = 3;
//        int query[2] = {1, 2};
//        int queryCounter = 0;
//        while (data.size() != N) {
//            int index = data.size();
//            query[0] = data[index - 2];
//            query[1] = data[index - 1];
//            cout << query[0] << ' ' << query[1] << ' ' << addition << endl;
//            ++queryCounter;
//            int median;
//            cin >> median;
//            bool satisfied = median == query[1];
//            if (satisfied) {
//                data.push_back(addition);
//            } else {
//                while (!satisfied && index > 0) {
//                    cout << query[0] << ' ' << addition << ' ' << query[1] << endl;
//                    ++queryCounter;
//                    cin >> median;
//                    satisfied = addition == median;
//                    --index;
//                    query[0] = data[index];
//                    query[1] = data[index - 1];
//                }
//                data.push_back(addition);
//                for (int k = data.size() - 2; k >= index; --k) {
//                    data[k + 1] = data[k];
//                }
//                data[index] = addition;
//                cout << "I: " << index << ' ' << nl;
//            }
//            ++addition;
//        }
//        cout << "F: ";
