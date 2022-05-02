#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        //Accept the array
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        //Sort the array
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
        }

        
        //Check same values
        int same = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == arr[i + 1]){
                same++;
            }
        }

        //Print distinct values
        cout << n - same << endl;
    }
}