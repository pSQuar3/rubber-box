import java.io.*;
import java.util.*;
import java.math.*;

public class step_java
{
    public static void main(String args[])throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long D[][] = new long[n+1][n+1];
        long a[] = new long[n];
        for(int i=0;i<n;i++)
        {
            a[i] = sc.nextInt();
            D[i][i] = 1;
        }
        D[n][n] = 1;
        long mx = -1;
        for(int l=1;l<=n-1;l++) 
        {
            for(int r=l+1;r<=n;r++)
            {
                if(a[r-1] >= a[r-2])
                {
                    D[l][r] = D[l][r-1] + 1;
                    if(D[l][r] > mx)
                        mx = D[l][r];
                }
                else
                    D[l][r] = 1;
            }
        }
        System.out.println(mx);
    }
}
