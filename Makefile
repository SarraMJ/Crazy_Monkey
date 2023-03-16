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

obj/mainJeu.o: src/sdl2/mainJeu.cpp src/sdl2/AffichageSDL2.h 
	$(COMPILER) $(CFLAGS) -c src/sdl2/mainJeu.cpp  -o obj/mainJeu.o

obj/AffichageSDL2.o: src/sdl2/AffichageSDL2.h src/core/Jungle.h src/core/Arbre.h src/core/Singe.h src/core/Vec2.h src/core/Serpent.h
	$(COMPILER) $(CFLAGS) -c src/sdl2/AffichageSDL2.cpp -o obj/AffichageSDL2.o

obj/main_txt.o : src/txt/main_txt.cpp src/core/Jungle.h
	$(COMPILER) $(CFLAGS) -c src/txt/main_txt.cpp  -o obj/main_txt.o

obj/AffichageTxt.o: src/txt/AffichageTxt.h src/txt/WinTxt.h src/core/Jungle.h src/core/Arbre.h src/core/Singe.h src/core/Vec2.h src/core/Serpent.h
	$(COMPILER) $(CFLAGS) -c src/txt/AffichageTxt.cpp -o obj/AffichageTxt.o

obj/Jungle.o: src/core/Jungle.cpp src/core/Jungle.h src/core/Arbre.h src/core/Singe.h src/core/Vec2.h src/core/Serpent.h
	$(COMPILER) $(CFLAGS) -c src/core/Jungle.cpp -o obj/Jungle.o

obj/Arbre.o: src/core/Arbre.cpp src/core/Arbre.h src/core/Serpent.h src/core/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/core/Arbre.cpp -o obj/Arbre.o

obj/Serpent.o: src/core/Serpent.cpp src/core/Serpent.h src/core/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/core/Serpent.cpp -o obj/Serpent.o

obj/Singe.o: src/core/Singe.cpp src/core/Singe.h src/core/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/core/Singe.cpp -o obj/Singe.o

obj/Vec2.o: src/core/Vec2.cpp src/core/Vec2.h
	$(COMPILER) $(CFLAGS) -c src/core/Vec2.cpp -o obj/Vec2.o

obj/WinTxt : src/txt/WinTxt.cpp src/txt/WinTxt.h
	$(COMPILER) $(CFLAGS) -c src/txt/WinTxt.cpp -o obj/WinTxt.o

docs: doc/image.doxy
	doxygen doc/image.doxy

clean:
	rm -rf obj/* bin/* doc/html callgrind.out.*
