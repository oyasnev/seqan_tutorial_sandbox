# ===========================================================================
#                  SeqAn - The Library for Sequence Analysis
# ===========================================================================
# File: /sandbox/tutorial_sandbox/apps/stringsetsWA4/CMakeLists.txt
#
# CMakeLists.txt file for stringsetsWA4.
# ===========================================================================

cmake_minimum_required (VERSION 2.8.2)
project (seqan_sandbox_tutorial_sandbox_apps_stringsetsWA4)
message (STATUS "Configuring sandbox/tutorial_sandbox/apps/stringsetsWA4")

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
add_executable (stringsetsWA4 stringsetsWA4.cpp)

# Add dependencies found by find_package (SeqAn).
target_link_libraries (stringsetsWA4 ${SEQAN_LIBRARIES})

# Add CXX flags found by find_package (SeqAn).
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SEQAN_CXX_FLAGS}")

# ----------------------------------------------------------------------------
# Installation
# ----------------------------------------------------------------------------

# Set variables for installing, depending on the selected build type.
if (NOT SEQAN_PREFIX_SHARE_DOC)
  seqan_setup_install_vars (stringsetsWA4)
endif (NOT SEQAN_PREFIX_SHARE_DOC)

# Install stringsetsWA4 in ${PREFIX}/bin directory
install (TARGETS stringsetsWA4
         DESTINATION bin)

# Install non-binary files for the package to "." for app builds and
# ${PREFIX}/share/doc/stringsetsWA4 for SeqAn release builds.
install (FILES LICENSE
               README
         DESTINATION ${SEQAN_PREFIX_SHARE_DOC})
#install (FILES example/fasta1.fa
#               example/fasta2.fa
#         DESTINATION ${SEQAN_PREFIX_SHARE_DOC}/example)

# ----------------------------------------------------------------------------
# App Test
# ----------------------------------------------------------------------------

#seqan_add_app_test (stringsetsWA4)

# ----------------------------------------------------------------------------
# CPack Install
# ----------------------------------------------------------------------------

if (SEQAN_BUILD_SYSTEM STREQUAL "APP:stringsetsWA4")
  set (CPACK_PACKAGE_NAME "stringsetsWA4")
  set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "stringsetsWA4")
  set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.net>")
  set (CPACK_PACKAGE_VENDOR "Your Name <your.email@example.net>")

  seqan_configure_cpack_app (stringsetsWA4 "stringsetsWA4")
endif (SEQAN_BUILD_SYSTEM STREQUAL "APP:stringsetsWA4")

