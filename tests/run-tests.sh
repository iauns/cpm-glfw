#!/bin/bash
cd "$(dirname "$0")"

if [ ! -d ./bin ]; then
  mkdir -p ./bin
fi

# Ensure we fail immediately if any command fails.
set -e

pushd ./bin > /dev/null
  cmake -DCPM_MODULE_CACHE_DIR=$HOME/.cpm_cache ..
  make
popd

# Run the tests
./bin/glfw_test
