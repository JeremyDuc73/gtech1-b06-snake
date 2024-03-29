CC=g++
# Adapt the variables below to your needs:
EXE=snake
CPP=game/*.cpp
HPP=game/direction.h  game/*.hpp

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -lSDL2 -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

# Build the UML diagram as a PNG image:
uml/classes.png: $(HPP)
	./uml/mk_uml.sh uml/classes.png game/*.hpp

# Count the number of lines of code:
nblines:
	@wc -l $(CPP) $(HPP)