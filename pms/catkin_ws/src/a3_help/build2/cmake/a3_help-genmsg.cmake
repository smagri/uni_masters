# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(FATAL_ERROR "Could not find messages which '/lu1/smagri/uni/subj/proj30cp/catkin_ws/src/a3_help/srv/RequestGoal.srv' depends on. Did you forget to specify generate_messages(DEPENDENCIES ...)?
Cannot locate message [int]: unknown package [a3_help] on search path [{'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg']}]")
message(STATUS "a3_help: 0 messages, 1 services")

set(MSG_I_FLAGS "-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(a3_help_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(a3_help
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a3_help
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(a3_help_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(a3_help_generate_messages a3_help_generate_messages_cpp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(a3_help_gencpp)
add_dependencies(a3_help_gencpp a3_help_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a3_help_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(a3_help
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a3_help
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(a3_help_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(a3_help_generate_messages a3_help_generate_messages_lisp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(a3_help_genlisp)
add_dependencies(a3_help_genlisp a3_help_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a3_help_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(a3_help
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a3_help
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(a3_help_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(a3_help_generate_messages a3_help_generate_messages_py)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(a3_help_genpy)
add_dependencies(a3_help_genpy a3_help_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a3_help_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a3_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a3_help
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(a3_help_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a3_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a3_help
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(a3_help_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a3_help)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a3_help\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a3_help
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(a3_help_generate_messages_py sensor_msgs_generate_messages_py)
