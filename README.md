Twinecoin Consensus Library
===========================

| Build | Status|
| :-----------: | :--------------: |
| Development | [![Build Status](https://travis-ci.org/twinecoin/twineconsensus.svg?branch=devel)](https://github.com/twinecoin/twineconsensus/tree/devel) |
| Release | [![Build Status](https://travis-ci.org/twinecoin/twineconsensus.svg?branch=master)](https://github.com/twinecoin/twineconsensus/tree/master) |

This is the Twinecoin consensus library.

This library defines the consensus rules for Twinecoin.  The implementation is
minimal and does not include any functionality other than required to define
the Twinecoin consensus rules.

Building
--------

The library is built from the root directory.

    ./autogen.sh
    ./configure
    make
    make check
    make install [optional]

The build result is placed in the ./out directory by default.
