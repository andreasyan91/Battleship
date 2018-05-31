SOURCES := $(wildcard src/*.cpp) 
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))
CFLAGS  := -std=c++11

bin/program : $(OBJECTS) 
	@mkdir -p ./bin
	echo "building battleship.exe ..."
	@g++ $(CFLAGS)  $^ -o $@ 

obj/%.o : src/%.cpp
	@mkdir -p ./obj
	@g++ $(CFLAGS) -c $< -I./src -o $@

deps/%.dep: src/%.cpp
	@mkdir -p ./deps
	@g++ -MM $< -MT "$@ $(patsubst deps/%.dep, obj/%.o, $@)" -o $@ -I./src

-include $(DEPENDS)

clean :
	@echo "clean up..."
	@rm -rf obj bin deps
	@rm -rf docs/doxygen
	@rm -f  tests/*.o tests/*.exe 

doxygen :
	@mkdir -p ./docs/doxygen
	@doxygen ./Doxyfile

html : doxygen 
	@firefox ./docs/doxygen/html/index.html

run : bin/program 
	@bin/program   


