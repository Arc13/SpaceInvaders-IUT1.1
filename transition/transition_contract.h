#ifndef TRANSITION_CONTRACT_H
#define TRANSITION_CONTRACT_H

#include <chrono>
#include <functional>
#include <vector>

#include "itransitionable.h"

class TransitionContract
{
public:
    typedef std::chrono::time_point<std::chrono::system_clock> SystemTimePoint_t;
    typedef std::chrono::duration<float, std::nano>            SystemDuration_t;

    enum TransitionMode {
        MODE_FINITE,
        MODE_LOOP,
        MODE_LOOP_SMOOTH,
    };

    TransitionContract(ITransitionable& target, const int &id,
                       const std::chrono::seconds &duration, const std::vector<float> &destination,
                       const TransitionMode &transitionMode = TransitionMode::MODE_FINITE);

    const int& what() const;
    const ITransitionable& where() const;

    const std::vector<float>& getDestination() const;
    const TransitionMode& getTransitionMode() const;

    void setFinishCallback(const std::function<void()> &callback);

protected:
    const int m_id;
    ITransitionable& m_target;
    const TransitionMode m_transitionMode;

    std::vector<float> m_beginning;
    const std::vector<float> m_destination;

    SystemDuration_t m_duration;

    std::function<void()> m_finishCallback;
};

#endif // TRANSITION_CONTRACT_H
