#include <iostream>

using namespace std;

typedef long long int LL;

LL gcd(LL a, LL b) {
    return a%b==0?b:gcd(b, a%b);
}

LL lcm(LL a, LL b) {
    return a/gcd(a, b)*b;
}

int main() {
    LL n, m;
    while(cin>>n>>m) {
        LL a[n];
        LL lcmAll = 1;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            lcmAll = lcm(lcmAll, a[i]);
        }
        LL sum = 0;
        for(int i=0; i<n; i++) {
            a[i] = lcmAll/a[i];
            sum += a[i];
        }
        if(m%sum) {
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
            LL times = m/sum;
            cout<<a[0]*times;
            for(int i=1; i<n; i++) {
                cout<<" "<<a[i]*times;
            }
            cout<<endl;
        }
    }

    return 0;
}
