#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

const int MAX = 100005;
const int MAX_HEIGHT = 2000000001;

ll arr[MAX], temp[MAX];
int N, M, K;

bool check(ll cap){
    ll used = 0;
    for (int i=1; i<=N; i++){
        temp[i] = arr[i] - arr[i-1];
    }

    for (int i=1; i<=N; i++){
        temp[i] += temp[i-1];
        if (temp[i] < cap){
            ll d = cap - temp[i];
            used += d;
            temp[i] += d, temp[min(N+1, i+M)] -= d;
        }
    }

    return used <= K;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    arr[0] = temp[0] = 0;

    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    
    ll low = 1;
    ll high = MAX_HEIGHT;

    while (low < high){
        ll mid = (low + high) / 2;
        if (check(mid)){
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low - 1;


    return 0;
}
