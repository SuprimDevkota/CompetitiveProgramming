#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;  //Number of people
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        int bestcase = INT_MAX;
        int worstcase = INT_MIN;

        for(int i = 0; i < n; ++i){

            int left = i;
            while(left > 0 && abs(arr[left-1] - arr[left]) <= 2){
                left--;
            }
            
            int right = i;
            while(right < n - 1 && abs(arr[right+1] - arr[right]) <= 2){
                right++;
            }

            int infected = right - left + 1;
            bestcase = min(bestcase, infected);
            worstcase = max(worstcase, infected);
        }

        cout << bestcase << " " << worstcase << endl;
    }
    return 0;
}