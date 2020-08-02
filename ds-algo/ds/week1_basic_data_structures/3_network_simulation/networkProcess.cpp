#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Buffer
{
    int start_time,end_time;
    public:
    Buffer(int a,int b)
    {
        start_time = a;
        end_time = b;
    }
    int st()
    {
        return start_time;
    }
    int et()
    {
        return end_time;
    }
};

int main()
{
    int S,n;
    cin >> S >> n;
    queue<Buffer> buffer;
    int arr[n],proc[n];
    for(int i=0;i<n;i++)
        cin >> arr[i] >> proc[i];
    //cout << "accepted details" << endl;
    int dec[n];
    int currentEndTime=arr[0];
    //cout << "size of buffer = " << buffer.size() << endl;
    for(int i=0;i<n;i++)
    {
        //cout << "i = " << i << endl;
        /*
        cout << "buffer: " << endl;
        for(int i=0;i<buffer.size();i++)
            cout << buffer.st() << " " << buffer[i].et() << endl;
        */
        /*
        if(!buffer.empty())
        {
            if(buffer.front().et() <= arr[i] && currentEndTime <= arr[i])// && buffer.back().st() > arr[i])
            {
                buffer.pop();
                currentEndTime += buffer.front().st() + buffer.front().st();
            }
            if(buffer.size() < S+1 && (arr[i] > buffer.front().st() || buffer.empty()))
            {
                //cout << "first if block: arr[i] = " << arr[i] << " proc[i] = " << proc[i] << endl;
                int k = arr[i];
                if(!buffer.empty())
                    k = max(buffer.back().et(),arr[i]);
                Buffer ob(k,k+proc[i]);
                buffer.push(ob);
                dec[i] = k;
            }
            else
                dec[i] = -1;
        }
        else
        {
            if(currentEndTime <= arr[i]+proc[i])
            {
                //send network packge to processor
                currentEndTime = arr[i] + proc[i];
                dec[i] = arr[i];
            }
            else
            {
                //cout << "last else block\n";
                int k = arr[i];
                //if(!buffer.empty())
                //    k = max(buffer.back().et(),arr[i]);
                Buffer ob(k,k+proc[i]);
                buffer.push(ob);
                dec[i] = arr[i];
            }
        }
        */
        if(buffer.empty())
        {
            Buffer ob(arr[i],arr[i]+proc[i]);
            buffer.push(ob);
            dec[i] = arr[i];
        }
        else
        {
            bool b = true;
            //if(arr[i] >= buffer.front().st() && buffer.size() < S+1)
            if(buffer.size() < S+1)
            {
                if(arr[i] > buffer.front().st())
                {
                    b = false;
                    int k = max(arr[i],buffer.back().et());
                    Buffer ob(k,k+proc[i]);
                    buffer.push(ob);
                    dec[i] = k;
                    if(arr[i] > buffer.front().et())
                    {
                        buffer.pop();
                        //dec[i] = arr[i];
                    }
                }
                else if(arr[i] == buffer.front().st())
                {
                    int k = max(arr[i],buffer.back().et());
                    Buffer ob(k,k+proc[i]);
                    buffer.push(ob);
                    dec[i] = k;
                }
            }
            else
                dec[i] = -1;
            /*if(arr[i] >= buffer.front().et() && b)
            {
                buffer.pop();
                dec[i] = arr[i];
            }*/
            if(arr[i] >= buffer.back().et())
            {
                while(!buffer.empty())
                {
                    buffer.pop();
                }
                Buffer ob(arr[i],arr[i]+proc[i]);
                buffer.push(ob);
                dec[i] = arr[i];
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << dec[i] << endl;
    return 0;
}
