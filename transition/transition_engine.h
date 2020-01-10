#ifndef TRANSITION_ENGINE_H
#define TRANSITION_ENGINE_H

#include <chrono>
#include <memory>
#include <vector>

#include "transition.h"

class TransitionEngine
{
public:
    void update(const std::chrono::microseconds &delta);
    void startContract(const TransitionContract &contract);

private:
    std::vector<Transition> m_transitionList;
};

#endif // TRANSITION_ENGINE_H
