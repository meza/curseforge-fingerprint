{
  "variables" : {
    "openssl_fips": "",
  },
  "targets": [
    {
      "target_name": "curseforge",
      "sources": [
        "src/addon/fingerprint.h",
        "src/addon/fingerprint.cpp",
        "src/addon/binding.cc"
      ],
      "cflags": [
        "-std=c++11",
        "-Wall",
        "-pedantic"
      ],
      "include_dirs": [],
      "libraries": [],
      "dependencies": [],
      "conditions": [
        [
          "OS==\"win\"", {}],
        [
          "OS==\"mac\"", {}],
        [
          "OS==\"linux\"", {}]
      ],
      "defines": [
        "NAPI_VERSION=<(napi_build_version)"
      ]
    }
  ]
}
