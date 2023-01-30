{
  "variables" : {
    "openssl_fips": "",
  },
  "targets": [
    {
      "target_name": "curseforge",
      "sources": [
        "src/fingerprint.h",
        "src/fingerprint.cpp",
        "src/binding.cc"
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
