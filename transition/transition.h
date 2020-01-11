#ifndef TRANSITION_H
#define TRANSITION_H

#include "transition_contract.h"

class Transition : public TransitionContract
{
public:
    Transition(const TransitionContract &contract);

    const SystemDuration_t& getElapsed() const;
    void setElapsed(const SystemDuration_t &elapsed);
    void addToElapsed(const SystemDuration_t &addedTime);

    const bool& isReversed() const;

    void finish();
    const bool& isFinished() const;

private:
    SystemTimePoint_t m_startTime;
    SystemDuration_t m_elapsed;
    bool m_reverse;
    bool m_finished;

    void updateValues();
    void handleEndlife();
};

#endif // TRANSITION_H
