// #include<bits/stdc++.h>

// using namespace std;

// string binary(int no){
//     int rem;
//     string binary;
//     while(no){
//         rem = no%2;
//         binary = 
//         no = no/2;
//     }
// }

// int main(){

//     int size , i ,j;
//     string temp;
//     cin>>size;
//     vector<int> v;
//     map<int,int> bin;
//     int arr[size];
//     for(i = 0 ; i < size ; i++){
//         cin>>arr[i];
//     }
//     sort(arr,arr+size);
//     for(i = 0 ; i < size ; i++){
//         temp = binary(arr[i]);
//         bin.insert(pair<int,string> (arr[i], temp));
//     }
//     for()

//     for(i = 0 ; i < size ; i++){
//         for(j = i ; j < size ;j++){
//             v.push_back(arr[j]);
//         }
//     }     
// }

#include<bits/stdc++.h>
using namespace std;

void calc(int i,vector<int> &v1,int siz,int s,int &tot){
    if(i==siz){
        if(s==0)
            tot++;
        return;
    }

    calc(i+1,v1,siz,s+v1[i],tot);
    calc(i+1,v1,siz,s,tot);
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) 
        cin>>i;
    
    int m=0;

    for(int i=0;i<n;i++){
        if(v[i] > m)
            m = v[i];
    }
    int count=0;

    while(m){
        count++;
        m=m>>1;
    }
    vector<int> v1(n,0);
    for(int i=0;i<n;i++){
        while(v[i]){
            if(v[i]&1)
                v1[i]++;
                
            v[i]=v[i]>>1;
        }
    }
    int j=0;
    for(int i=0;i<n;i++){
        v1[j]=count-2*v1[i];
        if(v1[j]==0)
            continue;
        else
            j++;
        }
    int tot=0;
    calc(0,v1,j,0,tot);
    tot-=1;
    tot=tot*(1+n-j)+(1<<(n-j))-1;
    vector<int> bin(count,0); 
    int i=0;
    while (tot > 0) { 
  
        bin[i] = tot &1; 
        tot = tot>>1; 
    i++;
    } 
    for(int j = count-1 ; j >= 0 ; j--){
        cout<<bin[j];
    }
}
