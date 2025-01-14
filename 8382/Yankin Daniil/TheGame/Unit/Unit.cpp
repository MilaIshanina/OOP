#include "Unit.h"
#include "Game/Game.h"
#include "Field/Field.h"
#include "Player/Player.h"
#include "Base/Base.h"
#include <math.h>


Unit::Unit(Point point, Base* base) : point(point), base(base) {
    base->addUnit(this);
    isGroup = false;
}

Unit::~Unit() {
    if (!isGroup) {
        base->removeUnit(this);
        Game::getInstance().objectWasDestructed(static_cast <Object*> (this));
    }
}



Point Unit::getPoint() {
    return point;
}

void Unit::setPoint(Point point) {
    this->point = point;
}

Player* Unit::getPlayer() {
    return base->getPlayer();
}

Base* Unit::getBase() {
    return base;
}



uint16_t Unit::getMaxHealth() {
    return health.getMaxHealth();
}

uint16_t Unit::getHealth() {
    return health.getHealth();
}

uint16_t Unit::getAttack() {
    return strength.getStrength();
}

uint8_t Unit::getAttackRadius() {
    return strength.getRadius();
}

uint16_t Unit::getArmor() {
    return armor.getArmor();
}

uint8_t Unit::getMaxMovePoints() {
    return movePoints.getMaxMovePoints();
}

uint8_t Unit::getMovePoints() {
    return movePoints.getMovePoints();
}

void Unit::setMovePoints(uint8_t points) {
    movePoints.setMovePoints(points);
}



uint16_t Unit::giveDamage(IUnit* enemy) {
    return strength.getStrength() * classAttackModifier(enemy) * typeAttackModifier(enemy);
}

uint16_t Unit::giveDamage(Base* enemy) {
    return strength.getStrength() * classAttackModifier(enemy) * typeAttackModifier(enemy);
}

bool Unit::takeDamage(uint16_t damage) {
    damage = std::max(2, static_cast<int>(damage - armor.getArmor() * 0.2));

    health.setHealth(std::max(health.getHealth() - damage, 0));
    if (health.getHealth() == 0) {
        if (!isGroup) {
            delete this;
        }
        return false;
    }
    return true;

    // Выжил - true, помер - false
    // Если единичный, то при помирании самоуничтожается
    // Если в составе группы, то за уничтожение отвечает группа
}



void Unit::smallHeal(uint16_t healSize) {
    health.setHealth(std::min(static_cast <uint16_t> (health.getHealth() + healSize), health.getMaxHealth()));
}

void Unit::fullHeal() {
    health.setHealth(health.getMaxHealth());
}

void Unit::attackModification(int16_t modSize) {
    if (modSize < 0) {
        strength.setStrength(std::max(strength.getStrength() + modSize, 0));
        return;
    }
    strength.setStrength(strength.getStrength() + modSize);
}

void Unit::armorModification(int16_t modSize) {
    if (modSize < 0) {
        armor.setArmor(std::max(armor.getArmor() + modSize, 0));
        return;
    }
    armor.setArmor(armor.getArmor() + modSize);
}

void Unit::renewMovePoints() {
    movePoints.setMovePoints(movePoints.getMaxMovePoints());
}
