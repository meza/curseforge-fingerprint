#!/bin/bash

prebuildify --napi --all --strip
prebuildify --arch=ia32 --napi --strip

#TARGET=node@18.5.0
#
#prebuildify --napi --target $TARGET --platform win32 --arch x64
#prebuildify --napi --target $TARGET --platform win32 --arch arm64
#prebuildify --napi --target $TARGET --platform darwin --arch x64
#prebuildify --napi --target $TARGET --platform darwin --arch arm64
#prebuildify --napi --target $TARGET --platform linux --arch x64
#prebuildify --napi --target $TARGET --platform linux --arch armhf
#prebuildify --napi --target $TARGET --platform linux --arch arm64
