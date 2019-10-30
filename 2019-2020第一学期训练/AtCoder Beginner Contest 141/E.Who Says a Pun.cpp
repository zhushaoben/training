#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;string s;
	cin>>n>>s;
	int l=0,r=1;
	while(r<=n){
		string tmp=s.substr(l,r-l);
		if(s.find(tmp,r)<n)ans=max(ans,r-l),r++;
		else l++,r++;
	}
	cout<<ans; 
	return 0;
} 
