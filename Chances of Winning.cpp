#include <iostream>
#include <map>

using namespace std;
map<pair<int, int>, int> games = {};

int favorite;
int n_games;
int scores[4];
int t1, t2, s1, s2;
int sum;
int c;

void chances();

void win(pair<int, int> game){
    n_games ++;
    games[game] = 1;
    scores[(game.first - 1)] += 3;
    chances();
    games[game] = 0;
    scores[game.first - 1] -= 3;
    n_games --;
}

void loose(pair<int, int> game){
    n_games ++;
    games[game] = 3;
    scores[(game.second - 1)] += 3;
    chances();
    games[game] = 0;
    scores[game.second - 1] -= 3;
    n_games --;
}

void tie(pair<int, int> game){
    n_games ++;
    games[game] = 2;
    scores[(game.first - 1)] += 1;
    scores[(game.second - 1)] += 1;
    chances();
    games[game] = 0;
    scores[game.first - 1] -= 1;
    scores[game.second - 1] -= 1;
    n_games --;
}


void chances(){
    if (n_games == 6){
        
        c = 0;
        for (int score : scores){
            if (score >= scores[favorite-1]) c++;
        }
        if (c == 1){
            sum ++;
        }
        return;
    }
    for (auto game : games){
        if (game.second == 0){
            win(game.first);
            tie(game.first);
            loose(game.first);
            return;
        }
    }
}

int main() {
    // 0 = not played, 1 = first team won, 2 = tie, 3 = second team won   
    games[pair<int, int>(1, 2)] = 0;
    games[pair<int, int>(1, 3)] = 0;
    games[pair<int, int>(1, 4)] = 0;
    games[pair<int, int>(2, 3)] = 0;
    games[pair<int, int>(2, 4)] = 0;
    games[pair<int, int>(3, 4)] = 0;

    cin >> favorite >> n_games;

    for (int i=0; i<n_games; i++){
        cin >> t1 >> t2 >> s1 >> s2;
        if (s1 > s2){
            games[pair<int, int>(t1, t2)] = 1;
            scores[t1-1] += 3;
        } else if (s1 == s2){
            games[pair<int, int>(t1, t2)] = 2;
            scores[t1-1] ++;
            scores[t2-1] ++;
        } else{
            games[pair<int, int>(t1, t2)] = 3;
            scores[t2-1] += 3;
        }
    }

    chances();

    cout << sum << endl;
} 
