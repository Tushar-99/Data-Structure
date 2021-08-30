#include<iostream>

using namespace std;

class A
{
    public:
    static int x;
        A()
        {
            cout<<"Construstor called"<<endl;
        }
        ~A()
        {
            //cout<<"Destructor called"<<endl;
        }
        void* operator new(size_t sz)
        {
            x++;
        }
};
int A::x=0;

int main(){
    A a,b;//local --> stack
    A c,d,e;
    
    A* ptr=new A;

    delete ptr;
    cout<<A::x<<endl;
}