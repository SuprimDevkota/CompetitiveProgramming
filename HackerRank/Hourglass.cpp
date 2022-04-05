/*GIVEN A 6X6 2D ARRAY FIND THE MAXIUMUM HOURGLASS SUM POSSIBLE AND RETURN IT.
EG:
-9-9 -9  1 1 1
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
THE  HOURGLASS SUMS ARE:
-63, -34, -9, 12,
-10,   0, 28, 23,
-27, -11, -2, 10,
  9,  17, 25, 18
THE HIGHEST HOURGLASS SUM IS  28 FROM THE HOURGLASS BEGINNING AT ROW 1, COLUMN 2:
0 4 3
  1
8 6 6
*/

#include <iostream>
using namespace std;

int main(){

    int arr[6][6];
    int sums[16], k = 0, max_sum;

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            sums[k] = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            k++;
        }
    }
    
    max_sum = sums[0];
    for(int i = 1; i < 16; ++i){
        max_sum = (max_sum > sums[i])?max_sum: sums[i];
    }
    cout << max_sum << endl;
}