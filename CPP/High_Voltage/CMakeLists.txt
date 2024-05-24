# CMakeList.txt : CMake project for High_Voltage, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("High_Voltage")

# Add source to this project's executable.
add_executable (High_Voltage "High_Voltage.h" "High_Voltage.cpp" "GlobalVariables.h" "GlobalVariables.cpp" "cPlayer.h" "cPlayer.cpp" "cInterceptor.h" "cInterceptor.cpp" "mBuildMaze.h" "mBuildMaze.cpp" "mController.h" "mController.cpp" "mFunctions.h" "mFunctions.cpp" "mMoveCharacters.h" "mMoveCharacters.cpp" "mRunGame.h" "mRunGame.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET High_Voltage PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
