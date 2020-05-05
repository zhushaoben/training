#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=1e3;
void work(){
	int n=randint(1,N);
	for(int i=0;i<n;i++)putchar('a'+randint(0,2));
	puts("");
}
int main(){
	srand(time(NULL));
	int t=randint(1,5);
	while(t--)work();
	puts("#");
	return 0;
}
