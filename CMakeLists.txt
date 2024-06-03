#----------------------------------------------------------------------------
# Setup the project
#
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(EdGen)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
set(useROOT true)        # use true or false
include(FindROOT.cmake)

include_directories(${PROJECT_SOURCE_DIR} ${ROOT_INCLUDE_DIR} )
set(LINK_DIRECTORIES
	${ROOT_LIBRARY_DIR}	
	  )
	file(GLOB sources 
	  ${PROJECT_SOURCE_DIR}/release.C
	  )
	file(GLOB headers 
	  ${PROJECT_SOURCE_DIR}/release.h
	  )

link_directories( ${LINK_DIRECTORIES})


#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(Release ${sources} ${headers})
	set(LINK_LIBRARIES
  ${ROOT_LIBRARIES} -lThread -lHtml -lGed -lEG -lGeom 
)
target_link_libraries(Release ${LINK_LIBRARIES})
file(COPY release.inp DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY efficiency.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})



