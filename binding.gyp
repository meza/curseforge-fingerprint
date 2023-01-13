{
  "targets": [
    {
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "target_name": "curseforge",
      "sources": [
        "src/binding.cc"
      ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "include_dirs": [
          "<!@(node -p \"require('node-addon-api').include\")"
       ]
    }
  ]
}
