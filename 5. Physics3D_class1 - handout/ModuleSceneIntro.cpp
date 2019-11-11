#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center

	vec3 move = { App->camera->Position.x + 1, App->camera->Position.y + 2, App->camera->Position.z };
	App->camera->Move({move});
	App->camera->LookAt({ 0,0,0 });

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	Plane plane;
	plane.SetPos(0, 0, 0);
	plane.color = { 255,0,255 };
	plane.axis = true;
	plane.Render();

	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere sphere;
	sphere.SetPos(0, 0, 0);
	sphere.color = { 248, 0, 0 };
	sphere.radius = 0.5;
	sphere.Render();

	Cube cube;
	cube.SetPos(2, 0, 0);
	cube.color = { 0,0,255 };
	cube.size = { 2, 2, 2 };
	cube.Render();

	Cylinder cylinder;
	cylinder.SetPos(1, 2, 0);
	cylinder.radius = 0.5;
	vec3 og = { 0,1,1 };
	cylinder.color = { 0,143,57 };
	cylinder.SetRotation(45, og);
	cylinder.height = 5;
	cylinder.Render();
	

	return UPDATE_CONTINUE;
}

