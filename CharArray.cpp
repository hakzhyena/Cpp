//Traversing through a character array using pointers
#include <iostream>

void printArray(const char* start, const char* end)
{
     while(start != end)
   {
      std::cout << *start << ", ";
      start++;
   }
     std::cout << std::endl;
}
int main()
{
   const char name[] = {'T','o','m'}; // Now what would be the size of array? 3 or 4? Let's find out
   std::cout << "Size of the name array in terms of bytes: " << sizeof(name) << std::endl;
   const char place[] = "USA";
   std::cout << "Size of the place array in terms of bytes: " << sizeof(place) << std::endl;
   //So I received 3 for name array and 4 for place array. That means when using string literal an end of array character is appended by default
   //Let's just traverse through them using pointers and print them
   
   const char* startOfArray = name;
   const char* endOfArray= name + 3; //Note that endOfArray is pointing to one-past-last element and this is still legal per C++ standard
   printArray(startOfArray, endOfArray);
   //Reassign pointers to place character array
    startOfArray = place;
    endOfArray = place + 3; // 3 because at 3rd index we have null character 
    printArray(startOfArray, endOfArray);
   
}

