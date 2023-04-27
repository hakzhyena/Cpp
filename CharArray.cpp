//Traversing through a character array using pointers
#include <iostream>
#include <string>

using namespace std;

void printArray(const char* start, const char* end)
{
     while(start != end)
   {
      std::cout << *start << ", ";
      start++;
   }
     std::cout << std::endl;
}

void printString(std::string::const_iterator begin, std::string::const_iterator end)
{
   while(begin != end)
   {
      cout << *begin << ", "; 
      begin++;
   }
   cout << endl;
}

void printStringInReverse(std::string::reverse_iterator begin, std::string::reverse_iterator end)
{
   while(begin != end)
   {
      cout << *begin << ", ";
      begin++;
   }
   cout << endl;
}

void printArrayInReverse(const char *begin, const char* end)
{
   unsigned int elements = end  - begin;
   
   end--;
   
   while(elements > 0)
   {
      cout << *end << ", ";
      end--;
      elements--;
   }
   cout << endl;
}

int main()
{
   const char name[] {'T','o','m'}; // Now what would be the size of array? 3 or 4? Let's find out
   std::cout << "Size of the name array in terms of bytes: " << sizeof(name) << std::endl;
   const char place[] {"USA"};
   std::cout << "Size of the place array in terms of bytes: " << sizeof(place) << std::endl;
   //So I received 3 for name array and 4 for place array. That means when using string literal an end of array character is appended by default
   //Let's just traverse through them using pointers and print them
   
   printArray(name,  name + 3);//Note that name + 3 is pointing to one-past-last element and this is still legal per C++ standard
   printArray(place, place + 3); // 3 because at 3rd index we have null character 
   
   //Now let's do the same experiment with using iterators for std::string
   std::string strName {"Tom"}; // I am not sure if Tom would have a null character at end, let's check - no! where as char array contained a null char at end, weird!
   std::cout << "Size of strName in terms of elements: " << strName.size() << std::endl;
   std::string strPlace {"USA"};
   std::cout << "Size of strPlace in terms of elements: " << strPlace.size() << std::endl;
   
   printString(strName.cbegin(), strName.cend());
   printString(strPlace.cbegin(), strPlace.cend());
   
   cout << "Print Array in reverse" << endl;
   printArrayInReverse(name,  name + 3);
   printArrayInReverse(place, place + 3); 
   
   cout << "Print String in reverse" << endl;
   printStringInReverse(strName.rbegin(), strName.rend());
   printStringInReverse(strPlace.rbegin(), strPlace.rend());
   
}

