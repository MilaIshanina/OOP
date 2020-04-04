#pragma once

#include "Landscape/Landscape.h"


class Forest : public Landscape
{
public:
    Forest(Point point);
    bool movementAccess() override;
    uint8_t getObjectType() override;
};
