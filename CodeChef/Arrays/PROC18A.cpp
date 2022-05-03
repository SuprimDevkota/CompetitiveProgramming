#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i = 0; i < n; ++i){
	        cin >> arr[i];
	    }
	    int sum = 0;
	    for(int i = 0; i < n; ++i){
	        int curr_sum = 0;
	        for(int j = i; (j < i+k && j < n); j++){
	            curr_sum += arr[j];
	        }
	        sum = max(curr_sum, sum);
	    }
	    
	    cout << sum << endl;
	    
	}
	return 0;
}
