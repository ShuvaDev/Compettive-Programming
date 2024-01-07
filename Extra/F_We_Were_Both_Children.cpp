#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;


    while(t--) {
        int n, x;
        cin >> n;

        vector<int> vc;
        vector<int> elements(200005, 0);
        
        for(int i = 1; i <= n; i++) {
            cin >> x;
            if(x <= n) {
                elements[x]++;
            }
        }

        
        // for(int i = 0; i < elements.size(); i++) {
        //     if(elements[i]) cout << i << " ";
        // }
        
        for(int elem  = n; elem > 1; elem--){
            for(int i = 1; i * i <= elem; i++) {
                if(i * i == elem) {
                    // cout << i << " : " << elements[i] << endl;
                    elements[elem] += elements[i];

                } else if(i == 1) {
                    // cout << i << " ";
                    elements[elem] += elements[i];
                } else {
                    if(elem % i == 0) {
                        elements[elem] += elements[i];
                        elements[elem] += elements[elem / i];
                        // cout << i << " " << elem / i << " ";
                    }
                }
            }
                
        }

        // for(int i = 0; i < elements.size(); i++) {
        //     if(elements[i]) {
        //         cout << i << " " << elements[i] << endl;
        //     }
        // }
        

        cout << *max_element(elements.begin(), elements.end()) << endl;
    }
    
    
    
    return 0;
}