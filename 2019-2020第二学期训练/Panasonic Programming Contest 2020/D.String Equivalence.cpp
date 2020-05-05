#include<bits/stdc++.h>
using namespace std;
char s[20];int n;
void work(int d,int w){
	if(!d){
		puts(s);
		return;
	}
	for(int i='a';i<w;i++){
		s[n-d]=i;work(d-1,w);
	}
	s[n-d]=w;work(d-1,w+1);
}
int main(){
	scanf("%d",&n);
	work(n,'a');
	return 0;
}
