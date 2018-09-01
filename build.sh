#!/usr/bin/env bash

if [ ! -e 'target' ]; then mkdir 'target'; fi
cp ./run.sh target
cp cmake-build-debug/pythagorean_triples target
cp ./resources/*.* target

cd target
chmod a+x run.sh
