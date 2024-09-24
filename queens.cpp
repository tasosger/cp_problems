#include <bits/stdc++.h>
using namespace std;


struct ArrStruct {
    int arr[8][8];
};

int cntfree(int m[8][8]) {
    int counter = 0;
 for (int i = 0; i<8; ++i) {
        for (int j = 0; j<8; ++j) {
            if (m[i][j] == 0) ++counter;
        }
 }
 return counter;
}

ArrStruct gp(ArrStruct m, int x, int y) {
    for (int i = 0; i < 8; ++i) {
        m.arr[y][i] = 1; 
        m.arr[i][x] = 1; 
    }
     int i = x + 1, j = y + 1;
    while (i < 8 && j < 8) {
        m.arr[j][i] = 1;
        ++i;
        ++j;
    }

    // Bottom-right diagonal
    i = x + 1, j = y - 1;
    while (i < 8 && j >= 0) {
        m.arr[j][i] = 1;
        ++i;
        --j;
    }

    // Top-left diagonal
    i = x - 1, j = y + 1;
    while (i >= 0 && j < 8) {
        m.arr[j][i] = 1;
        --i;
        ++j;
    }

    // Bottom-left diagonal
    i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0) {
        m.arr[j][i] = 1;
        --i;
        --j;
    }

    return m;
}

int calculate(int n, ArrStruct m) {
    int res = 0;
    if (n!=1){
    for (int i =0;i< 8;++i) {
        
            if (m.arr[i][8-n] == 0) {
                res += calculate(n-1, gp(m, 8-n,i));
            }
        
    }
    } else {
        for (int i =0;i< 8;++i) {
        
            if (m.arr[i][8-n] == 0) {
                res += 1;
            }
        
    }
    }
    return res;
}



int main() {
    char c;
    ArrStruct m;
    for (int i = 0; i<8; ++i) {
        for (int j = 0; j<8; ++j) {
            cin>>c;
            if (c == '.') m.arr[i][j] = 0;
            else  m.arr[i][j] = 1;
        }
    }
    cout << calculate(8, m);
    return 0;
}