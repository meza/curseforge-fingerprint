#!/bin/bash

function build {
  prebuild -r napi -t $1 --arch $2 --strip
}


build 8 ia32
build 8 x64
build 8 arm64
