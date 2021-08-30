#include<bits/stdc++.h>

using namespace std;

class Term{

public:
    int coeff;
    int expo;
};

class Poly{

private:
    int n;
    Term *t;
    //vector<pair<int,int>> t;

public:
    Poly(){

    }
    Poly(int n){
        this->n = n;
        t = new Term[this->n];
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
        // cin>>x>>y;
        // p.t.push_back({x,y});
        cin>>p.t[i].coeff>>p.t[i].expo;

    }
    return is;
}

ostream & operator <<(ostream &os,Poly &p){

    int temp;
    for(int i = 0 ; i < p.n ; i++){
        cout<<p.t[i].coeff<<" x^"<<p.t[i].expo;
        temp = i;
        if(++temp < p.n){
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
        sum += t[i].coeff * pow(x,t[i].expo);
    }
    return sum;
}

Poly Poly::operator +(Poly &p){

    int i,j,k;
    i=j=k=0;
    Poly *pa = new Poly();
    while(i < n && j < p.n){
        if(t[i].expo > p.t[j].expo) pa->t[k++] = t[i++];

        else if(t[i].expo < p.t[j].expo) pa->t[k++] = p.t[j++];

        else{
            pa->t[k].expo = t[i].expo;
            pa->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
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