Build homesoft, you must install Visual Stduio 2005 or later, cmake, NSIS package tools, QT.
change the root directory.
execute follow command:
	mkdir build && cd build
	cmake .. -G "Visual Studio 8 2005"
	msbuild homesoft.sln
	
	or
	
	mkdir build && cd build
	cmake .. -G "NMake Makefiles"
	nmake
	cpack -G "NSIS"