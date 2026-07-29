#ifndef INTEGER_CONTAINER_IMPL_HPP_
#define INTEGER_CONTAINER_IMPL_HPP_

#include "integer_container.h"
#include<vector>
using namespace std;

class IntegerContainerImpl : public IntegerContainer {

public:
    bool Delete(int value)override;
    int Add(int value)override;

    int GetMedian()override;

    std::vector<int>v1;

};

#endif  // INTEGER_CONTAINER_IMPL_HPP_
