#include <iostream>
#include <vector>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    //throw std::logic_error("Waiting to be implemented");
    std::vector<std::string> aSolutionVector;
    for (auto itr : names1) {
        aSolutionVector.push_back(itr);
    }
    
    for (auto itr : names2) {
        bool isNameAlreadyThere = false;
        for (auto itr2 : names1) {
            if (itr.compare(itr2) == 0) {
                isNameAlreadyThere = true;
                break;
            }
        }
        if (!isNameAlreadyThere) {
            aSolutionVector.push_back(itr);
        }
    }
    
    return aSolutionVector;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};
    
    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif