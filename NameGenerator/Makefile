OUTPUT_PATH=Obj
SOURCE_PATH=Source

BUILD_FLAGS=-g #-Wall -Wextra

all: NameGenerator

NameGenerator: NameGenerator.o Names.o NameGenerator_UI_CL.o
	g++ $(BUILD_FLAGS) $(OUTPUT_PATH)\NameGenerator.o $(OUTPUT_PATH)\Names.o $(OUTPUT_PATH)\NameGenerator_UI_CL.o -o NameGenerator.exe

NameGenerator.o: $(SOURCE_PATH)\NameGenerator.cpp
	g++ $(BUILD_FLAGS) -o $(OUTPUT_PATH)\NameGenerator.o -c $(SOURCE_PATH)\NameGenerator.cpp

Names.o: $(SOURCE_PATH)\Names.cpp
	g++ $(BUILD_FLAGS) -o $(OUTPUT_PATH)\Names.o -c $(SOURCE_PATH)\Names.cpp

NameGenerator_UI_CL.o: $(SOURCE_PATH)\NameGenerator_UI_CL.cpp
	g++ $(BUILD_FLAGS) -o $(OUTPUT_PATH)\NameGenerator_UI_CL.o -c $(SOURCE_PATH)\NameGenerator_UI_CL.cpp

clean:
	del $(OUTPUT_PATH)\*.o NameGenerator.exe