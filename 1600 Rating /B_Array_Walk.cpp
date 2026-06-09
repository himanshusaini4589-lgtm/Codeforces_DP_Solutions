#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// dp[moves][left][last_was_left]
// Max values: k <= 100000, z <= 5, last_was_left <= 1
int dp[100005][6][2]; 

int f(vector<int>& v, int moves, int left, int last_was_left, int k, int z) {

    if (moves == k) return 0;
    if (dp[moves][left][last_was_left] != -1) {
        return dp[moves][left][last_was_left];
    }

    // Calculate current index based on moves and left turns taken
    int ind = moves - 2 * left;

    int move_right = 0;
    if (ind + 1 < v.size()) {
        move_right = v[ind + 1] + f(v, moves + 1, left, 0, k, z);
    }
    int move_left = 0;
    if (left < z && last_was_left == 0 && ind - 1 >= 0) {
        move_left = v[ind - 1] + f(v, moves + 1, left + 1, 1, k, z);
    }

    return dp[moves][left][last_was_left] = max(move_right, move_left);
}

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp,-1,sizeof dp);
    int ans = v[0] + f(v, 0, 0, 0, k, z);
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    while (N--) {
        solve();
    }
    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;

// int f(vector<int>&v,int ind,int total,int left,bool l,int k,int z){
//     if(k==0) return 0;
//     if(ind<0) return 0;
//     if(ind>=v.size()) return 0;
//     int take = 0;
//     if(total<k && ind+1<v.size()){
//         take = take + v[ind+1] + f(v,ind+1,total+1,left,0,k,z);
//     }
//     int lefti = 0;
//     if(left<z && ind-1>=0 && total<k && !l){
//         lefti = lefti + v[ind-1] + f(v,ind-1,total+1,left+1,1,k,z);
//     }

//     return max(take , lefti);
// }

// int main(){
//     int N;
//     cin>>N;
//     while(N--){
//         int n,k,z;
//         cin>>n>>k>>z;
//         vector<int>v;
//         for(int i = 0 ; i<n ; i++){
//             int y;
//             cin>>y;
//             v.push_back(y);
//         }
//         int ans= v[0] +  f(v,0,0,0,1,k,z);
//         cout<<ans<<"\n";
//     }
// }
