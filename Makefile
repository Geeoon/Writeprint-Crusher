CC = g++
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: $(BUILD_FOLDER)/crusher
	
$(BUILD_FOLDER)/crusher: $(BUILD_FOLDER)/main.o
	$(CC) -o $@ $^

$(BUILD_FOLDER)/main.o: $(SOURCE_FOLDER)/main.c
	$(CC) -o $@ -c $^

# $(BUILD_FOLDER)/identity.o: $(SOURCE_FOLDER)/identity.
# 	$(CC) -o $@ -c $^