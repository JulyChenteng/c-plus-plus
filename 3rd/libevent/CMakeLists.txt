# CMakeList.txt: demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 2.8)

project ("demo")

# 将源代码添加到此项目的可执行文件。
# add_executable (demo "demo.cpp" "demo.h")

# TODO: 如有需要，请添加测试并安装目标。
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	# 添加头文件目录
	include_directories(../../include)
	# 添加需要链接的库文件目录
	link_directories(../../lib)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	link_directories(/usr/local/lib /usr/local/lib64)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")



# 添加 math 子目录
# add_subdirectory(asio)

# 指定生成目标 
# add_executable(${PROJECT_NAME}.out asio/timer01.cpp)

# 指定可执行文件和lib文件目录
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# If necessary, use the RELATIVE flag, otherwise each source file may be listed 
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
# file( GLOB APP_SOURCES RELATIVE app/*.cxx )
# get_filename_component(<var> <FileName> <mode> [CACHE])

file( GLOB APP_SOURCES RELATIVE_PATH *.cpp test_server/*.cpp)
foreach( testsourcefile ${APP_SOURCES} )
	# I used a simple string replace, to cut off .cpp.
	# string( REPLACE ".cpp" "" testname ${testsourcefile} )
	get_filename_component(testname ${testsourcefile} NAME_WE)
	add_executable( ${testname} ${testsourcefile} )
	# Make sure YourLib is linked to each app
	# 添加链接库
	IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
		target_link_libraries(${testname} libevent ws2_32)
	ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
		target_link_libraries(${testname} event)
	ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	# target_link_libraries(${testname}.exe boost_chrono)
endforeach( testsourcefile ${APP_SOURCES} )
