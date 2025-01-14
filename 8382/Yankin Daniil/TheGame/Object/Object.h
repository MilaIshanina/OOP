#pragma once

#include <Trivia/Point.h>


class Object
{
public:
    Object() = default;
    ~Object() = default;

    virtual uint8_t getGroupType() = 0;  // Получение типа группы объекта (Unit, Land, etc.)
    virtual uint8_t getObjectType() = 0;  // Получение конкретного типа объекта
    virtual Point getPoint() = 0;
};


enum Objects {
    LAND,
    LAND_WATER,
    LAND_MOUNTAIN,
    LAND_PLAIN,
    LAND_FOREST,
    LAND_HILL,
    LAND_FOREST_HILL,

    UNIT,
    UNIT_SWORDSMAN,
    UNIT_PIKEMAN,
    UNIT_SHOCK_CAVALRY,
    UNIT_ARCHER,
    UNIT_CROSSBOWMAN,
    UNIT_SCOUT_CAVALRY,
    UNIT_CATAPULT,
    UNIT_RAM,

    BASE,

    NEUT_OBJECT,

    OBJECT
};
