#include "transition_engine.h"

#define TRANSITIONENGINE nsTransition::TransitionEngine

void TRANSITIONENGINE::update(const std::chrono::microseconds &delta)
{
    // Update every transitioned items
    TransitionVector_t::iterator iter = m_transitionList.begin();
    while (iter != m_transitionList.end())
    {
        // Check if the item is finished, and remove it from the list in that case
        if (iter->isFinished())
        {
            m_transitionList.erase(iter++);
        }
        else
        {
            iter->addToElapsed(delta);
            ++iter;
        }
    }
} // update()

void TRANSITIONENGINE::startContract(const TransitionContract &contract)
{
    m_transitionList.push_back(Transition(contract));
} // startContract()

#undef TRANSITIONENGINE
