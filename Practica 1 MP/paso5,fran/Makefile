all: bin/principal
obj/punto.o: src/punto.cpp include/punto.h
	g++ -c -o obj/punto.o -Iinclude src/punto.cpp

obj/circulo.o: src/circulo.cpp include/circulo.h
	g++ -c -o obj/circulo.o -Iinclude src/circulo.cpp

obj/utilidades.o: src/utilidades.cpp include/utilidades.h
	g++ -c -o obj/utilidades.o -Iinclude src/utilidades.cpp

lib/libformas.a: obj/punto.o obj/circulo.o obj/utilidades.o
	ar rvs lib/libformas.a obj/punto.o obj/circulo.o obj/utilidades.o

obj/principal.o: src/principal.cpp include/punto.h include/circulo.h include/utilidades.h
	g++ -c -o obj/principal.o -Iinclude src/principal.cpp

bin/principal: obj/principal.o lib/libformas.a
	g++ -Llib/ -o bin/principal obj/principal.o -lformas

clean:
	echo "Limpiando..."
	rm obj/*.o lib/lib*.a

mrproper: clean
	rm bin/principal
