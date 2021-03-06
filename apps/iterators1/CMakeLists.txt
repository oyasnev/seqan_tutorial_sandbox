# ===========================================================================
#                  SeqAn - The Library for Sequence Analysis
# ===========================================================================
# File: /sandbox/tutorial_sandbox/apps/iterators1/CMakeLists.txt
#
# CMakeLists.txt file for iterators1.
# ===========================================================================

cmake_minimum_required (VERSION 2.8.2)
project (seqan_sandbox_tutorial_sandbox_apps_iterators1)
message (STATUS "Configuring sandbox/tutorial_sandbox/apps/iterators1")

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
add_executable (iterators1 iterators1.cpp)

# Add dependencies found by find_package (SeqAn).
target_link_libraries (iterators1 ${SEQAN_LIBRARIES})

# Add CXX flags found by find_package (SeqAn).
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SEQAN_CXX_FLAGS}")

# ----------------------------------------------------------------------------
# Installation
# ----------------------------------------------------------------------------

# Set variables for installing, depending on the selected build type.
if (NOT SEQAN_PREFIX_SHARE_DOC)
  seqan_setup_install_vars (iterators1)
endif (NOT SEQAN_PREFIX_SHARE_DOC)

# Install iterators1 in ${PREFIX}/bin directory
install (TARGETS iterators1
         DESTINATION bin)

# Install non-binary files for the package to "." for app builds and
# ${PREFIX}/share/doc/iterators1 for SeqAn release builds.
install (FILES LICENSE
               README
         DESTINATION ${SEQAN_PREFIX_SHARE_DOC})
#install (FILES example/fasta1.fa
#               example/fasta2.fa
#         DESTINATION ${SEQAN_PREFIX_SHARE_DOC}/example)

# ----------------------------------------------------------------------------
# App Test
# ----------------------------------------------------------------------------

#seqan_add_app_test (iterators1)

# ----------------------------------------------------------------------------
# CPack Install
# ----------------------------------------------------------------------------

if (SEQAN_BUILD_SYSTEM STREQUAL "APP:iterators1")
  set (CPACK_PACKAGE_NAME "iterators1")
  set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "iterators1")
  set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.net>")
  set (CPACK_PACKAGE_VENDOR "Your Name <your.email@example.net>")

  seqan_configure_cpack_app (iterators1 "iterators1")
endif (SEQAN_BUILD_SYSTEM STREQUAL "APP:iterators1")

