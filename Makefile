CC=g++ --std=c++11

run:
	$(CC) src/outline.cpp 

# This wont work on windows
clean:
	rm a.* src/*.gch
