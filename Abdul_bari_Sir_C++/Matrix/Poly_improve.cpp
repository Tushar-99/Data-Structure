#include<bits/stdc++.h>

using namespace std;

class Poly{

private:
    int n;
    vector<pair<int,int>> t;

public:
    Poly(){

    }
    Poly(int n){
        this->n = n;
    }

    friend istream & operator >>(istream &is,Poly &p);

    friend ostream & operator <<(ostream &os,Poly &p);

    int eval(int);

    Poly operator +(Poly &p);
};

istream & operator >>(istream &is,Poly &p){

    int x,y;
    cout<<"Enter the coefficients and exoponents of polynomial";
    for(int i = 0 ; i < p.n ;i++){
        cin>>x>>y;
        p.t.push_back({x,y});
    }

    return is;
}

ostream & operator <<(ostream &os,Poly &p){

    int temp;
    for(int i = 0 ; i < p.t.size() ; i++){
        cout<<p.t[i].first<<" x^"<<p.t[i].second;
        temp = i;
        if(++temp < p.t.size()){
            cout<<" + ";
        }
    }
    cout<<endl;
    cout<<p.n<<endl;
    return os;
}

int Poly::eval(int x){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += t[i].first * pow(x,t[i].second);
    }
    return sum;
}

Poly Poly::operator +(Poly &p){

    int i,j,k;
    i=j=k=0;
    Poly *pa = new Poly();
    while(i < n && j < p.n){
        if(t[i].second > p.t[j].second) pa->t[k++] = t[i++];

        else if(t[i].second < p.t[j].second) pa->t[k++] = p.t[j++];

        else{
            pa->t[k].second = t[i].second;
            pa->t[k++].first = t[i++].first + p.t[j++].first;
        }
    }
    
    for(;i < n ; i++) pa->t[k++] = t[i]; 
    for(;j < p.n ; j++) pa->t[k++] = t[j];
    
    pa->n = k; 

    return *pa;
}

int main(){

    Poly p1(5),p2(3);
    cin>>p1>>p2;
    cout<<p1<<endl<<p2<<endl;
    cout<<p1.eval(3)<<endl;
    Poly add = p1+p2;
    cout<<add;
}