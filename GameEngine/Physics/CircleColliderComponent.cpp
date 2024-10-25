#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance > other->m_radius + m_radius)
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();
    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = position + direction.getNormalized() * getRadius();
    collisionData->penetrationDistance = (other->m_radius + m_radius) - distance;

    return collisionData;

}

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    //establish circle parts
    GameMath::Vector2 circleCenter = getOwner()->getTransform()->getGlobalPosition();
    float circleX = getOwner()->getTransform()->getGlobalPosition().x;
    float circleY = getOwner()->getTransform()->getGlobalPosition().y;

    float circleRadius = m_radius;

    //establish aabb borders
    GameMath::Vector2 aabbCenter = other->getOwner()->getTransform()->getGlobalPosition();

    GameMath::Vector2 direction = circleCenter - aabbCenter;

    float AABBY = other->getOwner()->getTransform()->getGlobalPosition().y;

    float AABBX = other->getOwner()->getTransform()->getGlobalPosition().x;

    float halfHeight = (AABBY + circleY) / 2;
    float halfWidth = (AABBX + circleX) / 2;

    float yDifference = AABBY - circleY;

    if (yDifference < 0)
        yDifference *= -1;

    float xDifference = AABBX - circleX;

    if (xDifference < 0)
        xDifference *= -1;

    float penDis = 0;
    bool isHeightSmaller;
    if (xDifference < halfWidth && yDifference < halfHeight)
    {
        if ((halfHeight - yDifference) < (halfWidth - xDifference))
        {
            penDis = halfHeight - yDifference;
            isHeightSmaller = true;
        }
        else
        {
            penDis = halfWidth - xDifference;
            isHeightSmaller = false;
        }
    }
    else
    {
        return nullptr;
    }

    GamePhysics::Collision* collisionData = new Collision();
    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = circleCenter + direction.getNormalized() * circleRadius;
    collisionData->penetrationDistance = penDis;


    return collisionData;
}

void GamePhysics::CircleColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();

    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius()/2, GetColor(getColor()));
}
