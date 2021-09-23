# Classes

### PhysicsGame

Name: startup
	
	Type: bool 
	
	Description: renders the game and all game objects
	
Name: shutdown
	
	Type: void
	
	Description: unloads the game and all game objects
	
Name: update
	
	Type: void
	
	Description: updates the scene over time 
	
Name: draw
	
	Type: void 
	
	Description: renders in the game objects

### PhysicsObject

Name: ShapeType
	
	Type: enum class
	
	Description: holds all the different shape types like boxes, spheres, etc.
	
### PhysicsProject

Name: main
	
	Type: int 
	
	Description: runs the game
	
### PhysicsScene

Name: PhysicsScene()
	
	Type: public
	
	Description: constructor for the physics scene
	
Name: ~PhysicsScene()
	
	Type: public
	
	Description: deconstructs the physics scene

Name: AddActor
	
	Type: void
	
	Description: adds a actor to the scene

Name: removeActor
	
	Type: void
	
	Description: deletes a actor
	
Name: update
	
	Type: void 
	
	Description: updates the actors overtime
	
Name: draw
	
	Type: void 
	
	Description: renders the actors and scene
	
Name: setTimeStep
	
	Type: void
	
	Description: sets the time step in the scene
	
Name: getTimeStep
	
	Type: float
	
	Description: gets a reference to the timestep
	
Name: planeToPlane
	
	Type: bool
	
	Description: determines the interaction between two planes
	
Name: planeToSphere
	
	Type: bool
	
	Description: determines the interaction between a plane and a sphere
	
Name: planeToBox
	
	Type: bool
	
	Description: determines the intersction between a plane and a box
	
Name: sphereToPlane
	
	Type: bool
	
	Description: determines the interaction between a plane and a sphere
	
Name: sphereToSphere
	
	Type: bool
	
	Description: determines the interaction between two spheres
	
Name: sphereToBox
	
	Type: bool
	
	Description: determines the intersction between a sphere and a box
	
Name: boxToPlane
	
	Type: bool
	
	Description: determines the interaction between a plane and a box
	
Name: boxToSphere
	
	Type: bool
	
	Description: determines the interaction between a sphere and a box
	
Name: boxToBox
	
	Type: bool
	
	Description: determines the intersction between two boxes
	
Name: m_gravity
	
	Type: glm::vec2
	
	Description: value for gravity
	
Name: m_timestep
	
	Type: float
	
	Description: value for timestep
	
Name: m_actors
	
	Type: std::set<PhysicsObject*>
	
	Description: reference of the actors
	
### Plane

Name: Plane()
	
	Type: public  
	
	Description: constructor for plane
	
Name: ~Plane()
	
	Type: public
	
	Description: deconstructor for plane
	
Name: fixedUpdate
	
	Type: void
	
	Description: updates the plane overtime
	
Name: draw
	
	Type: void 
	
	Description: renders the plane in the scene
	
Name: resolveCollision
	
	Type: void
	
	Description: how the plane will handle a collision
	
### RigidBody

Name: RigidBody()
	
	Type: public
	
	Description: constructs the Rigid Body
	
Name: ~RigidBody()
	
	Type: public
	
	Description: deconstructs the Rigid Body
	
Name: fixedUpdate
	
	Type: void
	
	Description: updates the Rigid Body over time
	
Name: applyForce
	
	Type: void
	
	Description: applies a force to itself on collision
	
Name: applyForceToOther
	
	Type: void
	
	Description: applies a force to the object that it collides with
	
Name: resolveCollision
	
	Type: void
	
	Description: how the object will react on collision
	
### Sphere

Name: Sphere()
	
	Type: public
	
	Description: constructs the sphere
	
Name: ~Sphere()
	
	Type: public
	
	Description: deconstructs the sphere
	
Name: draw
	
	Type: void 
	
	Description: renders the sphere in the scene
