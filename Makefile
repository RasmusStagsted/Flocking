CC	  = g++#Compiler

CFLAGS    = -w -c -std=c++11#Compiler Flags

LDFLAGS	  = -lSDL2_gfx -lSDL2_image#Linker options

SOURCES   = main.cpp#
SOURCES  += ../libraries/sources/Boid.cpp#
SOURCES  += ../libraries/sources/Color.cpp#
SOURCES  += ../libraries/sources/Vector.cpp#
SOURCES  += ../libraries/sources/Window.cpp#
SOURCES  += ../libraries/sources/Checkbox.cpp#
SOURCES  += ../libraries/sources/Button.cpp#
SOURCES  += ../libraries/sources/Slider.cpp#

OBJECTS  = $(SOURCES:.cpp=.o)#Object files

EXECUTEABLE= a.out #Output name

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
#	$(CC) $(OBJECTS) `sdl2-config --cflags --libs` $(LDFLAGS) -o $(EXECUTEABLE)
	$(CC) $(OBJECTS) -lSDL2 $(LDFLAGS) -o $(EXECUTEABLE)


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
