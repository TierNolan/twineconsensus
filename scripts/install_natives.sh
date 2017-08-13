#!/bin/bash

set -e

if [ -z $1 ]; then
  echo Error: No host variable set, exiting
  exit 1
fi

HOST=$1

if [ -z $2 ]; then
  echo Error: No prefix set, exiting
  exit 1
fi

PREFIX=$2

if [ -z $3 ]; then
  echo Error: No library version set, exiting
  exit 1
fi

LIBVER=$3

if [ -z $4 ]; then
  echo Info: Skipping installation to natives directory as TW_NATIVE_PATH is not set
  exit 0
fi

NATIVE_PATH=$4

if [ ! -d $NATIVE_PATH ]; then
  echo Error: Natives directory given in TW_NATIVE_PATH does not exist, exiting
  exit 1
fi

if [[ $HOST == *"linux"* ]]; then
  OS=linux
  SHARED_SUFFIX=.so.${LIBVER}
  SHARED_DIR=lib
elif [[ $HOST == *"w32"* ]]; then
  OS=win32
  SHARED_SUFFIX=-${LIBVER}.dll
  SHARED_DIR=bin
elif [[ $HOST == *"w64"* ]]; then
  OS=win32
  SHARED_SUFFIX=-${LIBVER}.dll
  SHARED_DIR=bin
else
  echo Unknown OS
  exit 1
fi

if [[ $HOST == *"x86_64"* ]]; then
  CPU_ARCH=x86-64
elif [[ $HOST == *"i686"* ]]; then
  CPU_ARCH=x86
else
  echo Unknown CPU architecture
  exit 1
fi

RESOURCE_PREFIX=${OS}-${CPU_ARCH}

LIB_PATH=${NATIVE_PATH}/${RESOURCE_PREFIX}

PREFIX_PATH=${PREFIX}/${SHARED_DIR}

mkdir -p $LIB_PATH

SECP256K1_FILENAME=libsecp256k1${SHARED_SUFFIX}
TWINECONSENSUS_FILENAME=libtwineconsensus${SHARED_SUFFIX}

cp ${PREFIX_PATH}/${SECP256K1_FILENAME} ${LIB_PATH}
sha256sum -b ${PREFIX_PATH}/${SECP256K1_FILENAME} | sed 's/ .*$//' > ${LIB_PATH}/${SECP256K1_FILENAME}.sha256

cp ${PREFIX_PATH}/${TWINECONSENSUS_FILENAME} ${LIB_PATH}
sha256sum -b ${PREFIX_PATH}/${TWINECONSENSUS_FILENAME} | sed 's/ .*$//' > ${LIB_PATH}/${TWINECONSENSUS_FILENAME}.sha256
