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


in vtabletest you find an example with classes and virtual functions, where
an executable loads a plugin, and both have classes with the same names.
There you can also experiment what effect the visibility attribute has,
both in the executable and in the plugin.
