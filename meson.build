project('iprof', 'c')
os = host_machine.system()
os_windows = (os == 'windows')
os_is_linux = (os == 'linux')


src = files(
  'prof.h',
  'prof_draw.c',
  'prof_gather.c',
  'prof_process.c',
)

if os_windows
  src += 'prof_win32.c'
elif os_is_linux
  src += 'prof_linux.c'
endif

inc = include_directories('.')

iprof_lib = library(
  'raylib',
  src,
  include_directories: [inc],
)

iprof_dep = declare_dependency(
  link_with: iprof_lib,
  include_directories: [inc],
)

if get_option('BUILD_EXAMPLE')
  raylib_options = [
    'default_library=static',
    'SUPPORT_FILEFORMAT_FLAC=true',
    'SUPPORT_FILEFORMAT_MP3=true',
    'SUPPORT_MODULE_RMODELS=false',
    'SUPPORT_CAMERA_SYSTEM=false',
    'SUPPORT_GESTURES_SYSTEM=false',
    'SUPPORT_COMPRESSION_API=false',
    'SUPPORT_AUTOMATION_EVENTS=false',
  ]
  raylib_proj = subproject('raylib', default_options: raylib_options)
  raylib_dep = raylib_proj.get_variable('raylib_dep')

  src += 'main.c'
  executable(
    meson.project_name(),
    src,
    dependencies: [raylib_dep],
    include_directories: [inc]
  )
endif
