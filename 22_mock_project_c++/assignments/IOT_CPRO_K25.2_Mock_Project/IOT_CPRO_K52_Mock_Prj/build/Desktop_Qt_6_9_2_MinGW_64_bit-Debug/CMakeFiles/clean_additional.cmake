# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\IOT_CPRO_K52_Mock_Prj_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IOT_CPRO_K52_Mock_Prj_autogen.dir\\ParseCache.txt"
  "IOT_CPRO_K52_Mock_Prj_autogen"
  )
endif()
