

OBJECT  := ../obj/battleship.o 
SOURCES := $(wildcard ./*.cpp) 
OBJECTS := $(patsubst ./%.cpp, ./%.o, $(SOURCES))
TARGET  := test.exe
INCLUDE_PATH := -I../src

$(TARGET) : $(OBJECTS) 
	@echo "test.exe ..."
	@g++ -std=c++11  $^ $(OBJECT) -o $@ 

./%.o : ./%.cpp 
	@echo "text"
	@g++ -std=c++11 -c  $<  $(INCLUDE_PATH)

clean :
	@echo cleanig up...
	@rm -f ./*.o ./*.exe

test :
	
	@echo sax lava
#	@./test.exe
		
