#include "TestScene.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/Entity.h"
#include "Engine/TransformComponent.h"
#include <chrono>
#include "Physics/CircleColliderComponent.h"

void TestScene::onStart()
{
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 50,50 });
	m_circle1->getTransform()->setLocalPosition({ 200, 400 });
	m_circle1->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle1->addComponent(new GamePhysics::CircleColliderComponent(100));
	addEntity(m_circle1);

	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 50,50 });
	m_circle2->getTransform()->setLocalPosition({ 600, 400 });
	m_circle2->addComponent<GameGraphics::ShapeComponent>()->setShapeType(GameGraphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(100));
	addEntity(m_circle2);


}

void TestScene::onUpdate(double deltaTime)
{
	GameMath::Vector2 position = m_circle1->getTransform()->getLocalPosition();
	GameMath::Vector2 deltaPostion = { 100, 0 };
	m_circle1->getTransform()->setLocalPosition(position + deltaPostion * deltaTime);
}
