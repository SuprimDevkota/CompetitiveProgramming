#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<long> arr(n + 10, 0);
    long answer = INT_MIN;

    while(m--){
        int a, b, k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b+1] -= k;
    }

    for(int i = 1; i <=n; ++i){
        arr[i] += arr[i -1];
        answer = (answer > arr[i])?answer:arr[i];
    }

    cout << answer;
}