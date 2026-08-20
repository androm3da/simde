fs = import('fs')

simde_test_hexagon_hvx_simd_tests = simde_hvx_families + ['types']

simde_test_hexagon_hvx_qemu_broken = []
# QEMU cannot decode the floating-point comparison instructions.
simde_test_hexagon_hvx_qemu_broken += ['vcmp']
# QEMU does not model out-of-range gathers.
simde_test_hexagon_hvx_qemu_broken += ['vgather']
simde_test_hexagon_hvx_on_qemu = (host_machine.cpu_family() == 'hexagon')

simde_test_hexagon_hvx_simd_sources = []
simde_test_hexagon_hvx_simd_libs = []
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

      if not (emul == 'native'
              and simde_test_hexagon_hvx_on_qemu
              and name in simde_test_hexagon_hvx_qemu_broken)
        test('hexagon_hvx_simd/' + name + '/' + emul + '/' + lang, x,
            protocol: 'tap',
            workdir: meson.current_build_dir())
      endif
    endforeach
  endforeach
endforeach
