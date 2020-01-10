#include "transition_engine.h"

void TransitionEngine::update(const std::chrono::microseconds &delta)
{
    for (Transition &item : m_transitionList)
    {
        item.addToElapsed(delta);
    }
}

void TransitionEngine::startContract(const TransitionContract &contract)
{
    m_transitionList.push_back(Transition(contract));
}
