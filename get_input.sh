cmake -S . -B bin -G "Ninja Multi-Config"

cd bin

ninja -f build-Release.ninja

cd Release

ln -s ./get_input /usr/bin/get_input

cd ../..