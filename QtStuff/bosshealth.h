#ifndef BOSSHEALTH_H
#define BOSSHEALTH_H

#include "health.h"

class bossHealth : public Health
{
public:
    bossHealth();
    void decrease();
};

#endif // BOSSHEALTH_H
