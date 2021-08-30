#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    char a[100] = "I am going to fit now";

    char *ptr = strtok(a , " ");
    cout << ptr << endl;

    while(ptr != NULL)
    {
        ptr = strtok(NULL , " ");
        if(ptr == NULL)
        {
            cout << "NULL mil gaya" << endl;
            break;
        }
        cout << ptr << endl;
    }
}