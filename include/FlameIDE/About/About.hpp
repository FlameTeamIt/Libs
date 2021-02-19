#ifndef FLAMEIDE_ABOUT_ABOUT_HPP
#define FLAMEIDE_ABOUT_ABOUT_HPP

#ifndef FLAMEIDE_VERSION
#	ifndef FLAMEIDE_VERSION_MAJOR
#		define FLAMEIDE_VERSION_MAJOR 0
#	endif
#	ifndef FLAMEIDE_VERSION_MINOR
#		define FLAMEIDE_VERSION_MINOR 0
#	endif
#	ifndef FLAMEIDE_VERSION_PATCH
#		define FLAMEIDE_VERSION_PATCH 1
#	endif
#	ifndef FLAMEIDE_VERSION_BUILD_NUMBER
#		define FLAMEIDE_VERSION_BUILD_NUMBER 1
#	endif
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
	About() = default;

	const unsigned int major = FLAMEIDE_VERSION_MAJOR;
	const unsigned int minor = FLAMEIDE_VERSION_MINOR;
	const unsigned int patch = FLAMEIDE_VERSION_PATCH;
	const unsigned long build  = FLAMEIDE_VERSION_BUILD_NUMBER;

#ifdef __GNUG__
	const char* date = __DATE__;
	const char* time = __TIME__;
#endif
};

}

#endif // FLAMEIDE_ABOUT_ABOUT_HPP

