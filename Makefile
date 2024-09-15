CC = g++
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: $(BUILD_FOLDER)/crusher
	
$(BUILD_FOLDER)/crusher: $(BUILD_FOLDER)/crusher.o
	$(CC) -o $@ $^

$(BUILD_FOLDER)/crusher.o: $(SOURCE_FOLDER)/main.cpp
	$(CC) -o $@ -c $^