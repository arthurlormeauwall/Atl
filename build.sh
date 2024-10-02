cmake -S . -B build/ ; cmake --build build ; 
cp build/atl/atlCore/libatlCore.a lib/atl.a;
cp build/atl/atlRunner/atlRunner example/testRunner/atlRunner