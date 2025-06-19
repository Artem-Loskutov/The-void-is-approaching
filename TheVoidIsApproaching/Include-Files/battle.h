#pragma once

#include "entity-class.h"

void hit(Entity& entity, int damage);
void block(Entity& entity);
void heal(Entity& entity);

void battle(Entity& player, Entity enemy);
