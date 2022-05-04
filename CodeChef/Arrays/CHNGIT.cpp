#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int max_freq = 0;
        for(int i = 0; i < n; ++i){
            int freq = 1, j = i;
            while(arr[j] == arr[j+1]){
                freq++;
                j++;
            }

            max_freq = max(max_freq, freq);
        }

        cout << n - max_freq << endl;
    }
}