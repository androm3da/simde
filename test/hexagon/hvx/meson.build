fs = import('fs')

simde_test_hexagon_hvx_simd_tests = simde_hvx_families

simde_test_hexagon_hvx_simd_sources = []
foreach name : simde_test_hexagon_hvx_simd_tests
  foreach lang : ['c', 'cpp']
    source_file = name + '.c'
    if lang == 'cpp'
      source_file = fs.copyfile(name + '.c', name + '.cpp')
    endif
    simde_test_hexagon_hvx_simd_sources += source_file

    foreach emul : ['emul', 'native']
      extra_flags = ['-DSIMDE_TEST_BARE']
      if emul == 'emul'
        extra_flags += '-DSIMDE_NO_NATIVE'
      endif

      x = executable(name + '-' + emul +  '-' + lang, source_file,
          c_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          include_directories: simde_include_dir,
          dependencies: simde_deps)

      test('hexagon_hvx_simd/' + name + '/' + emul + '/' + lang, x,
          protocol: 'tap',
          suite: 'hexagon',
          workdir: meson.current_build_dir())
    endforeach
  endforeach
endforeach
