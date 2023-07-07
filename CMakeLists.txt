project(UvttThumbnailer)

# Set minimum required version of cmake.
cmake_minimum_required(VERSION 2.8.12)

set(QT_MIN_VERSION "5.2.0")

# Locate extra-cmake-modules version 0.0.11 and make it a required package
find_package(ECM 1.0.0 REQUIRED NO_MODULE)

# Set value of CMAKE_MODULE_PATH variable where cmake will search for modules
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Qt5Gui REQUIRED)
find_package(KF5 REQUIRED COMPONENTS KIO Archive)

include(FeatureSummary)
include(WriteBasicConfigVersionFile)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

set(UvttThumbnailer_SRCS src/uvttcreator.cpp)

add_library(uvttthumbnailer MODULE ${UvttThumbnailer_SRCS})

target_link_libraries(uvttthumbnailer Qt5::Gui KF5::KIOWidgets KF5::Archive)

install(TARGETS uvttthumbnailer             DESTINATION ${PLUGIN_INSTALL_DIR})
install(TARGETS uvttthumbnailer             DESTINATION ${QT_PLUGIN_INSTALL_DIR})
# Source I copied this from (https://github.com/StefanHamminga/kde-uvtt-thumbnailer) had the above 2 lines commented out and these in their place
#install(TARGETS uvttthumbnailer             DESTINATION ${LIB_INSTALL_DIR}/qt5/plugins)
#install(FILES   src/uvttthumbnailer.desktop DESTINATION ${SERVICES_INSTALL_DIR})
