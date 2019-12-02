a,b,s=input().split()
x=int(a)
y=int(b)
len=len(s)
sum=0
base=x
i=0
while i<len:
    k=ord(s[i])
    if s[i] >= '0' and s[i]<='9':
        sum=sum*base+(k-ord('0'))
    elif s[i] >= 'A' and s[i]<='Z':
        sum=sum*base+(k-ord('A')+10)
    elif s[i] >= 'a' and s[i]<='z':
        sum=sum*base+(k-ord('a')+36)
    i=i+1
if sum==0:
    print("0", end="")
    exit()
res=[]
while sum>0:
    res.append(sum%y)
    sum=sum//y
res.reverse()
for j in res:
    if j<=9:
        print(j, end="")
    elif j>=10 and j<=35:
        print(chr(j-10+ord('A')), end="")
    elif j>=36:
        print(chr(j-36+ord('a')), end="")