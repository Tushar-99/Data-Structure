//the main error i get in sorting pair of map which is value map

//note here u have to care about writing every row and column in sorted order then only your sparse matrix is represented ok

#include<bits/stdc++.h>

using namespace std;

class Element{

public:
    int i;
    int j;
    int x;
};

class Sparse{

private:
    int m;//rows of sparse matrix
    int n;//columns of sparse matrix
    int nums;//no of non zero element of sparse matrix
    Element *e;
    //multimap<int,pair<int,int>> mp;
    //multimap<int,pair<int,int>> ::iterator it = mp.begin();
    //agar app map mae insert hone se pehle hi iterator bana doge toh us case mae map mae 0 value vale elements hoge khali
    //auto it = mp.begin();

public:
    Sparse(int m,int n,int nums){
        this->m = m;
        this->n = n;
        this->nums = nums;
        e = new Element[this->nums];
    }
    void create();

    void Display();

    Sparse operator +(Sparse);
    // bool cmp(const pair<int ,int> &a , const pair<int,int> &b){
    //     return a.second < b.second;
    // }

    friend istream & operator >>(istream &is,Sparse &s);

    //Question is why we use friend function here

    friend ostream & operator <<(ostream &os,Sparse &s);

    friend void fun(ostream,Sparse);

    ~Sparse(){
        delete []e;
    }
};

void Sparse::create(){

    //int a,b,c;

    cout<<"Enter row , column and element value";
    for(int i = 0 ; i < nums ; i++){
        cin>>e[i].i;
        cin>>e[i].j;
        cin>>e[i].x;
    }

    // for(int i = 0 ; i < nums ; i++){
    //     cout<<e[i].i<<" ";
    //     cout<<e[i].j<<" ";
    //     cout<<e[i].x<<" ";
    //     cout<<endl;
    // }
    // for(int i = 0 ; i < nums ; i++){
    //     cin>>a>>b>>c;
    //     mp.insert({a,{b,c}});
    // }

    //sort(mp.begin(),mp.end(),cmp);

    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    // }
    //cout<<it;
    //cout<<it->first;
}

void Sparse::Display(){

    int a , b , k = 0;
    for(a = 0; a < m ; a++){
        for(b = 0 ; b < n ; b++){
            if(a == e[k].i && b == e[k].j)
                cout<<e[k++].x<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    // map<int,pair<int,int>> ::iterator it = mp.begin();
    // auto it = mp.begin();
    // for(i = 0; i < m ; i++){
    //     for(j = 0 ; j < n ; j++){
    //         if(i == it->first && j == it->second.first){
    //             cout<<it->second.second<<" ";
    //             it++;
    //         }
    //         else
    //             cout<<"0 ";
    //     }
    //     cout<<endl;
    // }    
}

//if signature is like void operator >>(istream &is,Sparse &s) then we cannot use cin in this way (cin>>s2>>t; <--not right  cin>>s2; <-- Right) but if signature istream & operator >>(istream &is,Sparse &s) then we can use in this way (cin>>s2>>t);

istream & operator >>(istream &is,Sparse &s){

    int a,b,c;

    cout<<"Enter row , column and element value";
    for(int i = 0 ; i < s.nums ; i++){
        is>>s.e[i].i;
        is>>s.e[i].j;
        is>>s.e[i].x;
    }
    return is;
}

// >> this is extraction operator used with cin
// << this is insertion operator used with cout

ostream & operator <<(ostream &os,Sparse &s){

    int a , b , k = 0;
    for(a = 0; a < s.m ; a++){
        for(b = 0 ; b < s.n ; b++){
            if(a == s.e[k].i && b == s.e[k].j)
                os<<s.e[k++].x<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

Sparse Sparse::operator +(Sparse s2){

    int i , j , k;
    i=j=k=0;
    Sparse *sum = new Sparse(m,n,nums+s2.nums);

    if(m != s2.m || n != s2.n)
        return Sparse(0,0,0);
    
    else{
        while(i < nums && j < s2.nums){

            //here no need copy structure every single element when we assinging structure to another structure all the members will be copied no need to copy element by element
            if(e[i].i < s2.e[j].i) sum->e[k++] = e[i++];

            else if(e[i].i > s2.e[j].i) sum->e[k++] = e[j++];

            else{
                if(e[i].j < s2.e[j].j) sum->e[k++] = e[i++];

                else if(e[i].j > s2.e[j].j) sum->e[k++] = e[j++];

                else{
                    sum->e[k] = e[i];
                    sum->e[k++].x = e[i++].x+s2.e[j++].x;
                }
            }
        }

        for(;i < nums ; i++) sum->e[k++] = e[i];
        for(;j < nums ; j++) sum->e[k++] = s2.e[j];
        sum->nums = k;
    }

    return *sum;
} 

void fun(ostream &os,Sparse &s){

}

int main(){

    int t;
    Sparse s1(5,5,5),s2(5,5,5);
    s1.create();
    cin>>s2>>t;
    s1.Display();
    cout<<endl;
    cout<<s2<<endl;
    Sparse sum = s1 + s2;
    sum.Display();
}