CPP_FILES := 	$(wildcard src/*cpp)
CPP_FILES +=	include/vendor/stb_image.cpp
O_FILES := 		$(patsubst %.cpp,%.o,$(CPP_FILES))

COMPILE_FLAGS :=	-g -c
INCLUDE_PATHS :=	-I./include -I../glew-2.1.0/include -I../glfw-3.3.6/include -I./include/vendor
LIBRARY_PATHS :=	-L./lib
LIBRARIES :=		-lGLEW -lglfw -framework OpenGL -lstdc++ -lpngloader

exec : $(O_FILES)
	gcc $(LIBRARY_PATHS) -o exec $(O_FILES) $(LIBRARIES)

%.o : %.cpp
	gcc -std=c++17 $(INCLUDE_PATHS) $(COMPILE_FLAGS) $< -o $@

.PHONY: clean
clean:
	rm src/*.o
	rm exec
