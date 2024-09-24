#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    //cout << n << endl;
    vector<int> p (n);
    int w;
    int total = 0;
    for (int i = 0;i< n;++i) {
        cin >> w;

        p[i] = w;
        //cout << p[i] << endl;
        total+= p[i];
    }
    //cout << "done";
    long long best_diff = total;
    //int best_mask = 0;
    vector<int> dp(1ll << n, -1);

    dp[0] = 0;
    for (int mask = 0; mask < (1<<n);++mask) {
        
        //cout << mask << endl;
        
        for (int  i = 1;i<(1ll<<n); i*=2) {
            
            if(((mask & i) != 0)  || dp[mask |i ] != -1) {
                continue;
            }  else {
                dp[mask | i] = dp[mask] +p[__builtin_ctz(i)];
                
                long long diff = abs((total -  dp[mask | i])- dp[mask|i ]);
                //cout << diff << endl;
                if(diff < best_diff) {
                    best_diff = diff;
                }
                //dp[!(mask | i )] = total - dp[mask | i ];
            }
        }
    }

    cout << best_diff;
    return 0;

    
}