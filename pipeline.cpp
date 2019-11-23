/*
As part of a data processing pipeline, complete the implementation of the makePipeline method:

The method should accept a vector of functions, 
and it should return a new function that accepts one parameter arg.

The returned function should call the first function in the makePipeline with the parameter arg, 
and call the second function with the result of the first function.

The returned function should continue calling each function in the makePipeline in order,
following the same pattern, and return the value from the last function.
*/

#include <iostream>
#include <functional>
#include <vector>

template<class T>
std::function<T (T)> makePipeline(const std::vector<std::function<T (T)>>& funcs) {
    return [&funcs] (const T& arg) {
        auto result = arg;
        for (auto itr : funcs) {
            result = itr(result);
        }
        return result;
    };
}

#ifndef RunTests
int main()
{
    std::vector<std::function<int (int)>> functions;
    functions.push_back([] (int x) -> int { return x * 3; });
    functions.push_back([] (int x) -> int { return x + 1; });
    functions.push_back([] (int x) -> int { return x / 2; });
    
    std::function<int (int)> func = makePipeline(functions);
    std::cout << func(3); // should print 5
}
#endif