/*
 * Particle.h
 *
 *  Created on: Apr 25, 2017
 *      Author: jacksoft
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <math.h>

namespace jacksoft {

struct Particle {
	double m_x;
	double m_y;
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);

};

} /* namespace jacksoft */

#endif /* PARTICLE_H_ */
