#!/bin/bash

prebuildify --napi --strip --target node@16.16.0 --arch x64
prebuildify --napi --strip --target node@16.16.0 --arch arm64
