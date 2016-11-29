#!/bin/bash

echo "--- Installing cvBlob..."
wget -O cvblob-0.10.4-src.tgz https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/cvblob/cvblob-0.10.4-src.tgz
tar xzvf cvblob-0.10.4-src.tgz
cd cvblob/
mkdir build
cd build
cmake ..
sudo make install /usr/local/lib
echo "--- Installation of cvBlob complete."
