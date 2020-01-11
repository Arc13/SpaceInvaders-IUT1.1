#include "transition.h"

#include <algorithm>

Transition::Transition(const TransitionContract &contract)
    : TransitionContract(contract)
    , m_startTime(std::chrono::high_resolution_clock::now())
    , m_elapsed(0)
    , m_reverse(false)
    , m_finished(false)
{}

const TransitionContract::SystemDuration_t& Transition::getElapsed() const
{
    return m_elapsed;
}

void Transition::setElapsed(const TransitionContract::SystemDuration_t &elapsed)
{
    // Set the new elapsed time
    m_elapsed = elapsed;

    // Update the target values
    updateValues();
}

void Transition::addToElapsed(const TransitionContract::SystemDuration_t &addedTime)
{
    setElapsed(getElapsed() + addedTime);
}

const bool &Transition::isReversed() const
{
    return m_reverse;
}

void Transition::finish()
{
    m_finished = true;
}

const bool& Transition::isFinished() const
{
    return m_finished;
}

void Transition::updateValues()
{
    // Get the elapsed progress and clamp it between 0 and 1
    float elapsedProgress = m_elapsed / m_duration;
    elapsedProgress = std::max(0.f, std::min(elapsedProgress, 1.f));

    // If we are in reverse mode, reverse the progress
    float effectiveElapsedProgress = (!m_reverse) ? elapsedProgress : 1 - elapsedProgress;

    // Compute the new values
    std::vector<float> updatedValues(m_beginning.size());
    for (size_t i = 0; i < m_beginning.size(); ++i)
    {
        updatedValues[i] = ((m_destination[i] - m_beginning[i]) * effectiveElapsedProgress) + m_beginning[i];
    }

    // Set the new values to the target
    m_target.setValues(m_id, updatedValues);

    // Transition has finished, call the endlife handler
    if (elapsedProgress == 1.f)
    {
        handleEndlife();
    }
}

void Transition::handleEndlife()
{
    switch (m_transitionMode)
    {
        case TransitionContract::TransitionMode::MODE_FINITE:
            // In finite mode, the transition is terminated when it's done
            finish();

            break;
        case TransitionContract::TransitionMode::MODE_LOOP:
            // In loop mode, the target is set to its beginning values before going again
            m_target.setValues(m_id, m_beginning);

            m_startTime = std::chrono::high_resolution_clock::now();
            m_elapsed = SystemDuration_t::zero();

            break;
        case TransitionContract::TransitionMode::MODE_LOOP_SMOOTH:
            // In loop smooth mode, we invert the reverse boolean before going again
            m_reverse = !m_reverse;

            m_startTime = std::chrono::high_resolution_clock::now();
            m_elapsed = SystemDuration_t::zero();

            break;
    }

    // Call the finish callback if set
    if (m_finishCallback)
    {
        m_finishCallback();
    }
}
