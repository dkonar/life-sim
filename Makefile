src = $(wildcard src/*.cpp)
CXX = em++
BUILD_DIR ?= ./build
CXXFLAGS = -s BINARYEN_TRAP_MODE=clamp -s USE_SDL=2
all: src/main.cpp src/board.cpp src/board.cpp
	  $(MKDIR_P) $(BUILD_DIR)
		$(CXX) $(src) ${CXXFLAGS} -o ${BUILD_DIR}/hello.html

.PHONY: watch clean

watch:
	while true; do \
		inotifywait -qr -e modify -e create -e delete -e move src; \
		make; \
	done

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P ?= mkdir -p
