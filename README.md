This is a simple dummy library, executable and "plugin" for playing around
with ctors and dtors and plugin loading.

First build and install foolib:
cd foolib
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/opt/foo ..
make
make install

Then build and run libtester:
cd libtester
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/opt/foo ..
make

./libtesterstatic 5
