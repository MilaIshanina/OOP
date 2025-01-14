#include "Melee.h"
#include "Game/Game.h"


/* MELEE MELEE MELEE MELEE MELEE MELEE MELEE MELEE MELEE MELEE */

Melee::Melee(Point point, Base* base) : Unit(point, base) {}

uint8_t Melee::getUnitClass() {
    return UNIT_MELEE;
}

double Melee::classAttackModifier(Object* enemy) {
    if (enemy->getGroupType() == BASE)
        return 0.4;

    if (enemy->getGroupType() == UNIT) {
        auto unit = static_cast<IUnit*>(enemy);
        if (unit->getUnitClass() == UNIT_MELEE) {
            return 1;
        }

        if (unit->getUnitClass() == UNIT_RANGED) {
            return 1.2;
        }

        if (unit->getUnitClass() == UNIT_SIEGE_ENGINE) {
            return 1.6;
        }
    }
    return 0;
}


/* SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN SWORDSMAN */

Swordsman::Swordsman(Point point, Base* base) : Melee(point, base) {
    strength = Strength(50, 0);
    armor = Armor(20);
    health = Health(100, 100);
    movePoints = MovePoints(2, 2);
}

uint8_t Swordsman::getObjectType() {
    return UNIT_SWORDSMAN;
}

double Swordsman::typeAttackModifier(Object* enemy) {
    if (enemy->getGroupType() == BASE)
        return 1;

    if (enemy->getGroupType() == UNIT) {
        uint8_t enemyType = enemy->getObjectType();
        if (enemyType == UNIT_PIKEMAN || enemyType == UNIT_ARCHER || enemyType == UNIT_CROSSBOWMAN)
            return 1.2;
        return 1;
    }
    return 0;
}



/* PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN PIKEMAN */

Pikeman::Pikeman(Point point, Base* base) : Melee(point, base) {
    strength = Strength(40, 0);
    armor = Armor(16);
    health = Health(100, 100);
    movePoints = MovePoints(2, 2);
}

uint8_t Pikeman::getObjectType() {
    return UNIT_PIKEMAN;
}

double Pikeman::typeAttackModifier(Object* enemy) {
    if (enemy->getGroupType() == BASE)
        return 1;

    if (enemy->getGroupType() == UNIT) {
        uint8_t enemyType = enemy->getObjectType();
        if (enemyType == UNIT_SHOCK_CAVALRY || enemyType == UNIT_SCOUT_CAVALRY)
            return 1.2;
        return 1;
    }
    return 0;
}



/* SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY SHOCK_CAVALRY */

ShockCavalry::ShockCavalry(Point point, Base* base) : Melee(point, base) {
    strength = Strength(45, 0);
    armor = Armor(16);
    health = Health(100, 100);
    movePoints = MovePoints(4, 4);
}

uint8_t ShockCavalry::getObjectType() {
    return UNIT_SHOCK_CAVALRY;
}

double ShockCavalry::typeAttackModifier(Object* enemy) {
    if (enemy->getGroupType() == BASE)
        return 1;

    if (enemy->getGroupType() == UNIT) {
        uint8_t enemyType = enemy->getObjectType();
        if (enemyType == UNIT_SWORDSMAN || enemyType == UNIT_CROSSBOWMAN)
            return 1.2;
        return 1;
    }
    return 0;
}
