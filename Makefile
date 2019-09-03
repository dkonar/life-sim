CXX = em++
BUILD_DIR ?= ./build
CXXFLAGS = -s BINARYEN_TRAP_MODE=clamp -s USE_SDL=2 -s ERROR_ON_UNDEFINED_SYMBOLS=0
all: main

main:
		$(MKDIR_P) $(BUILD_DIR)
		$(CXX) -o ${BUILD_DIR}/hello.html src/main.cpp src/board.cpp src/lifeform.cpp src/colors.cpp ${CXXFLAGS}

.PHONY: watch clean

watch:
	while true; do \
		inotifywait -qr -e modify -e create -e delete -e move src; \
		make; \
	done

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P ?= mkdir -p
