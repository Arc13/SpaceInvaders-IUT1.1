#include "transition_contract.h"

TransitionContract::TransitionContract(ITransitionable& target, const int &id,
                                       const std::chrono::seconds &duration, const std::vector<float> &destination,
                                       const TransitionMode &transitionMode)
    : m_id(id)
    , m_target(target)
    , m_transitionMode(transitionMode)
    , m_destination(destination)
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

const TransitionContract::TransitionMode& TransitionContract::getTransitionMode() const
{
    return m_transitionMode;
}

void TransitionContract::setFinishCallback(const std::function<void ()> &callback)
{
    m_finishCallback = callback;
}

const ITransitionable& TransitionContract::where() const
{
    return m_target;
}
