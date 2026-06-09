#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int k;
    cin>>k;
   
    string s;
    cin>>s;
    unordered_map<int,long long>mp;
    vector<int>prefix(s.length()+1,0);
    
    for(int i = 0 ; i<s.length() ; i++){
        prefix[i+1] = prefix[i] + (s[i]=='1');
    }
    long long ans = 0;
    for(int i = 0 ; i<=s.length() ; i++){
        // if(prefix[i]==k) ans++;
        // for(int j = 0 ; j<i ; j++)
            
        //     if(i-1>=0 && (prefix[i]-prefix[j])==k){
        //         ans++;
        
        // }

        // this approach is correct for n^2 solution 
        // how many j exist where prefix[i] - prefix[j] == k
        // i.e prefix[j] == prefix[i] - k
        ans += mp[prefix[i] - k];
        mp[prefix[i]]++;
    }
    cout<<ans<<endl;   
}