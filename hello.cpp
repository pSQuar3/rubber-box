#include <iostream>
//include the math header file to access functions like sin cos, etc.

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;
const int MAX = 3;
static int count = 10;
bool conditional_statement(string s)
{
    bool k = (s == "hello")? true:false;
    return k;
}
void print_random_numbers()
{
    srand((unsigned)time(NULL)); // planting the seed for the random number generation as the time of the system in seconds
    for(int i=0;i<10;i++)
    {
        int j = rand();
        cout << "Random number = " << j << endl;
    }
}
int checkError()
{
    unsigned int k;
    cin >> k;
    return k;
}
int maximum(int a, int b)
{
    return (a > b)? a:b;
}
void static_var_demonstrate()
{
    static int i = 5; // local static variable
    i++;
    std::cout << "i is " << i ;
    std::cout << " and count is " << count << std::endl;
}

int pointerfunc()
{
    int  var[MAX] = {10, 100, 200};
 
    for (int i = 0; i < MAX; i++)
    {
        *var = i;    // This is a correct syntax
//        var++;       // This is incorrect.
    }
    return 0;
}
int* bubble_sort(int *arr)
{
    for(int i=0;i<sizeof(arr);i++)
    {
        for(int j=0;j<sizeof(arr)-i+1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                //condition to sort the elements of the array
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    return arr;
}

void diff_modifiers()
{
    short int i;           // a signed short integer
    short unsigned int j;  // an unsigned short integer
    
    j = 50000;
    
    i = j;
    cout << i << " " << j;
}

void String_Handling()
{
    cout << "C-style character string" << endl;
    string s = "Hello";
    string s2 = "World";
}
void side()
{
    typedef int length;
    length h = 90;
    cout << "Length = " << h << endl;
}
void displayAddress()
{
    int rt = 0;
    int *ptr = &rt;
    cout << "Address of the number: "<<&rt << endl;
    cout << "Address of ptr = " << ptr << endl;
    cout << "Value of ptr = " << *ptr << endl;
    ptr++;
    cout << "Value of ptr after increment " << *ptr << endl;
}
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    //hello ob = new hello();
    /*cout << "Hello World" << "\n";
    cout << "Size of char" << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of: " << sizeof(long) << endl;
    int f = 9;
    int k = ++f;
    cout << "The values are: " << f << " " << "The second set: " << ++k + f++ << endl;
    side();*/
    cout << "Displaying the address of the variable: " << endl;
    displayAddress();
    cout << "Demonstration of the static variables: " << endl;
    while(count--)
        static_var_demonstrate();
    cout << "Conditional statements testing: " << endl;
    //cin << "Enter the number of elements: " << k << endl;
    cout << conditional_statement("hello") << endl;
    cout << "Return max or min" << endl;
    cout << maximum(23,25);
    cout << "Random number printing: " << endl;
    print_random_numbers();
    cout << "Bubble Sort";
    int len = 10;
    int arr[] = {34,53,23,45,32,6,35,980,34,67,54,24};
    /*for(int i=0;i<10;i++)
        arr[i] = 10-i;*/
    int *sorted = bubble_sort(arr);
    for(int i=0;i<10;i++)
        cout << sorted[i] << " ";
    cout << "Checking for an expected error: ";
    unsigned int num = checkError();
    cout << "Finally recorded number = " << num << endl;
    cout << "Swapping 2 integers using pointers:" << endl;
    cout << "Enter the first number: ";
    int num1, num2;
    cin >> num1 >> num2;
    //cout << "Enter the second number: " ;
    //cin >> num2;
    swap(&num1,&num2);
    cout << "First number = " << num1 << " Second number = " << num2 << endl;
    cout << "Taking inputs: " << endl;

    return 0;
}

