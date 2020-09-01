#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=100000,W=1e9;
vector<int>v;
void work(){
	int n=randint(N,N);
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		int op=randint(1,3),x,y;
		if(op==1||!v.size())op=1,x=randint(1,W),v.push_back(x);
		else if(op==2){
			y=randint(0,v.size()-1);
			auto w=v.begin();
			for(int j=0;j<y;j++)w++;
			x=*w,v.erase(w);
		}
		else x=randint(1,W);
		printf("%d %d\n",op,x);
	}
	puts("");
}
int main(){
//	prime();
	srand(time(NULL));
	int t=randint(1,1);
//	printf("%d\n",t);
	while(t--)work();
	return 0;
}
