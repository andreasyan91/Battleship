SOURCES := $(wildcard src/*.cpp) 
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))


bin/program : $(OBJECTS) 
		@mkdir -p ./bin
		echo "building battleship.exe ..."
		@g++ -std=c++11  $^ -o $@ 

obj/%.o : src/%.cpp
		@mkdir -p ./obj
		@g++ -std=c++11 -c $< -I./src -o $@

deps/%.dep: src/%.cpp
		@mkdir -p ./deps
		@g++ -MM $< -MT "$@ $(patsubst deps/%.dep, obj/%.o, $@)" -o $@ -I./src

-include $(DEPENDS)

.PHONY:
clean :
	   @echo "clean up..."
		@rm -rf obj bin deps
		@rm -rf docs/doxygen
		@rm -f  tests/*.o tests/*.exe 

doxygen :
	   @doxygen ./Doxyfile

html :
		@firefox ./docs/doxygen/html/index.html

run :
	   @bin/battleship.exe   
	
		
