import java.util.*;
public class wish{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String w = sc.next();

        int a=0,b=0;
        int deuceA=0;
        int deuceB=0;
        for(int i=0;i<w.length();i++)
        {
            if(a < 40 && b <40)
            {
                if(w.charAt(i) == 'A')
                {
                    if(a == 30)
                    {
                        a=40;
                        continue;
                    }
                    else {
                        a += 15;
                        continue;
                    }
                }
                else
                {
                    if(b==30)
                    {
                        b=40;
                        continue;
                    }
                    else{
                        b+=15;
                        continue;}
                }
            }
        else if( b == 40 && a <40) //condition when B is winning
            {
                char x=  w.charAt(i);
                if(x == 'B') {
                    System.out.print("B");
                    a = 0;
                    b = 0;
                    continue;
                }
                else
                {
                    if(a == 30)
                    {
                        a=40;
                        continue;
                    }
                    else
                    {
                        a= a+15;
                        continue;
                    }
                }
            }
