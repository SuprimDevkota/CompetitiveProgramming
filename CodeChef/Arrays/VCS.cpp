#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int ignored[m];
        int tracked[k];
        
        for(int i = 0; i < m; ++i){
            cin >> ignored[i];
        }
        for(int i = 0; i < k; ++i){
            cin >> tracked[i];
        }

        vector<int> ti;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < k; ++j){
                if(ignored[i] == tracked[j]){
                    ti.push_back(ignored[i]);
                }
            }
        }

        //U - (A + B - A.B) = U - (A+B) = (A+B)'
        cout << ti.size() << " " << n - (m + k  - ti.size()) << endl;
    }
    return 0;
}