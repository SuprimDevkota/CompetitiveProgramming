#include <iostream>
#include <set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            s.insert(a);
        }

        //Number of minimum operations = Number of distinct elements - Number of 0's.
        cout << s.size() - s.count(0) << endl;
    }

    return 0;
}