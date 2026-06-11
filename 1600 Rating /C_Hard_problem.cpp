#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

const long long INF = 1e18;
map<pair<int,string>, long long> memo;

long long f(int n, vector<int>& c, vector<string>& v, int ind, string prev){
    if(ind >= n) return 0;
    auto key = make_pair(ind, prev);
    if(memo.count(key)) return memo[key];
    string original = v[ind];
    string reversed = v[ind];
    reverse(reversed.begin(), reversed.end());

    long long useOriginal = INF;
    long long useReversed = INF;

    // use original if it maintains sorted order
    if(original >= prev){
        long long next = f(n, c, v, ind+1, original);
        if(next != INF)
            useOriginal = 0 + next;
    }

    // use reversed if it maintains sorted order
    if(reversed >= prev){
        long long next = f(n, c, v, ind+1, reversed);
        if(next != INF)
            useReversed = c[ind] + next;
    }

    return memo[key] = min(useOriginal, useReversed);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    memo.clear();
    long long ans = f(n, c, v, 0, "");
    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}