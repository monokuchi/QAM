
#!/bin/bash

################## Script to compile and run qam.cpp ##################

pushd ${PWD} > /dev/null
cd ~/gitrepos/QAM/src
g++ -o qam qam.cpp
./qam
popd > /dev/null
