#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
   
    int y;
    vector <int> w (n);
    for (int i = 0;i< n;++i) {
        cin >> w[i];
    }

    vector <pair<int,int>> dp (1 << n ,{n+1,0});
    dp[0] = {1,0};

    for(int mask = 0;mask <(1 << n);mask++) {

        for (int i =0;i<n;i++) {
            if(!(mask & (1 << i))) {
                auto current_state = dp[mask];
                if (dp[mask].second + w[i] <=x) {
                    current_state.second+= w[i];
                    
                } else {
                    current_state.first++;
                    current_state.second = w[i];
                }
                dp[mask | (1 << i)] = min(dp[mask | (1 << i )], current_state);
            
            }
        }
    }


    cout << dp[(1<<n) - 1].first << endl;
    return 0;

    
}