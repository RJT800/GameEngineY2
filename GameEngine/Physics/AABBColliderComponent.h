#pragma once

#include "ColliderComponent.h"

namespace GamePhysics
{
	class AABBColliderComponent : public ColliderComponent
	{
	public:
		AABBColliderComponent(float width, float height);

		GamePhysics::Collision* checkCollisionAABB(AABBColliderComponent* other) override;
		GamePhysics::Collision* checkCollisionCircle(CircleColliderComponent* other) override;

		void draw() override;

		float getWidth() { return m_width; }
		float getHeight() { return m_height; }


	private:
		float m_width;
		float m_height;


	};
}