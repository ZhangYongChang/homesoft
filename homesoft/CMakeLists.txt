# Add header files in header files group
file(GLOB INCLUDE_FILES "*.h")
file(GLOB SOURCE_FILES "*.cpp")
file(GLOB GUI_FILES "*.ui")
file(GLOB RESOURCE_FILES "*.qrc")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})
source_group("Gui Files" FILES ${GUI_FILES})
source_group("Resource Files" FILES ${RESOURCE_FILES})

FIND_PACKAGE(Qt4 COMPONENTS QtCore QtGui REQUIRED)
INCLUDE(${QT_USE_FILE})

if(MSVC) # Check if we are using the Visual Studio compiler
    install(FILES  ${QT_LIBRARY_DIR}/QtCore4.dll DESTINATION bin)
	install(FILES  ${QT_LIBRARY_DIR}/QtGui4.dll DESTINATION bin)
	install(FILES  ${QT_LIBRARY_DIR}/QtSql4.dll DESTINATION bin)
	install(FILES  ${QT_PLUGINS_DIR}/sqldrivers/qsqlodbc4.dll DESTINATION bin/sqldrivers)
else()
	install(FILES  ${QT_LIBRARY_DIR}/QtCore4.so DESTINATION lib)
	install(FILES  ${QT_LIBRARY_DIR}/QtGui4.so DESTINATION lib)
	install(FILES  ${QT_LIBRARY_DIR}/QtSql4.so DESTINATION lib)
	install(FILES  ${QT_PLUGINS_DIR}/sqldrivers/qsqlodbc4.dll DESTINATION bin/sqldrivers)
endif()

set(qt_UI ${GUI_FILES})
set(QOBJ_HDRS 
	mainwindow.h 
	addbuyorderdialog.h 
	additemdialog.h
	adduserdialog.h
	querybydatedialog.h
	querybynameanddatedialog.h
	countermonthdialog.h
	counterbymonthanduserdialog.h)

qt4_wrap_ui(QTUICs ${qt_UI})
qt4_wrap_cpp(MOCSrcs ${QOBJ_HDRS})
qt4_add_resources(QTRESOURCEs ${RESOURCE_FILES})


# Executable file generate command.
add_executable(homesoft ${SOURCE_FILES} ${INCLUDE_FILES} ${QTUICs} ${MOCSrcs} ${QTRESOURCEs})

include_directories (${QT_INCLUDES} ${PROJECT_BINARY_DIR}/Gui)

target_link_libraries(homesoft ${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES})

install(TARGETS homesoft DESTINATION bin)

IF(WIN32) # Check if we are on Windows
  if(MSVC) # Check if we are using the Visual Studio compiler
    set_target_properties(homesoft PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
  elseif(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
  else()
    message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
  endif()
elseif(UNIX)
  # Nothing special required
else()
  message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF()