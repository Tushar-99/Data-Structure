#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N , opp ,no , temp = 0 , sum = 0;
    priority_queue <int> pq;
    cout << "Enter the size of the Array"<<endl;
    cin >> N;
    int *arr = new int[N];
    cout << "Enter the no of opeartions"<<endl;
    cin >> opp;
    cout << "Enter the elements of the array"<<endl;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> no;
        pq.push(no);
        sum = sum + no;
    }
    
    for(int i = 1 ; i <= opp ; i++)
    {
        temp = pq.top();
        pq.pop();
        sum = sum - temp;
        pq.push(temp/2);
        sum = sum + temp/2;
    }
    cout << sum;
}