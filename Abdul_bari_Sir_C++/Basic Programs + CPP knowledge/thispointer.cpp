#include<iostream> 
using namespace std; 
  
/* local variable is same as a member's name */
class Test 
{ 
private: 
   int x,y; 
public: 
   void setX (int x,int y,Test t) 
   { 
       // The 'this' pointer is used to retrieve the object's x value 
       // hidden by the local variable 'x'
       t.x=x;
       t.y=y;
       //this->x=x;// this pointer overridden but still we can use
       //this->y=y;
   } 

   void setX (int x,int y,Test* t) 
   { 
       // The 'this' pointer is used to retrieve the object's x value 
       // hidden by the local variable 'x'
       t->x=x;
       t->y=y;
       //this->x=x;// this pointer overridden but still we can use
       //this->y=y;
   } 

   void print(Test t)
    { 
       cout << "x = " << t.x << endl;
       cout << "y = " << t.y << endl;
       //cout << "y = " << this->y << endl;
    } 
    void print(Test* t)
    { 
       cout << "x = " << t->x << endl;
       cout << "y = " << t->y << endl;
       //cout << "y = " << this->y << endl;
    } 
}; 
  
int main() 
{ 
   Test* obj=new Test;//yaha pae instance create hua hai so object hai toh toh vo initailize ho jayega
   Test obj1;//yaha pae Test type ka variable create hua hai instance nahi isliye iski vlaue garbage aa rhahi hai 
   int x = 20,y = 30; 
   //only accessible if public and have garbage value
   //cout << "obj x=" << obj->x<<endl; 
   //cout << "obj x=" << obj1.x<<endl;
   obj1.setX(x,y,obj1); 
   obj1.print(obj1);
   obj->setX(x,y,obj); 
   obj->print(obj);  
   return 0; 
} 