
#!/bin/bash

################## Script to compile and run QAM ##################

pushd ${PWD} > /dev/null
cd ~/gitrepos/QAM/build
./TX
popd > /dev/null
