#ifndef __MODULETIMER_H__
#define __MODULETIMER_H__

#include "Defs.h"

class Timer
{
public:

	// Constructor
	Timer();

	void Start();
	uint32 Read() const;
	float ReadSec() const;

private:
	uint32 startTime;
};

#endif //__MODULETIMER_H__
