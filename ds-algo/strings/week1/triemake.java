import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.math.*;
import java.util.Scanner;
import java.util.HashMap;
public class triemake
{
    public class Node
    {
        char this_char;
        HashMap<Character,Node> nextnodes = new HashMap<Character,Node>();
        Node find(char c)
        {
            return(nextnodes.get(c));
        }
    }
    public static void solve()throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        Scanner sc = new Scanner(System.in);
        
    }
    public static void main(String args[])throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        Scanner sc = new Scanner(System.in);
        solve();
    }
}
