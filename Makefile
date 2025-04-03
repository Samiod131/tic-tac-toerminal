.PHONY: all clean

all:
	mkdir -p build
	echo "App_Data" > build/.gitignore
	cd build && cmake .. && cmake --build .

clean:
	rm -rf build

run: all
	./build/TicTacToerminal