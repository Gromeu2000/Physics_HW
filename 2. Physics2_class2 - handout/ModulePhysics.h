#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2DynArray.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

class b2World;
class b2Body;

// TODO 6: Create a small class that keeps a pointer to tghe b2Body
// and has a method to request the position
// then write the implementation in the .cpp
// Then make your circle creation function to return a pointer to that class

class PhysBody
{
public:
	PhysBody(b2Body* body) :body_pointer(body) {}
	void GetPosition(int& x, int& y) const;
	void GetRotation(float& angl);
public:
	b2Body* body_pointer;
	int width, height;

};

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	// TODO 4: Move body creation to 3 functions to create circles, rectangles and chains
	PhysBody* CreateCircle(int x, int y, int radius,bool dynamic);
	PhysBody* CreateRectangle(int x, int y, int width, int height, bool dynamic);
	void CreateChain();

	p2DynArray<PhysBody*> physbody_circle;
	p2DynArray<PhysBody*> physbody_rectangle;


private:

	bool debug;
	b2World* world;
};