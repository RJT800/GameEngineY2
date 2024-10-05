#include "TestScene.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/Entity.h"
#include "Engine/TransformComponent.h"
#include <chrono>
#include "Physics/RigidBodyComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"


//GamePhysics::AABBColliderComponent;



void TestScene::onStart()
{
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 50,50 });
	m_circle1->getTransform()->setLocalPosition({ 200, 500 });
	m_circle1->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle1->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle1->addComponent(new GamePhysics::RigidBodyComponent());
	m_circle1->getComponent<GamePhysics::RigidBodyComponent>()->setMass(50);
	addEntity(m_circle1);

	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 50,50 });
	m_circle2->getTransform()->setLocalPosition({ 200, 700 });
	m_circle2->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle2->addComponent(new GamePhysics::RigidBodyComponent());
	m_circle2->getComponent<GamePhysics::RigidBodyComponent>()->setMass(50);

	m_circle2->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);

	addEntity(m_circle2);

	m_square1 = new GameEngine::Entity();
	m_square1->getTransform()->setLocalScale({ 50,50 });
	m_square1->getTransform()->setLocalPosition({ 500,500 });
	m_square1->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square1->addComponent(new GamePhysics::AABBColliderComponent(50,50));
	
	//addEntity(m_square1);


}

void TestScene::onUpdate(double deltaTime)
{
	//GameMath::Vector2 position = m_circle1->getTransform()->getLocalPosition();
	//GameMath::Vector2 deltaPostion = { 100, 0 };
	//m_circle1->getTransform()->setLocalPosition(position + deltaPostion * deltaTime);
	//m_circle2->getTransform()->setLocalPosition(position + deltaPostion * -deltaTime);
	
}
