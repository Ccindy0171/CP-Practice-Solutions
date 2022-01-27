#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e5 + 1;

int G, P;
set<int> ports;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int G, P;
    cin >> G >> P;
    
    for (int i=1; i<=G; i++){
        ports.insert(i);
    }
    
    int ans = 0;
    int g;
    bool full = false;
    for (int i=0; i<P; i++){
        cin >> g;
        if (!full){
            auto x = ports.upper_bound(g);
            if (x != ports.begin()){
                x--;
                ports.erase(x);
                ans ++;
            } else{
                full = true;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
