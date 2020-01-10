#include "transition_contract.h"

TransitionContract::TransitionContract(ITransitionable& target, const int &id, const std::chrono::seconds &duration, const std::vector<float> &destination)
    : m_id(id)
    , m_target(target)
    , m_destination(destination)
    , m_startTime(std::chrono::system_clock::now())
    , m_duration(duration)
{
    m_beginning.resize(destination.size());
    target.getValues(id, m_beginning);
}

const int& TransitionContract::what() const
{
    return m_id;
}

const std::vector<float>& TransitionContract::getDestination() const
{
    return m_destination;
}

const ITransitionable& TransitionContract::where() const
{
    return m_target;
}
