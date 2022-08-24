

import java.util.*;
public
class Aditya
{
public
    static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String w = sc.next();

        int a = 0, b = 0;
        int deuceA = 0;
        int deuceB = 0;
        for (int i = 0; i < w.length(); i++)
        {
            if (a < 40 && b < 40)
            {
                if (w.charAt(i) == 'A')
                {
                    if (a == 30)
                        a = 40;
                    else
                        a += 15;
                }
                else
                {
                    if (b == 30)
                        b = 40;
                    else
                        b += 15;
                }
            }
            else if (b == 40 && a < 40) // conditon when B is winning
            {
                char x = w.charAt(i);
                if (x == 'B')
                {
                    System.out.print("B");
                    a = 0;
                    b = 0;
                }
                else
                {
                    if (a == 30)
                        a = 40;
                    else
                    {
                        a = a + 15;
                    }
                }
            }

            else if (a == 40 && b < 40) // condition when A is winning
            {
                char x = w.charAt(i);
                if (x == 'A')
                {
                    System.out.print("A");
                    a = 0;
                    b = 0;
                }
                else
                {
                    if (b == 30)
                        b = 40;
                    else
                        b += 15;
                }
            }
            else if (a == 40 && b == 40) // condition when deuce
            {
                if (w.charAt(i) == 'A' && deuceA == 0)
                {
                    deuceA++;
                }
                else if (w.charAt(i) == 'A' && deuceA == 1)
                {
                    deuceA = 0;
                    deuceB = 0;
                    System.out.print("A");
                    a = 0;
                    b = 0;
                }
                else if (w.charAt(i) == 'B' && deuceB == 0)
                {
                    deuceB++;
                }
                else if (w.charAt(i) == 'B' && deuceB == 1)
                {
                    deuceA = 0;
                    deuceB = 0;
                    System.out.print("B");
                    a = 0;
                    b = 0;
                }
                else if (w.charAt(i) == 'B' && deuceA == 1)
                {
                    deuceA = 0;
                    deuceB = 0;
                    a = 0;
                    b = 0;
                }

                else if (w.charAt(i) == 'A' && deuceB == 1)
                {
                    deuceA = 0;
                    deuceB = 0;
                    a = 0;
                    b = 0;
                }
            }
        }
    }
}