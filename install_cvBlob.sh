#!/bin/bash

echo "--- Removing any pre-installed ffmpeg and x264"
wget -O cvblob-0.10.4-src.tgz https://cvblob.googlecode.com/files/cvblob-0.10.4-src.tgz
tar xzvf cvblob-0.10.4-src.tgz
cd cvblob/
mkdir build
cd build
cmake ..
sudo make install
