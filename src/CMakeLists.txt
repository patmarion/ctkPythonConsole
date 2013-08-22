

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(PythonLibs REQUIRED)
find_package(PythonQt REQUIRED)


include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${PYTHONQT_INCLUDE_DIR})


set(srcs
  ctkConsole.cpp
  ctkPythonConsole.cpp
  ctkAbstractPythonManager.cpp
)

qt4_wrap_cpp(moc_srcs
  ctkConsole.h
  ctkConsole_p.h
  ctkPythonConsole.h
  ctkAbstractPythonManager.h
  )

add_library(ctkPythonConsole ${srcs} ${moc_srcs})
target_link_libraries(ctkPythonConsole ${QT_LIBRARIES} ${PYTHON_LIBRARIES} ${PYTHONQT_LIBRARIES})
set_target_properties(ctkPythonConsole PROPERTIES SOVERSION 1.0 VERSION 1.0)
set_target_properties(ctkPythonConsole  PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")

add_executable(console main.cpp)
target_link_libraries(console ctkPythonConsole)

install(FILES
  ctkAbstractPythonManager.h
  ctkConsole.h
  ctkPythonConsole.h
  ctkPythonConsoleExport.h
  DESTINATION include/ctkPythonConsole)

install(TARGETS
  ctkPythonConsole
  DESTINATION lib)
