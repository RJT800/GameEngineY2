#include "TestScene.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/Entity.h"
#include "Engine/TransformComponent.h"
#include <chrono>
#include "Physics/RigidBodyComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"
#include "Physics/ColliderComponent.h"





void TestScene::onStart()
{
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 50,50 });
	m_circle1->getTransform()->setLocalPosition({ 100, 200 });
	m_circle1->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle1->addComponent(new GamePhysics::CircleColliderComponent(100));
	m_circle1->addComponent(new GamePhysics::RigidBodyComponent());
	m_circle1->getComponent<GamePhysics::RigidBodyComponent>()->setMass(500);

	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 50,50 });
	m_circle2->getTransform()->setLocalPosition({ 500, 200 });
	m_circle2->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(100));
	m_circle2->addComponent(new GamePhysics::RigidBodyComponent());
	m_circle2->getComponent<GamePhysics::RigidBodyComponent>()->setMass(50);
	m_circle2->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);


	m_square1 = new GameEngine::Entity();
	m_square1->getTransform()->setLocalScale({ 50,50 });
	m_square1->getTransform()->setLocalPosition({ 400,400 });
	m_square1->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square1->addComponent(new GamePhysics::AABBColliderComponent(50,50));
	m_square1->addComponent(new GamePhysics::RigidBodyComponent());
	m_square1->getComponent<GamePhysics::ColliderComponent>()->setColliderType(GamePhysics::ColliderComponent::AABB);

	m_square2 = new GameEngine::Entity();
	m_square2->getTransform()->setLocalScale({ 50,750 });
	m_square2->getTransform()->setLocalPosition({ 800,400 });
	m_square2->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square2->addComponent(new GamePhysics::AABBColliderComponent(100,800));
	m_square2->addComponent(new GamePhysics::RigidBodyComponent());
	m_square2->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);

	m_square2->getComponent<GamePhysics::RigidBodyComponent>()->setIsKinematic(true);
	m_square2->getComponent<GamePhysics::ColliderComponent>()->setColliderType(GamePhysics::ColliderComponent::AABB);
	
	m_square3 = new GameEngine::Entity();
	m_square3->getTransform()->setLocalScale({ 50,750 });
	m_square3->getTransform()->setLocalPosition({ 1,400 });
	m_square3->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square3->addComponent(new GamePhysics::AABBColliderComponent(100,800));
	m_square3->addComponent(new GamePhysics::RigidBodyComponent());
	m_square3->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);
	m_square3->getComponent<GamePhysics::RigidBodyComponent>()->setIsKinematic(true);
	m_square3->getComponent<GamePhysics::RigidBodyComponent>()->setMass(100);
	m_square3->getComponent<GamePhysics::ColliderComponent>()->setColliderType(GamePhysics::ColliderComponent::AABB);

	m_square4 = new GameEngine::Entity();
	m_square4->getTransform()->setLocalScale({ 750,50 });
	m_square4->getTransform()->setLocalPosition({ 400,1 });
	m_square4->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square4->addComponent(new GamePhysics::AABBColliderComponent(800,100));
	m_square4->addComponent(new GamePhysics::RigidBodyComponent());
	m_square4->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);
	m_square4->getComponent<GamePhysics::RigidBodyComponent>()->setIsKinematic(true);
	m_square4->getComponent<GamePhysics::RigidBodyComponent>()->setMass(100);
	m_square4->getComponent<GamePhysics::ColliderComponent>()->setColliderType(GamePhysics::ColliderComponent::AABB);

	m_square5 = new GameEngine::Entity();
	m_square5->getTransform()->setLocalScale({ 750,50 });
	m_square5->getTransform()->setLocalPosition({ 400,800 });
	m_square5->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::BOX);
	m_square5->addComponent(new GamePhysics::AABBColliderComponent(800, 100));
	m_square5->addComponent(new GamePhysics::RigidBodyComponent());
	m_square5->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);
	m_square5->getComponent<GamePhysics::RigidBodyComponent>()->setIsKinematic(true);
	m_square5->getComponent<GamePhysics::RigidBodyComponent>()->setMass(100);
	m_square5->getComponent<GamePhysics::ColliderComponent>()->setColliderType(GamePhysics::ColliderComponent::AABB);
	
	addEntity(m_circle1);
	addEntity(m_circle2);
	addEntity(m_square1);
	addEntity(m_square2);
	addEntity(m_square3);
	addEntity(m_square4);
	addEntity(m_square5);



}

void TestScene::onUpdate(double deltaTime)
{

	
}
