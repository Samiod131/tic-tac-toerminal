.PHONY: all clean run

# Detect the operating system
ifeq ($(OS),Windows_NT)
    # Windows-specific commands
    MKDIR = if not exist build mkdir build
    RMDIR = if exist build rmdir /s /q build
    EXEPATH = .\build\TicTacToerminal.exe
else
    # Unix/Linux-specific commands
    MKDIR = mkdir -p build
    RMDIR = rm -rf build
    EXEPATH = ./build/TicTacToerminal
endif

all:
	$(MKDIR)
	cd build && cmake .. && cmake --build .

clean:
	$(RMDIR)

run: all
	$(EXEPATH)