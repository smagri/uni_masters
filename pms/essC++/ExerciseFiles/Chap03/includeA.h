// includeA.h by Bill Weinman <http://bw.org/>

// this is called an include gard
//
#ifndef _INCLUDEA_H
#define _INCLUDEA_H
//
// can replace this by
// #pragma once
// and that works too, most modern compilers support it but it's not standard

#include "includeB.h"

struct structA {
	int member;
};

#endif // _INCLUDEA_H

