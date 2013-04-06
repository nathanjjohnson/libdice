CC        = g++
CFLAGS    = -c -Wall
LDFLAGS   = -L/usr/lib -L./lib -ldice
INCLUDE   = -I./include
OBJDIR    = obj/
OBJLIST   = Die.o LoadedDie.o DieRoller.o DiceRoller.o 
OBJECTS   = $(addprefix $(OBJDIR), $(OBJLIST) )
LIBRARY    = lib/libdice.a
TEST      = test/test.exe
all:$(LIBRARY) $(TEST)

$(LIBRARY): $(OBJECTS)
	ar crv $@ $(OBJECTS)

$(OBJECTS): obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $? -o $@ $(INCLUDE)

$(TEST): $(OBJECTS) $(LIBRARY)
	$(CC) -o $(TEST) test/main.cpp $(INCLUDE) $(LDFLAGS)
 
clean:
	rm -rf obj/*.o lib/*.a
