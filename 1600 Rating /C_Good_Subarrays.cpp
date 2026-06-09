#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
   
    while(n--){
        int k ;
        cin>>k;
        vector<int>v;
        string s;
        cin>>s;
        for(int i = 0 ; i<k ; i++){
            v.push_back(s[i]-'0');
        }
    
        unordered_map<int,long long>mp;
        vector<int>prefix(v.size()+1,0);
        
        for(int i = 0 ; i<v.size(); i++){
            prefix[i+1] = prefix[i] + (v[i]);
        }
        long long ans = 0;
        for(int i = 0 ; i<=v.size() ; i++){
            ans+= mp[prefix[i]-i];
            mp[prefix[i]-i]++;
        }
       
        cout<<ans<<endl;   
    }
}