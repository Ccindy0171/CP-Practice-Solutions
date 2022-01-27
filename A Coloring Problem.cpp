/*
    for problem `Mock CCC '18 Contest 2 J5/S3 - A Coloring Problem` on dmoj
    https://dmoj.ca/problem/nccc2j5s3
*/

#include <iostream>
#include <cstring>
#include <math.h>

typedef long l;

using namespace std;

int M, N;
int n_blues[30] = {}; 
int n_reds[30];
l combinations[30][30] = {{}};

int main(){
    string line;
    bool exist_comb = true;
    l answer = 0;

    cin >> M >> N;
    for (int i=0; i<M; i++){
        n_blues[i] = 0;
        n_reds[i] = N+1;
    }
    
    getline(cin, line);
    
    for (int i=0; i<M; i++){
        getline(cin, line);
        if (exist_comb){
            for (int j=0; j<N; j++){
                if (line[j] == 'B'){
                    // update all the limits for blues in rows before it
                    for (int k=0; k<=i; k++){
                        n_blues[k] = max(n_blues[k], j + 1);
                        // if there is conflict in a row, then the grid cannot be filled properly
                        if (n_blues[k] >= n_reds[k]){
                            exist_comb = false;
                        }
                    }
                } else if (line[j] == 'R'){
                    // update all the limits for reds in rows after it
                    for (int k=i; k<M; k++){
                        n_reds[k] = min(n_reds[k], j + 1);
                        // if there is conflict in a row, then the grid cannot be filled properly
                        if (n_blues[k] >= n_reds[k]){
                            exist_comb = false;
                        }
                    }
                }
            }
        }   
    }
    
    if (exist_comb){
        // for each row
        for (int r = M - 1; r >= 0; r--){
            // for each of the column that is allowed to be either blue or red
            for (int c = n_blues[r]; c<n_reds[r] - 1; c++){
                // set the combinations there to be 1 (for itself)
                combinations[r][c] = 1;
                // go through all the other possible combinations before it, and add them
                for (int i=r+1; i<M; i++){
                    for (int j = n_blues[i]; j< min(n_reds[i], c); j++){
                        combinations[r][c] += combinations[i][j];
                    }
                }
                // add the current number of combinations to answer
                answer += combinations[r][c];
            }
        }
        answer ++;
        cout << answer;
    } else{
        cout << 0;
    }
    
    // for judge (will report presentation error with no line breaks)
    cout << '\n';

    return 0;
}
