#ifndef REVISION_VEHICULAR_H
#define REVISION_VEHICULAR_H

typedef struct {
	bool gases;
	bool suspension;
	bool frenos;
	bool luces;
}Revision;


void revision_vehicular(Revision *r);

#endif
