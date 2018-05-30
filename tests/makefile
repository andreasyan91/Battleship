#HEADERS := $(wildcard ../src/header/*.hpp) 
SOURCES := $(wildcard ./*.cpp) 
#OBJECTS := $(patsubst ./%.cpp, ../src/source/battleship_functions.cpp, ./%.o,./%o $(SOURCES))
OBJECTS := $(patsubst ./%.cpp, ../src/source/.cpp, ./%.o $(SOURCES))
TARGET  := test.exe
INCLUDE_PATH := -I../src/header
DEPENDS := $(patsubst deps/%.dep, sr)

$(TARGET) : $(OBJECTS) #$(HEADERS)
	      @echo "test.exe ..."
			@g++ -std=c++11  $^ -o $@ 

$(OBJECTS) : $(SOURCES) 
			@echo "text"
			@g++ -std=c++11 -c  $<  $(INCLUDE_PATH)

test :
	@./test.exe
		
