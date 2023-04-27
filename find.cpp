#include <iostream>
#include <string>
#include <algorithm> //for std::find

int main()
{
    std::string name = "Marcus Aurelius";
    char c = 'v';
    
    std::string::iterator result = std::find(name.begin(),name.end(),c);
    if(result != name.end())
    {
        std::cout << "Found " << c << " in " << name << " at index: " <<result - name.begin() <<std::endl; 
    }else
    {
        std::cout << c << " does not exist in " << name;
    }
}