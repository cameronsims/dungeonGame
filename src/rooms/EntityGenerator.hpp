#pragma once

#include "Dungeon.hpp"
#include "../entities/Entity.hpp"
#include "../entities/Enemy.hpp"

namespace dungeon {
	size_t enemyAmountInRoom(const std::vector<dungeon::Entity>& pEntities, const dungeon::Dungeon* const dungeon, size_t room);
	size_t generateEnemyAmount(const dungeon::Dungeon* const dungeon);
	void generateEnemies(const dungeon::Dungeon* const dungeon, std::vector<dungeon::Entity>& pEntities, dungeon::Entity& const player);
	void setEnemies(std::vector<dungeon::Enemy*>& enemies, const std::vector<dungeon::Entity>& const entities);
}