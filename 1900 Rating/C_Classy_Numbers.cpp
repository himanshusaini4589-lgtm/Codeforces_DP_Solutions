
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> precal;

void brute(long long cnt, long long no, int pos){
    // base case: all 18 positions filled, store the number
    if(pos == 18){
        precal.push_back(no);
        return;
    }

    // place 0 at current position
    brute(cnt, no * 10, pos + 1);

    // place 1-9 only if non-zero quota remaining
    if(cnt < 3){
        for(int i = 1; i <= 9; i++){
            brute(cnt + 1, no * 10 + i, pos + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precal.push_back(1000000000000000000LL);

    brute(0, 0, 0);

    // sort for binary search
    sort(precal.begin(), precal.end());

    int n;
    cin >> n;

    while(n--){
        long long l, r;  // ⚠️ must be long long, NOT int (values up to 10^18)
        cin >> l >> r;

        // lower_bound → first index >= l
        // upper_bound → first index > r
        // difference  → count of classy numbers in [l, r]
        int lo = lower_bound(precal.begin(), precal.end(), l) - precal.begin();
        int ro = upper_bound(precal.begin(), precal.end(), r) - precal.begin();

        cout << ro - lo << "\n";
    }

    return 0;
}