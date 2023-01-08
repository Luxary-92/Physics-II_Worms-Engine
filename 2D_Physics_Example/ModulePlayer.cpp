#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "PhysBody.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	switch (tipo_movimiento) {

	case 1: //canviando la posicion del player
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
			App->physics->players.data()->x += 0.3;
		}
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
			App->physics->players.data()->x -= 0.3;
		}
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
			App->physics->players.data()->y += 3;
		}
		break;
	case 2: //Bloque de instrucciones 2;
		break;
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
			App->physics->players.data()->fx += 100;
		}
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
			App->physics->players.data()->fx += 100;
		}
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
			App->physics->players.data()->fy += 3;
		}
		break;
	}

	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_REPEAT) {
		if (tipo_movimiento == 1 ) {
			tipo_movimiento = 2;
		}
		if (tipo_movimiento == 2) {
			tipo_movimiento = 1;

		}
	}

	return UPDATE_CONTINUE;
}



