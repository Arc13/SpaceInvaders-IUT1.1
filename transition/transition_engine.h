#ifndef TRANSITION_ENGINE_H
#define TRANSITION_ENGINE_H

#include <chrono>
#include <memory>
#include <list>

#include "transition.h"

namespace nsTransition
{

class TransitionEngine
{
public:
    void update(const std::chrono::microseconds &delta);
    void startContract(const TransitionContract &contract);

private:
    typedef std::list<Transition> TransitionVector_t;

    TransitionVector_t m_transitionList;
};

} // namespace nsTransition

#endif // TRANSITION_ENGINE_H
