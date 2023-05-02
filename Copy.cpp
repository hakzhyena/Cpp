//Deep copy vs shallow copy + the Big three of the class, still need to learn about move related things ...

#include <iostream>

class A
{
  public:
  int i, j, *p;
 
  void print()
  {
     std::cout << i << ' ' << j << ' ' << p << ' ' << *p << ' ' << std::endl;
  }
  A()
  {
     i = j = 0;
     p = nullptr;
  }
  A(int i, int j, int *p) : i{i}, j{j}, p{p}{}
  A(const A& other) : i{other.i}, j {other.j}
  {
      p = new int;
      *p = *(other.p);
  } 
  A& operator = (const A& other)
  {
     i = other.i;
     j = other.j;
     if(p)
     delete p;
     p = new int;
     *p = *(other.p);
     return *this;
  }
  ~A()
  {
     delete p;
  }
};

int main()
{
   int temp = 10;
   A a{10,20, &temp}; //aggregate initialization works only if all the members are public.
   std::cout << "Printing a " << std::endl;
   a.print(); 
   A b = a;
   std::cout << "Printing b " << std::endl;
   b.print();
   temp = 30;
   std::cout << "Printing a " << std::endl;
   a.print(); 
   std::cout << "Printing b " << std::endl;
   b.print(); 
    A c;
    c = b;
   std::cout << "Printing c " << std::endl;
   c.print();
   
   //By looking at the results, you can see that the default copy constructor does shallow copy, where as if you want to go for deep copy -
   // - then implement the copy constructor yourself, also the rule of if you implement one of them implement all of them (constructor(s), destructor and copy - - assignment).
   
}