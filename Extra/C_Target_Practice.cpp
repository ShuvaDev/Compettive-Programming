#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    
    int t;
    cin >> t;
    vector<string> vc(10); 
    while(t--) {
        vc.clear();
        for(int i = 0; i < 10; i++)  {
            cin >> vc[i];
        }
        long long sum = 0;
        for(int i = 0; i < 10; i++)  {
            if(vc[0][i] == 'X') {
                sum += 1;
            }
            if(vc[9][i] == 'X') {
                sum += 1;
            }
        }
        for(int i = 1; i < 9; i++) {
            if(vc[i][0] == 'X') {
                sum += 1;
            }
            if(vc[i][9] == 'X') {
                sum += 1;
            }
        }
        
        for(int i = 1; i < 9; i++)  {
            if(vc[1][i] == 'X') {
                sum += 2;
            }
            if(vc[8][i] == 'X') {
                sum += 2;
            }
        }

        for(int i = 2; i < 8; i++) {
            if(vc[i][1] == 'X') {
                sum += 2;
            }
            if(vc[i][8] == 'X') {
                sum += 2;
            }
        }
        /// 
        for(int i = 2; i < 8; i++)  {
            if(vc[2][i] == 'X') {
                sum += 3;
            }
            if(vc[7][i] == 'X') {
                sum += 3;
            }
        }

        for(int i = 3; i < 7; i++) {
            if(vc[i][2] == 'X') {
                sum += 3;
            }
            if(vc[i][7] == 'X') {
                sum += 3;
            }
        }
        //
        for(int i = 3; i < 7; i++)  {
            if(vc[3][i] == 'X') {
                sum += 4;
            }
            if(vc[6][i] == 'X') {
                sum += 4;
            }
        }

        for(int i = 4; i < 6; i++) {
            if(vc[i][3] == 'X') {
                sum += 4;
            }
            if(vc[i][6] == 'X') {
                sum += 4;
            }
        }
        //
        for(int i = 4; i < 6; i++)  {
            if(vc[4][i] == 'X') {
                sum += 5;
            }
            if(vc[5][i] == 'X') {
                sum += 5;
            }
        }
        cout << sum << endl;
    }
    
    
    return 0;
}