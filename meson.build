project(
  'gtkmm-browser',
  'cpp',
  version: '0.1',
  default_options: ['cpp_std=c++20']
)

# Gtkmm 4
gtkmm_dep = dependency('gtkmm-4.0', required: true)

# WebKitGTK 6
webkit_dep = dependency('webkitgtk-6.0', required: true)

executable(
  'gtkmm-browser',
  'main.cpp',
  dependencies: [gtkmm_dep, webkit_dep]
)
