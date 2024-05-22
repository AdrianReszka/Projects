
#############################
# Generator plikow makefile #
# Krzysztof Siminski, 2022  #
#############################

# STALE:
kompilator=g++
standard=-std=c++20

optRelease=-O3
optDebug=

errors=-pedantic-errors

release=
debug=-g

#rownoleglosc=-fopenmp
rownoleglosc=

release_folder=_release
debug_folder=_debug

#############################

.PHONY : clean $(debug_folder) $(release_folder)

# opcje uruchomienia projektu:

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main
	
	./$(release_folder)/main -g plik.txt -e plik-z-cyklami
	./$(release_folder)/main -e plik-z-cyklami -g plik.txt
# niepoprawne
	./$(release_folder)/main -q plik-z-grafem -e plik-z-cyklami
	./$(release_folder)/main -g plik-z-grafem 
	./$(release_folder)/main -g plik-z-grafem -g plik-z-grafem -e plik-z-cyklami
	./$(release_folder)/main -g plik-z-grafem -e
	./$(release_folder)/main -g plik-z-grafem plik-z-cyklami -e
	
	



	
	

debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# kompilacja zrodel:

$(release_folder)/Cykl.o : Cykl.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/Cykl.o : Cykl.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/Funkcje.o : Funkcje.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/Funkcje.o : Funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^

# linkowanie:

$(release_folder)/main : $(release_folder)/Funkcje.o $(release_folder)/Cykl.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : $(debug_folder)/Funkcje.o $(debug_folder)/Cykl.o 
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;


