#include "ModulePerfTimer.h"
#include "SDL\include\SDL_timer.h"

uint64 PerfTimer::frequency = 0;

PerfTimer::PerfTimer()
{
	//...
	Start();
	frequency = SDL_GetPerformanceFrequency();
}

void PerfTimer::Start()
{
	startTime = SDL_GetPerformanceCounter();
}

double PerfTimer::ReadMs() const
{
	return 1000.0 * (double(SDL_GetPerformanceCounter() - startTime) / double(frequency));
}

uint64 PerfTimer::ReadTicks() const
{
	return SDL_GetPerformanceCounter() - startTime;
}