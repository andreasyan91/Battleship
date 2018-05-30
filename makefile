BIN_DIR		 := bin
DOCS_DIR		 := docs
TEST_DIR		 := tests
HEADERS_DIR	 := src/header
SOURCES_DIR	 := src/source
OBJECTS_DIR	 := obj
INCLUDE_PATH := -I./src/header

HEADERS := $(wildcard $(HEADERS_DIR)/*.hpp)  
SOURCES := $(wildcard $(SOURCES_DIR)/*.cpp) 
OBJECTS := $(patsubst $(SOURCES_DIR)/%.cpp, $(OBJECTS_DIR)/%.o, $(SOURCES))
DEPENDS := $(patsubst $(SOURCES_DIR)/%.cpp, deps/%.deps, $(SOURCES))
TARGET := $(BIN_DIR)/battleship.exe

$(TARGET) : $(OBJECTS) $(HEADERS)
		mkdir -p bin
		echo "building battleship.exe ..."
		g++ -std=c++11  $^ -o $@ 

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.cpp
		mkdir -p obj
		g++ -std=c++11 -o $@ -c $^  $(INCLUDE_PATH)

deps/%.dep: $(SOURCES_DIR)/%.cpp
		mkdir -p deps
		g++ -MM %< -MT "$@ $(patsubst $@, $(OBJECTS_DIR)/%.o, $@)" -o $@ $(INCLUDE_PATH)

-include $(DEPENDS)

clean :
	   @echo "clean up..."
		@rm -rf $(OBJECTS_DIR) $(BIN_DIR)
		@rm -rf $(DOCS_DIR)/doxygen
		@rm -f  $(TEST_DIR)/*.o $(TEST_DIR)/*.exe 

doxygen :
	   @doxygen ./Doxyfile

html :
		@firefox $(DOCS_DIR)/doxygen/html/index.html

run :
	   @$(BIN_DIR)/battleship.exe   
	
		
