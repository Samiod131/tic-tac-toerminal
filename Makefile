.PHONY: all clean

all:
	mkdir -p build
	cd build && cmake .. && cmake --build .

clean:
	rm -rf build

run: all
	./build/TicTacToerminal