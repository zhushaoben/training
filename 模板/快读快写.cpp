#include<cstdio>
#include<iostream>
using namespace std;
inline char getc(void) { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read(void) { 
    register int res = 0;
    register char tmp = getc();
    register bool f = true;
    while(!isgraph(tmp)) tmp = getc();
    if(tmp == '-') f = false, tmp = getc();
    while(isdigit(tmp))
        res = ((res + (res << 2)) << 1) + (tmp ^ 0x30),
        tmp = getc();
    if(f) return res;
    return ~res + 1;
}
char ops[1 << 18], *opt = ops, *const opt_end = ops + (1 << 18);
inline void write_all(void) { 
    fwrite(ops, 1, opt - ops, stdout);
    opt = ops; return ;
}
inline void write(int x) { 
    static char *p = new char[20]();
    if(x < 0) { 
        *(opt++) = '-';
        if(opt == opt_end) write_all();
    }
    do{ 
        *(++p) = (x % 10) | 0x30;
        x /= 10;
    }while(x);

    while(*p) { 
        *(opt++) = *(p--);
        if(opt == opt_end) write_all();
    }
    *(opt++) = ' ';
    if(opt == opt_end) write_all();
}
int main(){
	return 0;
} 
