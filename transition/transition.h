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

private:
    SystemDuration_t m_elapsed;
};

#endif // TRANSITION_H
