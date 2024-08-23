project(
  'Minimal VulkanSceneGraph App', 'cpp',
  version: '0.0.1',
  license: 'MIT',
  default_options: ['cpp_std=c++26'],
)


inc = include_directories(
  # Include this (project root) directory in search path.
  # For example, to use `#include "config_dir.h"` in any project subdirectory.
  # (paths are relative to this meason.build script directory and also
  # to the corresponding directory in the build folder)
  '.', 
)


deps = [
  dependency('sdl3'),
  dependency('vsg'),
]


#
# config_dir.h
# Configured installation directories.
# We do not use a "global" config.h, because if we include this directory
# everywhere, then everything gets recompiled when anything changes.
#
projectdir = get_option('projectdir')
prefix     = get_option('prefix')
datadir    = get_option('datadir')

confdir_data = configuration_data()
confdir_data.set_quoted('PROJECTDIR', projectdir,
  description: 'Default name used when we need to create a folder.')

confdir_data.set_quoted('PREFIX', prefix,
  description: 'System-wide installation path.')

confdir_data.set_quoted('GLOBAL_DATADIR', prefix / datadir,
  description: 'System-wide project data directory.')

confdir_data.set_quoted('LOCAL_DATADIR', projectdir / datadir,
  description: 'User\' project data directory.')

configure_file(
  output: 'config_dir.h',
  configuration: confdir_data,
)

#
# Source files.
# In Meason you do not need to list ".h" files.
#
minimal_vsg_src = [
  'main.cpp',
  'MinVsgApp.cpp',
]

minimal_vsg_exec = executable('minimal_vsg', minimal_vsg_src,
  include_directories: inc,
  dependencies: deps,
)

