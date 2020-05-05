#include<bits/stdc++.h>
using namespace std;
string s;
map<string,int>mp;
int main(){
	int n,ans=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(!mp[s])mp[s]=++ans;
	}
	printf("%d",ans);
	return 0;
}
