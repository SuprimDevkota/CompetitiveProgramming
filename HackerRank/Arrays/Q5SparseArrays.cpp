#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> strings(n);
    for(int i = 0; i < n; ++i){
        cin >> strings[i];
    }

    int q;
    cin >> q;
    vector<string> queries(q);
    vector<int> answers(queries.size());
    for(int i = 0; i < q; ++i){
        cin >> queries[i];
    }

    int k = 0;
    for(int i = 0; i < queries.size(); ++i){
        for(int j = 0; j < strings.size(); ++j){
            if(queries[i].compare(strings[j]) == 0){
                (answers[k])++;
            }
        }
        k++;
    }

    for(int i = 0; i < q; ++i){
        cout << answers[i] << endl;
    }

    return 0;
}