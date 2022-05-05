CC=g++ --std=c++17

run:
	$(CC) src/main.cpp -o snake

# This wont work on windows
clean:
	rm a.* src/*.gch
