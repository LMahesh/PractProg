#include "integer_container_impl.h"

// TODO: implement interface methods here

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

//IntegerContainerImpl::ADD(int value)
int IntegerContainerImpl::Add(int value) {
    v1.push_back(value);
    // TODO: implement
    int a = v1.size();
    return a;
}

bool IntegerContainerImpl::Delete(int value) {



    auto it = find(v1.begin(), v1.end(), value);
    if (it != v1.end())
    {
        v1.erase(it);
        // TODO: implement
        return true;
    }
    return false;
}

int IntegerContainerImpl::GetMedian()
{
    std::sort(v1.begin(), v1.end());
    int n = v1.size();


    if (n == 0)
        return NULL;
    //   throw std::runtime_error(" container empty");;

    if (n == 1)
        return v1[0];


    if (n % 2 != 0)
        return v1[((n + 1) / 2) - 1];
    else

        return  v1[(n / 2 - 1)];
}