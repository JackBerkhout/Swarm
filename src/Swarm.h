/*
 * Swarm.h
 *
 *  Created on: Apr 25, 2017
 *      Author: jacksoft
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace jacksoft {

class Swarm {
public:
	const static int NPARTICLES = 7000;

private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles() { return m_pParticles; };
};

} /* namespace jacksoft */

#endif /* SWARM_H_ */
