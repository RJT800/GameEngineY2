#include "RigidBodyComponent.h"
#include "Engine/TransformComponent.h"
#include "Engine/Entity.h"
#include "ColliderComponent.h"



void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector2 force)
{
	m_velocity = m_velocity + force / getMass();
}

void GamePhysics::RigidBodyComponent::applyForceToEntity(RigidBodyComponent* rigidBody, GameMath::Vector2 force)
{
	applyForce(force * -1);
	rigidBody->applyForce(force);
}

void GamePhysics::RigidBodyComponent::fixedUpdate(float fixedDeltaTime)
{
	GameMath::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	getOwner()->getTransform()->setLocalPosition(position + m_velocity * fixedDeltaTime);

	GameMath::Vector2 gravity = { 0, getGravity() };
	applyForce(gravity * getMass());
}

void GamePhysics::RigidBodyComponent::resolveCollision(GamePhysics::Collision* collisionData)
{
	
	GameMath::Vector2 firstVelocity = getVelocity();
	GameMath::Vector2 secondVelocity = collisionData->collider->getRigidBody()->getVelocity();
	float firstMass = 1/getMass();
	float secondMass = 1/collisionData->collider->getRigidBody()->getMass();

		float theThing =((1 * (GameMath::Vector2::dotProduct(firstVelocity - secondVelocity, collisionData->normal))
		/ (GameMath::Vector2::dotProduct(collisionData->normal, collisionData->normal)) * (firstMass + secondMass)));
		GameMath::Vector2 uhhIdk = (theThing, collisionData->normal);
			applyForce(uhhIdk);
			applyForceToEntity(collisionData->collider->getRigidBody(), uhhIdk);
	
}