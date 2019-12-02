#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct Base{
	LL a[63];
	void insert(LL x){
		for(int i=62;~i;i--){
			if(x&(1ll<<i)){
				if(!a[i]){a[i]=x;return;}
				x^=a[i];
			}
		}
	}
	LL Max(){
		LL ans=0;
		for(int i=62;~i;i--){
			ans^=(ans&(1ll<<i))?0:a[i];//如果ans第i位不为1就ans^=a[i] 
		}
		return ans;
	}
};
int main(){
	return 0;
}
