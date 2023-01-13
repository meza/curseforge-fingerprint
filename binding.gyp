{
  "targets": [
    {
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      "target_name": "curseforge",
      "sources": [
        "src/binding.cc"
      ],
      'conditions': [
        [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
          'cflags': ['-Wno-cast-function-type'],
        }],
      ]
    }
  ]
}
