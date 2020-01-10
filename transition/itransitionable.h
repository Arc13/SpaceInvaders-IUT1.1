#ifndef ITRANSITIONABLE_H
#define ITRANSITIONABLE_H

#include <vector>

class ITransitionable
{
public:
    virtual ~ITransitionable() {}

    virtual void getValues(const int &id, std::vector<float> &values) = 0;
    virtual void setValues(const int &id, const std::vector<float> &values) = 0;
};

#endif // ITRANSITIONABLE_H
