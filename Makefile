CC = g++
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: $(BUILD_FOLDER)/crusher
	
$(BUILD_FOLDER)/crusher: $(BUILD_FOLDER)/main.o $(BUILD_FOLDER)/identity.o
	$(CC) -o $@ $^

$(BUILD_FOLDER)/main.o: $(SOURCE_FOLDER)/main.cpp
	$(CC) -o $@ -c $^

$(BUILD_FOLDER)/identity.o: $(SOURCE_FOLDER)/identity.cpp
	$(CC) -o $@ -c $^
