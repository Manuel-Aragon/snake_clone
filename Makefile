CC=g++ --std=c++20

run:
	$(CC) src/main.cpp -o snake

# This wont work on windows
clean:
	rm a.* src/*.gch
