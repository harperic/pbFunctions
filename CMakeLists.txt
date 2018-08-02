cmake_minimum_required(VERSION 2.8.12)
project(pbFunctions)

find_package(pybind11)
pybind11_add_module(pbFunctions src/test.cpp src/DynamicFib.cpp src/fib.cpp src/MatrixFib.cpp src/sqrtTrick.cpp)

# get_filename_component(_python_lib_file ${PYTHON_LIBRARY} NAME)
# add_custom_command(TARGET example POST_BUILD
                          # COMMAND install_name_tool ARGS -change ${_python_lib_file} ${PYTHON_LIBRARY} $<TARGET_FILE:example>)


install(TARGETS pbFunctions LIBRARY DESTINATION pbFunctions)
