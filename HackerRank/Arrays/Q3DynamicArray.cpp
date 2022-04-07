#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> arr(n);
    vector<int> answers;

    cout << arr.size(); 

    int lastAnswer = 0;

    string* queries = new string [q];
    for(int i = 0; i < q; ++i){
        getline(cin>>ws, queries[i]);       //cin>>ws negates whitespaces
    }

    for(int i = 0; i < q; ++i){
        int x = queries[i][2] - 48, y = queries[i][4] - 48;
        int idx = ((x^lastAnswer) % n);
        if((queries[i][0]-48) == 1){
            arr[idx].push_back(y);
        }
        else if((queries[i][0]-48) == 2){
            cout << "size: " << arr[idx].size() << endl;
            lastAnswer = arr[idx][y%(arr[idx].size())];
            answers.push_back(lastAnswer);
        }
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }
    return 0;
}