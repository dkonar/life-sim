CC = emcc
all: src/main.c
		$(CC) src/main.c -O2 -s USE_SDL=2 -o ./build/hello.html

.PHONY: watch
watch:
	while true; do \
	inotifywait -qr -e modify -e create -e delete -e move src; \
	make; \
done
