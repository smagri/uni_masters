// includeB.h by Bill Weinman <http://bw.org/>

// this is called an include gard, not standard but is widely supported
//
//#ifndef _INCLUDEB_H
//#define _INCLUDEB_H
//
// can replace include guard by
#pragma once
// and that works too, most modern compilers support it but it's not standard

struct structB {
	int member;
};

//#endif // _INCLUDEB_H
