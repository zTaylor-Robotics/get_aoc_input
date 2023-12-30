cmake -S /get_aoc_input/ -B /get_aoc_input/bin -G "Ninja Multi-Config"

ninja -f /get_aoc_input/bin/build-Release.ninja

ln -s /get_aoc_input/bin/Release/get_input /usr/bin/get_input
