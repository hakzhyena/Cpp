#include <iostream>
#include <string>
using namespace std;

class Demo
{
   int i;
   string s;
   public:
   // if you have provided a constructor then compiler doesn't provide one. So there's no default constructor now and Demo d resulted in error: no appropriate default constructor available
   // parameterized constructor
   Demo(int i, const string &s) : i(i), s(s) 
   {
      //s is const reference, const because we are not going to modify the variable rereferenced by s, reference to save from the copy.
      // initialization is done in the order the member variables are declared in the class, not necassarily in the order the member initialization list lists them
      
   }
   //default constructor
   Demo()
   {
      i = 1;
      s = "Harish";
   }
   //copy constructor
   Demo(const Demo &other):i(other.i), s(other.s){}
   //Assignment operator
   Demo& operator=(Demo &other)
   {
      i = other.i;
      s = other.s;
      return *this;
   }
   //Destructor
   ~Demo()
   {
   
   }
   
   void Print()
   {
      cout << i << ", " << s << endl;
   }
   
};
int main()
{
      Demo a; 
      a.Print(); //Would print 1, Harish since a would have the same after the default initialization.
      Demo b{2,"Adrien"}; 
      b.Print(); //Would print 2, Adrien since b would have the same after the parameterized constructor is called on it.
      Demo c {b}; 
      c.Print(); // Would print 2, Adrien since c would have the same after the copy initialization.
      Demo d{2, "Jack"};
      d = a;
      d.Print(); //Would print 1, Harish since d is assigned with the value of a using assignment operator
      d = c = b = a;
      cout << "-----------------" << endl;
      //All the following four statements would print 1, Harish since the assignment operator returns the reference of assigned object
      a.Print();
      b.Print();
      c.Print();
      d.Print();
}