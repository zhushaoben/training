#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
map<string,int>mp;
string s[N];
int main(){
	int n,ma=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];mp[s[i]]++;
		ma=max(ma,mp[s[i]]);
	}
	sort(s,s+n);
	for(int i=0;i<n;i++){
		if(mp[s[i]]==ma)mp[s[i]]=0,cout<<s[i]<<"\n";
	}
	return 0;
}
