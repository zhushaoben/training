#include<cstdio>
#define ll long long
inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
inline ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
int main(){
	return 0;
}
