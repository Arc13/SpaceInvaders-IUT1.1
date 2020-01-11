#include "transition_contract.h"

#define TRANSITIONCONTRACT nsTransition::TransitionContract

TRANSITIONCONTRACT::TransitionContract(ITransitionable& target, const int &id,
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
} // TransitionContract()

const int& TRANSITIONCONTRACT::getId() const
{
    return m_id;
} // what()

const TRANSITIONCONTRACT::TransitionMode& TRANSITIONCONTRACT::getTransitionMode() const
{
    return m_transitionMode;
} // getTransitionMode()

const std::vector<float>& TRANSITIONCONTRACT::getBeginning() const
{
    return m_beginning;
} // getBeginning()

const std::vector<float>& TRANSITIONCONTRACT::getDestination() const
{
    return m_destination;
} // getDestination()

const TRANSITIONCONTRACT::SystemDuration_t &TRANSITIONCONTRACT::getDuration() const
{
    return m_duration;
} // getDuration()

void TRANSITIONCONTRACT::setFinishCallback(const std::function<void ()> &callback)
{
    m_finishCallback = callback;
} // setFinishCallback()

const nsTransition::ITransitionable& TRANSITIONCONTRACT::getTarget() const
{
    return m_target;
} // where()

#undef TRANSITIONCONTRACT
