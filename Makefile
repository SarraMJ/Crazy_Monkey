OBJ = obj/Jungle.o obj/Arbre.o obj/Singe.o  obj/Serpent.o  obj/Vec2.o 

COMPILER = g++

CFLAGS = -g -Wall

LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL

all: folders bin/Jeu  bin/Txt docs

folders:
	mkdir -p obj bin data

bin/Txt : obj/main_txt.o
	$(COMPILER) $(OBJ) obj/AffichageTxt.o obj/main_txt.o -o bin/Txt

bin/Jeu: $(OBJ) obj/mainJeu.o
	$(COMPILER) $(OBJ) obj/mainJeu.o -o bin/Jeu $(LIBS_SDL)

obj/mainJeu.o: src/mainJeu.cpp src/Jungle.h 
	$(COMPILER) $(CFLAGS) -c src/mainJeu.cpp  -o obj/mainJeu.o


obj/main_txt.o : src/main_txt.cpp src/Jungle.h
	$(COMPILER) $(CFLAGS) -c src/main_txt.cpp  -o obj/main_txt.o

obj/AffichageTxt.o: src/AffichageTxt.h src/WinTxt.h src/Jungle.h src/Arbre.h src/Singe.h src/Vec2.h src/Serpent.h
	$(COMPILER) $(CFLAGS) -c src/AffichageTxt.cpp -o obj/AffichageTxt.o

obj/Jungle.o: src/Jungle.cpp src/Jungle.h src/Arbre.h src/Singe.h src/Vec2.h src/Serpent.h
	$(COMPILER) $(CFLAGS) -c src/Jungle.cpp -o obj/Jungle.o

obj/Arbre.o: src/Arbre.cpp src/Arbre.h src/Serpent.h src/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/Arbre.cpp -o obj/Arbre.o

obj/Serpent.o: src/Serpent.cpp src/Serpent.h src/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/Serpent.cpp -o obj/Serpent.o

obj/Singe.o: src/Singe.cpp src/Singe.h src/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/Singe.cpp -o obj/Singe.o

obj/Vec2.o: src/Vec2.cpp src/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/Vec2.cpp -o obj/Vec2.o

obj/WinTxt : src/WinTxt.cpp src/WinTxt.h
	$(COMPILER) $(CFLAGS) -c src/WinTxt.cpp -o obj/WinTxt.o

docs: doc/image.doxy
	doxygen doc/image.doxy

clean:
	rm -rf obj/* bin/* doc/html callgrind.out.*
