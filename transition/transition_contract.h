#ifndef TRANSITION_CONTRACT_H
#define TRANSITION_CONTRACT_H

#include <chrono>
#include <vector>

#include "itransitionable.h"

class TransitionContract
{
public:
    typedef std::chrono::time_point<std::chrono::system_clock>  SystemTimePoint_t;
    typedef std::chrono::duration<float, std::nano>              SystemDuration_t;

    TransitionContract(ITransitionable& target, const int &id, const std::chrono::seconds &duration, const std::vector<float> &destination);

    const int& what() const;
    const ITransitionable& where() const;

    const std::vector<float>& getDestination() const;

protected:
    const int m_id;
    ITransitionable& m_target;

    std::vector<float> m_beginning;
    const std::vector<float> m_destination;

    SystemTimePoint_t m_startTime;
    SystemDuration_t m_duration;
};

#endif // TRANSITION_CONTRACT_H
