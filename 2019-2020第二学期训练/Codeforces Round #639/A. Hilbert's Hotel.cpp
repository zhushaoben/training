#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void work(){
	int x,n;scanf("%d",&n);
	for(int i=0;i<n;i++)a[i]=0;
	for(int i=0;i<n;i++)scanf("%d",&x),a[(((i+x)%n)+n)%n]++;
	for(int i=0;i<n;i++)if(!a[i]){puts("NO");return;}
	puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
