#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long pow_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

vector<long> palindromes = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99};
vector<long> multiples = {};

void all_palindromes(int digits){
    long num;
    int digit;
    for (int i=1; i<digits/2; i++){
        for (long n=pow_10[i]; n<pow_10[i+1]; n++){
            // odd numbers
            num = n * pow_10[i];
            for (int d=0; d<i; d++){
                digit = (n % pow_10[(i-d)+1]) / pow_10[(i-d)];
                num += digit * pow_10[d];
            }
            palindromes.push_back(num);
        }
        for (long n=pow_10[i]; n<pow_10[i+1]; n++){
            // even numbers
            num = n * pow_10[i+1];
            for (int d=0; d<=i; d++){
                digit = (n % pow_10[i-d+1]) / pow_10[i-d];
                num += digit * pow_10[d];
            }
            palindromes.push_back(num);
        }
    }
}

void all_multiples(int K){
    for (long palindrome : palindromes){
        if (palindrome % K == 0){
            multiples.push_back(palindrome);
        }
    }
}

void countPalindromes(long lower, long upper){
    //  use c++'s built-in binary search methods to get the index of the lower number and upper number
    int start = lower_bound(multiples.begin(), multiples.end(), lower) - multiples.begin();
    int end = upper_bound(multiples.begin(), multiples.end(), upper) - multiples.begin();
    cout << end - start << "\n";
}

int main() {
    // generate all palindromes up to 10 digits
    all_palindromes(10);

    int times, K;
    long lower, upper;

    cin >> times >> K;
    all_multiples(K);

    for (int i=0; i<times; i++){
        cin >> lower >> upper;
        // cout << lower << ", " << upper << "\n";
        // countPalindromes(lower, upper, K);
        countPalindromes(lower, upper);
    }
} 
