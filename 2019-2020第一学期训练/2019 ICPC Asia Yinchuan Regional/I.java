import java.util.Scanner;
import java.math.*;

public class I{

    public static int fafa(int v){
        if(v<='9'&&v>='0') return v-'0';
        if(v<='Z'&&v>='A') return v-'A'+10;
        if(v<='z'&&v>='a') return v-'a'+36;
        return -1;
    }
	public static String fp(int v){
		if(v<10)return Integer.toString(v+'0');
		if(v<36)return Integer.toString(v-10+'A');
		return Integer.toString(v-36+'a');
	}
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        BigInteger x=new BigInteger(String.valueOf(sc.nextInt()));
        BigInteger y=new BigInteger(String.valueOf(sc.nextInt()));
        String z=sc.nextLine();
        BigInteger m=new BigInteger(String.valueOf(0)),a0=m;
        int len=z.length();
        for(int i=1;i<=len;i++){
            m.multiply(x);
            m.add(new BigInteger(String.valueOf(fafa(z.charAt(i)))));
        }
        String ans="";
        BigInteger yy=new BigInteger(String.valueOf(y));
        while(m.compareTo(a0)==1){
             BigInteger[] bis=m.divideAndRemainder(y);
            int naive=bis[1].intValue();
            ans+=fp(naive);
            m.divide(y);
        }
		String reverse = new StringBuffer(ans).reverse().toString();
		 System.out.println(reverse);
    }
}
import java.util.Scanner;
import java.math.*;

public class Main{

    public static int fafa(char v){
        if(v<='9'&&v>='0') return v-'0';
        if(v<='Z'&&v>='A') return v-'A'+10;
        if(v<='z'&&v>='a') return v-'a'+36;
        return -1;
    }

    public static String too(int v){
        if(v<=9&&v>=0){
            String x=Character.toString((char)(v+'0'));
            return x;
        }
        if(v<=35&&v>=10){
            String x=Character.toString((char)(v+'A'-10));
            return x;
        }
        if(v<=62&&v>=36){
            String x=Character.toString((char)(v+'a'-36));
            return x;
        }
        String yy=" ";
        return yy;
    }

    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        int y=sc.nextInt();
        String z=sc.nextLine();
        BigInteger m=new BigInteger(String.valueOf(0));
        BigInteger pw=new BigInteger(String.valueOf(x));
        int len=z.length();
        for(int i=1;i<len;i++){
            m=m.multiply(pw);
            BigInteger dl=new BigInteger(String.valueOf(fafa(z.charAt(i))));
            //System.out.println(dl);
            m=m.add(dl);
            //System.out.println("m="+m);
        }
        String ans="";
        BigInteger yy=new BigInteger(String.valueOf(y));
        BigInteger ling=new BigInteger(String.valueOf(0));
        if(m.compareTo(ling)==0){
            System.out.print("0");
            return ;
        }
        while(m.compareTo(ling)==1){
            BigInteger[] bis=m.divideAndRemainder(yy);
            int naive=bis[1].intValue();
            //System.out.println("yushu="+naive);
            ans+=too(naive);
            m=m.divide(yy);
        }
        char[] chr = ans.toCharArray();
		
		for (int i = chr.length-1 ; i >= 0; i--) {
			System.out.print(chr[i]);
		}
        //System.out.println(ans);
    }
}