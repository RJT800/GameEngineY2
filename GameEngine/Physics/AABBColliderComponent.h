#pragma once

#include "ColliderComponent.h"

namespace GamePhysics
{
	class AABBColliderComponent : public ColliderComponent
	{
	public:
		AABBColliderComponent(float width, float height) : ColliderComponent() {}
	};
}