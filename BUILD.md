Cross Compiling Windows DLL
---------------------------

Windows Dlls can be cross compiled in Linux by setting the host configuration parameter.

    ./configure --host=x86_64-w64-mingw32

Setting Natives Directory
-------------------------

If the TW_NATIVE_PATH variable is set, make install will install the shared library 
to the natives directory.  The directory is structured for inclusion as a java resource.

export TW_NATIVE_PATH=<path to TwineNode>/TwineNode/src/main/resources/

Building All Natives
--------------------

These commands build the natives for Linux and use cross-compilation to build for Windows.

The TW_NATIVE_PATH variable should point to the Java repository's resource folder.

This will install them as a Java resource.

    ./autogen.sh && ./configure --host=x86_64-w64-mingw32 && make clean && make && make install && \
    ./autogen.sh && ./configure --host=i686-w64-mingw32   && make clean && make && make install && \
    ./autogen.sh && ./configure                           && make clean && make && make install

