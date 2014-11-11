# ===========================================================================
#                  SeqAn - The Library for Sequence Analysis
# ===========================================================================
# File: /sandbox/tutorial_sandbox/apps/graphs3/CMakeLists.txt
#
# CMakeLists.txt file for graphs3.
# ===========================================================================

cmake_minimum_required (VERSION 2.8.2)
project (seqan_sandbox_tutorial_sandbox_apps_graphs3)
message (STATUS "Configuring sandbox/tutorial_sandbox/apps/graphs3")

# ----------------------------------------------------------------------------
# Dependencies
# ----------------------------------------------------------------------------

# Search SeqAn and select dependencies.
#set (SEQAN_FIND_DEPENDENCIES NONE)
find_package (SeqAn REQUIRED)

# ----------------------------------------------------------------------------
# Build Setup
# ----------------------------------------------------------------------------

# Add include directories.
include_directories (${SEQAN_INCLUDE_DIRS})

# Add definitions set by find_package (SeqAn).
add_definitions (${SEQAN_DEFINITIONS})

# Update the list of file names below if you add source files to your application.
add_executable (graphs3 graphs3.cpp)

# Add dependencies found by find_package (SeqAn).
target_link_libraries (graphs3 ${SEQAN_LIBRARIES})

# Add CXX flags found by find_package (SeqAn).
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SEQAN_CXX_FLAGS}")

# ----------------------------------------------------------------------------
# Installation
# ----------------------------------------------------------------------------

# Set variables for installing, depending on the selected build type.
if (NOT SEQAN_PREFIX_SHARE_DOC)
  seqan_setup_install_vars (graphs3)
endif (NOT SEQAN_PREFIX_SHARE_DOC)

# Install graphs3 in ${PREFIX}/bin directory
install (TARGETS graphs3
         DESTINATION bin)

# Install non-binary files for the package to "." for app builds and
# ${PREFIX}/share/doc/graphs3 for SeqAn release builds.
install (FILES LICENSE
               README
         DESTINATION ${SEQAN_PREFIX_SHARE_DOC})
#install (FILES example/fasta1.fa
#               example/fasta2.fa
#         DESTINATION ${SEQAN_PREFIX_SHARE_DOC}/example)

# ----------------------------------------------------------------------------
# App Test
# ----------------------------------------------------------------------------

#seqan_add_app_test (graphs3)

# ----------------------------------------------------------------------------
# CPack Install
# ----------------------------------------------------------------------------

if (SEQAN_BUILD_SYSTEM STREQUAL "APP:graphs3")
  set (CPACK_PACKAGE_NAME "graphs3")
  set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "graphs3")
  set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.net>")
  set (CPACK_PACKAGE_VENDOR "Your Name <your.email@example.net>")

  seqan_configure_cpack_app (graphs3 "graphs3")
endif (SEQAN_BUILD_SYSTEM STREQUAL "APP:graphs3")

