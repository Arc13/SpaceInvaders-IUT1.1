#include "transition.h"

Transition::Transition(const TransitionContract &contract)
    : TransitionContract(contract)
    , m_elapsed(0)
{}

const TransitionContract::SystemDuration_t& Transition::getElapsed() const
{
    return m_elapsed;
}

void Transition::setElapsed(const TransitionContract::SystemDuration_t &elapsed)
{
    // Set the new elapsed time
    m_elapsed = elapsed;

    // Compute the new values
    float elapsedPercent = m_elapsed / m_duration;
    std::vector<float> updatedValues(m_beginning.size());
    for (size_t i = 0; i < m_beginning.size(); ++i)
    {
        updatedValues[i] = ((m_destination[i] - m_beginning[i]) * elapsedPercent) + m_beginning[i];
    }

    // Set the new values to the target
    m_target.setValues(m_id, updatedValues);
}

void Transition::addToElapsed(const TransitionContract::SystemDuration_t &addedTime)
{
    setElapsed(getElapsed() + addedTime);
}
