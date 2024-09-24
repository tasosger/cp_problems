#include <iostream>
#include <iomanip>  
using namespace std;
#define int long long


int32_t main () {
    int t;
    cin >> t;
    for (int i = 0; i<t; ++i) {
        int n, k;
        cin>>n>>k;
        int r = n-1, l=0;
        int mid;
         double totalsum = (k+n-1)*(k+n)/2 - (k)*(k-1)/2;
        while (l<=r) {
            mid = (l+r)/2;
            int psm = (k+mid)*(k+mid+1)/2 - (k-1)*(k)/2; 
            if (psm == (totalsum/2)) {
                cout << fixed << setprecision(0)<<totalsum - 2*psm << endl;
                break;
            }
            if (psm < (totalsum)/2) {
                l = mid+1;
            
            }
            else r = mid-1;
        
        }
        if(l> r) {
            int x1 = (k+l+1)*(k+l)/2 - (k-1)*(k)/2;
            int x2 = (k+r+1)*(k+r)/2 - (k-1)*(k)/2;
            cout << fixed << setprecision(0)<<abs(2* min(x1-totalsum/2,totalsum/2-x2))  <<endl;
        }


    }
}