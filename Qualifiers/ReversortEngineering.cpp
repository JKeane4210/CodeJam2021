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

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int N, C;
        cin >> N >> C;
        int max = 0;
        for (int j = 2; j <= N; ++j) {
            max += j;
        }
        if (C >= N - 1 && C <= max) { // range for valid C's that can be created checked
            int arr[N];
            for (int j = 0; j < N; ++j) {
                arr[j] = j + 1;
            }
            int steps[N - 1];
            /*
             * I create the steps that can be taken to get a cost of C through
             * a greedy approach where with the steps where the largest range is possible (earlier),
             * I see what I can take while adding at least 1 to everything else
             */
            for (int j = 1; j < N; ++j) {
                int possibleStep = (N - (j - 1));
                while (possibleStep != 1 && C - possibleStep < N - (j + 1)) {
                    --possibleStep;
                }
                steps[N - 1 - j] = possibleStep;
                C -= possibleStep;
            }
            for (int j = 0; j < N - 1; ++j) {
                // reverse a step
                for (int k = 0; k < steps[j] / 2; ++k) {
                    int temp = arr[N - 1 - (j + 1) + k];
                    arr[k + N - 1 - (j + 1)] = arr[N - 1 - (j + 1) + (steps[j] - 1) - k];
                    arr[N - 1 - (j + 1) + (steps[j] - 1) - k] = temp;
                }
            }
            if (C == 0) {
                printf("Case #%i: ", i + 1);
                for (int k = 0; k < N; ++k) {
                    printf("%i ", arr[k]);
                }
                printf("\n");
            } else { // unnecessary, but did it to be safe for the 100 element case
                printf("Case #%i: IMPOSSIBLE\n", i + 1);
            }
        } else {
            printf("Case #%i: IMPOSSIBLE\n", i + 1);
        }
    }

    return 0;
}
