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
	if (!getIsKinematic())
	applyForce(force * -1);

	if (!(rigidBody->getIsKinematic()))
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
	
	//Get everything for the formula
	GameMath::Vector2 firstVelocity = getVelocity();
	GameMath::Vector2 secondVelocity = collisionData->collider->getRigidBody()->getVelocity();
	float firstMass = getMass();
	float secondMass = collisionData->collider->getRigidBody()->getMass();

	//Does the formula
		float formulaResult =((.1 * (GameMath::Vector2::dotProduct(firstVelocity - secondVelocity, collisionData->normal))
		/ (GameMath::Vector2::dotProduct(collisionData->normal, collisionData->normal)) * (firstMass + secondMass)));

		GameMath::Vector2 finalForce = collisionData->normal * formulaResult;

		//Applies forces to Entities
		applyForceToEntity(collisionData->collider->getRigidBody(), finalForce);
	
}