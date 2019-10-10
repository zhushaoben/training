#include<bits/stdc++.h>
#define pb push_back
using namespace std;
multiset<int> s;
vector<int> a,b;
int n,x;
int main(){
	cin>>n;
	for (int i=0;i<(1<<n);i++){cin>>x;s.insert(x);}
	auto no=s.end();no--;
	a.pb(*no);s.erase(no);
	for (int i=1;i<=n;i++){
		for (auto j:a){
			auto k=s.lower_bound(j);
			if (k==s.begin()){puts("No");return 0;}
			k--;b.pb(*k);s.erase(k);
		}
		for (auto j:b)a.pb(j);b.clear();
	}
	puts("Yes");
	return 0;
}

