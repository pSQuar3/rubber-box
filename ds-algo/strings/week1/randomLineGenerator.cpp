#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 100000

using std::cin;
using std::cout;
using std::cerr;
using std::floor;
using std::ceil;
using std::vector;
using std::ios;
using std::unordered_map;
using std::endl;
using std::string;
using std::fstream;
using std::ctime;
using std::rand;
using std::srand;

fstream createCase(long long t,long long ch, long long max_size)
{
    fstream outfile("testcases.txt",ios::out);//opening normal file
    if(!outfile)
    {
        cout << "FIle not found" << endl;
        return outfile;
    }
    char gene[] = {'A','T','G','C'};
    srand((unsigned)time(0));
    for(int i=0;i<t;i++)
    {
        int num = (int)(rand()%4);
        outfile << gene[num];
    }
    outfile << endl;
    outfile << ch << endl;
    for(int i=0;i<ch;i++)
    {
        int num = (rand()%max_size)+1;
        for(int j=0;j<num;j++)
            outfile << gene[(int)(rand()%4)];
        outfile << endl;
    }
    return outfile;
}
void displayFile()
{
    fstream otfl("testcases.txt",ios::in);
    if(!otfl)
    {
        cout << "ERROR" << endl;
        return;
    }
    string s;
    cout << "Printing contents of file" << endl;
    while(!otfl.eof())
    {
        otfl >> s;
        cout << s << endl;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
     * t = size of mother string
     * ch = number of reads
     * max_size = maximum length of each read
     *                     t  ch max_size */
    fstream g = createCase(25,12,4);
    cout << ((g)? "Test cases generated":"unsuccessful") << endl;
    g.close();
    displayFile();
    return 0;
}
