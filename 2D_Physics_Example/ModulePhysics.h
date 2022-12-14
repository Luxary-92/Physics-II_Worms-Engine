#pragma once
#include "Module.h"
#include "Globals.h"
#include <vector>


#define PIXELS_PER_METER (20.0f) // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL (1.0f / PIXELS_PER_METER) // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) std::floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)


// Class: Ball object (a simple stoopid physics object)
class PhysObjeto
{
public:
	// Position
	// You could also use an array/vector
	float x;
	float y;

	// Velocity
	float vx;
	float vy;

	// Acceleration
	float ax;
	float ay;

	// Force (total) applied to the ball
	float fx;
	float fy;

	// Mass
	float mass;

	// Aerodynamics stuff
	float surface; // Effective wet surface
	float cl; // Aerodynamic Lift coefficient
	float cd; // Aerodynamic Drag coefficient
	float b; // Hydrodynamic Drag coefficient

	// Coefficients of friction & restitution (for bounces)
	float coef_friction;
	float coef_restitution;

	// Shape
	float radius;

	bool ball = false;
	bool player = false;

	// Has physics enabled?
	bool physics_enabled = true;
};




// Class: Ground
class Ground : public SDL_Rect
{
public:
	float x,y,w,h; // Geometry (x,y,w,h)
	SDL_Rect pixels(); // Convert geometry to pixels to draw w/ SDL
};

// Class: Water
class Water : public Ground
{
public:
	float density; // Density of fluid
	float vx; // Velocity x
	float vy; // Velocity y
};

// Class: Atmosphere
class Atmosphere
{
public:
	float density; // Density of air
	float windx; // Wind x
	float windy; // Wind y
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

	// Physics objects
	std::vector<PhysObjeto> players{};
	std::vector<PhysObjeto> balls{};
	Atmosphere atmosphere{};
	Ground ground{};
	Ground ground1{};
	Ground ground2{};
	Ground ground3{};
	Water water{};
	float speed1=0.1f;
	// Misc
	float dt = 1.0 / 60.0;

private:

	bool debug;

	int integrator;

	
	int textFont = -1;
	int testFont;
	int font;
	int bFont;
	int rFont;
};

// Compute modulus of a vector
float modulus(float vx, float vy);

// Compute Aerodynamic Drag force
void compute_aerodynamic_drag(float& fx, float& fy, const PhysObjeto& Objeto, const Atmosphere& atmosphere);

// Compute Hydrodynamic Drag force
void compute_hydrodynamic_drag(float& fx, float& fy, const PhysObjeto& Objeto, const Water& water);

// Compute Hydrodynamic Buoyancy force
void compute_hydrodynamic_buoyancy(float& fx, float& fy, const PhysObjeto& Objeto, const Water& water);

// Integration scheme: Velocity Verlet
void integrator_velocity_verlet(PhysObjeto& Objeto, float dt);

// Integration scheme: Backwards Euler
void integrator_backwards_euler(PhysObjeto& Objeto, float dt);

// Integration scheme: Forward Euler
void integrator_forward_euler(PhysObjeto& Objeto, float dt);

// Detect collision with ground
bool is_colliding_with_ground(const PhysObjeto& Objeto, const Ground& ground);

// Detect collision with water
bool is_colliding_with_water(const PhysObjeto& Objeto, const Water& water);

// Detect collision between circle and rectange
bool check_collision_circle_rectangle(float cx, float cy, float cr, float rx, float ry, float rw, float rh);


