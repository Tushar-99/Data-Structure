#include<iostream>
#include<utility>
#include<limits.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int , int>, null_type, less<pair<int , int>>, rb_tree_tag,                tree_order_statistics_node_update> new_data_set; 
int main()
{
    int n, count = 0 , ans = 0;
    //set store unique elements so it does not store repeated elements in the array but we can store multiple elements in the set using pair<int , int>
    new_data_set s;
    //cin >> n;
    int arr[] = { 5 , 2 , 3 , 2 , 3 , 8 , 1 }; 
    n = sizeof(arr)/sizeof(int);

    for(int i = 0 ; i < n ; i++)
    {
        ans = s.size() - s.order_of_key({arr[i] , INT_MAX});
        cout << ans << " ";
        count += ans;
        s.insert({arr[i] , i});
    }

    cout << endl;
    for(auto x:s)
        cout << x.first << " -> " << x.second << " ";

    cout << endl;
    cout << count ;
}
