CPP_FILES := 	$(wildcard src/*cpp)
CPP_FILES +=	include/vendor/stb_image.cpp
O_FILES := 		$(patsubst %.cpp,%.o,$(CPP_FILES))
EXEC_NAME :=		opengl_test

COMPILE_FLAGS :=	-g -c
INCLUDE_PATHS :=	-I./include -I../glew-2.1.0/include -I../glfw-3.3.6/include -I./include/vendor -I../glm
LIBRARY_PATHS :=	-L./lib
LIBRARIES :=		-lGLEW -lglfw -framework OpenGL -lstdc++ -lpngloader

$(EXEC_NAME) : $(O_FILES)
	gcc $(LIBRARY_PATHS) -o $(EXEC_NAME) $(O_FILES) $(LIBRARIES)

%.o : %.cpp
	gcc -std=c++17 $(INCLUDE_PATHS) $(COMPILE_FLAGS) $< -o $@

.PHONY: clean
clean:
	rm src/*.o
	rm $(EXEC_NAME)
