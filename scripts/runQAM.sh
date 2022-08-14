
#!/bin/bash

################## Script to compile and run QAM ##################

pushd ${PWD} > /dev/null
cd ~/gitrepos/QAM/build
./qam
popd > /dev/null
