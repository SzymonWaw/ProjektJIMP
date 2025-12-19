all:
	mkdir -p bin
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@echo "=== TEST 1 (A, b) ==="
	bin/gauss dane/A dane/b
	@echo "=== TEST 2 (C, d) ==="
	bin/gauss dane/C dane/d

clean:
	rm -rf bin