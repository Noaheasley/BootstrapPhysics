#include "PhysicsScene.h"
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.insert(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	m_actors.erase(actor);
}

void PhysicsScene::update(float deltaTime)
{
	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;

	//as long as there is enough accumulated time for a fixedUpdate
	while (accumulatedTime >= m_timeStep)
	{
		//... calll each actor's fixedUpdate
		for (PhysicsObject* actor : m_actors)
		{
			actor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumulatedTime -= m_timeStep;

		for (auto outer = m_actors.begin(); outer != --m_actors.end(); outer++) {
			for (auto inner = ++outer; inner != m_actors.end(); inner++) {
				
				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;
				
				//Collision check
				sphereToSPhere(dynamic_cast<Sphere*>(object1), dynamic_cast<Sphere>(object2))
			}
		}
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors)
	{
		actor->draw();
	}

	bool PhysicsScene::sphereToSPhere(Sphere* sphere1, Sphere* sphere2)
	{
		return false;
	}
}
