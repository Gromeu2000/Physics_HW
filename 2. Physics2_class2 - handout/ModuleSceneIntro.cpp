#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

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
	// TODO 5: Move all creation of bodies on 1,2,3 key press here in the scene
	
	// On space bar press, create a circle on mouse position
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->physics->physbody_circle.PushBack(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 25, 1));
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		// TODO 1: When pressing 2, create a box on the mouse position
		App->physics->physbody_rectangle.PushBack(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 50, 50, true));
		// TODO 2: To have the box behave normally, set fixture's density to 1.0f
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// TODO 3: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!
		App->physics->CreateChain();
	}

	// TODO 7: Draw all the circles using "circle" texture
	
	for (int i = 0; i < App->physics->physbody_circle.Count(); i++)
	{
		int x, y;
		float ang;
		App->physics->physbody_circle[i]->GetPosition(x, y);
		App->physics->physbody_circle[i]->GetRotation(ang);
		App->renderer->Blit(circle, x - 25, y - 25, NULL, NULL, ang);
	}

	return UPDATE_CONTINUE;
}
