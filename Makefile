EXECUTABLE := RobotNavigation

SOURCES := *.cpp

INCLUDES := -I ..\include
EXT := exe
CC := g++

life:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)
