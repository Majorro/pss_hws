# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.20.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(sqliteorm-populate NONE)

# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[F:/prg/Git/cmd/git.exe]==])
set(GIT_VERSION_STRING [==[2.24.1.windows.2]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[F:/prg/Git/cmd/git.exe;2.24.1.windows.2]==]
)


include(ExternalProject)
ExternalProject_Add(sqliteorm-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/fnc12/sqlite_orm" "GIT_TAG" "origin/dev"
                    SOURCE_DIR          "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src"
                    BINARY_DIR          "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


