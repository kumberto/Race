#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(magicNumbers::StripOfRoadway strip, magicNumbers::DirectionMovement direction)
: strip_(strip)
, direction_(direction)
{
}

void Enemy::move()
{
	switch (direction_)
	{
		case 2:

			break;
		case 3:
			break;
		case 0:
			break;
		case 1:
			break;
		default:
			break;
	}

}

void Enemy::drawEnemy()
{
}
