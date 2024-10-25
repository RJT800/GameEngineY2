#include "AABBColliderComponent.h"
#include "CircleColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::AABBColliderComponent::AABBColliderComponent(float width, float height) : ColliderComponent()
{
    m_width = width;
    m_height = height;
}


GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{

    //redo the math

    //get the combined sum of the halves of the heights
    float halfHeightSum = (m_height + other->m_height)/2;


    //get the combined y's of the squares
    float firstY = getOwner()->getTransform()->getGlobalPosition().y;
    float secondY = other->getOwner()->getTransform()->getGlobalPosition().y;

    
    float yDifference = firstY - secondY;
    
    if (yDifference < 0)
        yDifference *= -1;

    //same for width

    float halfWidthSum = (m_width + other->m_width) / 2;

    float firstX = getOwner()->getTransform()->getGlobalPosition().x;
    float secondX = other->getOwner()->getTransform()->getGlobalPosition().x;

    float xdifference = firstX - secondX;

    if (xdifference < 0)
        xdifference *= -1;
    
    //establish penetration distance
    float penDis = 0;
    bool isHeightSmaller;
    if (xdifference < halfWidthSum && yDifference < halfHeightSum)
    {
        if ((halfHeightSum - yDifference) < (halfWidthSum - xdifference))
        {
            penDis = halfHeightSum - yDifference;
            isHeightSmaller = true;
        }
        else
        {
            penDis = halfWidthSum - xdifference;
            isHeightSmaller = false;
        }
    }
    else
    {
        return nullptr;
    }

    //find contact point
    GameMath::Vector2 d;

    if (isHeightSmaller)
    {
        d.x = firstX;
        d.y = secondY - other->m_height;
    }
    else
    {
        d.x = secondX - other->m_width;
        d.y = firstY;
    }


    // find normal
    GameMath::Vector2 n;

    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;


    //send back collision data
    GamePhysics::Collision* collisionData = new Collision();
    collisionData->normal = direction.getNormalized();
    collisionData->collider = other;
    collisionData->contactPoint = d.getNormalized();
    collisionData->penetrationDistance = penDis;
    
    
    return collisionData;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    //establish circle parts
    GameMath::Vector2 circleCenter = other->getOwner()->getTransform()->getGlobalPosition();
    float circleRadius = other->getRadius();
    
    float circleX = other->getOwner()->getTransform()->getGlobalPosition().x;
    float circleY = other->getOwner()->getTransform()->getGlobalPosition().y;

    //establish aabb borders
    GameMath::Vector2 aabbCenter = getOwner()->getTransform()->getGlobalPosition();

    GameMath::Vector2 direction = circleCenter - aabbCenter;

    float firstY = getOwner()->getTransform()->getGlobalPosition().y;

    float firstX = getOwner()->getTransform()->getGlobalPosition().x;

    float halfHeight = (firstY + circleY) / 2;
    float halfWidth = (firstX + circleX) / 2;

    float yDifference = firstY - circleY;

    if (yDifference < 0)
        yDifference *= -1;

    float xDifference = firstX - circleX;

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

void GamePhysics::AABBColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
     
    RAYLIB_H::DrawRectangleLines(position.x- m_width/2, position.y - m_height /2, m_width, m_height, GetColor(getColor()));

}
 