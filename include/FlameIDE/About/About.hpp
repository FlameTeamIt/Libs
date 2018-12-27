#ifndef ABOUT_H
#define ABOUT_H

#ifndef BUILD_NUMBER
#define BUILD_NUMBER 1000
#endif

#ifndef __DATE__
#define __DATE__ "JAN 30 1994"
#endif

#ifndef __TIME__
#define __TIME__ "17:00:00"
#endif

namespace flame_ide
{

struct About
{
	About();
	
	const unsigned long buid_number;
	const unsigned int major_version;
	const unsigned int minor_version;
	const unsigned int patch_version;
	
#ifdef __GNUG__
	const char* date = __DATE__;
	const char* time = __TIME__;
#endif
};

About::About()
	: buid_number(BUILD_NUMBER)
	,major_version(0)
	,minor_version(0)
	,patch_version(1)
{}

}


#endif // ABOUT_H

