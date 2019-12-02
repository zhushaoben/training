#include<bits/stdc++.h>
using namespace std;
void work(){
	int r,g,b;scanf("%d%d%d",&r,&g,&b);
	if(r>g)swap(r,g);if(g>b)swap(g,b);
	printf("%d\n",b>(r+g)?r+g:(b+r+g)/2);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
