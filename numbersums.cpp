#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s, set;
    int n;
    int a;
    vector<int> coins;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        coins.push_back(a);
    }
    s.insert(0);
    for(int i=0; i<n; i++){
        set=s;
        for(auto k : set){
            s.insert(k+coins[i]);
        }
    }
    s.erase(0);
    cout << s.size() << '\n';
    for(auto k : s)
    cout << k << " ";
    return 0;
}