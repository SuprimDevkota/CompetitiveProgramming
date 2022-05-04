#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int nc = 0, no = 0, nd = 0, ne = 0, nh = 0, nf = 0;
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            nc += count(s.begin(), s.end(), 'c');
            no += count(s.begin(), s.end(), 'o');
            nd += count(s.begin(), s.end(), 'd');
            ne += count(s.begin(), s.end(), 'e');
            nh += count(s.begin(), s.end(), 'h');
            nf += count(s.begin(), s.end(), 'f');
        }

        cout << min({nc/2, no, nd, ne/2, nh, nf}) << endl;
    }

    return 0;
}