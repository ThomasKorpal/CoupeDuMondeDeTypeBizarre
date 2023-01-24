CC = gcc
CCFLAGS = -Wall
EXEC = main

all: $(EXEC)

main : Equipe.cc main.cc CoupeDuMonde.cc match.cc Random/fonctions_random.cc personnages/Coach.cc personnages/Joueur.cc personnages/JoueurGold.cc personnages/participant.cc Evenements/Effet.cc Evenements/evenement.cc
	g++ -Wall -o main main.cc match.cc CoupeDuMonde.cc personnages/participant.cc personnages/Joueur.cc personnages/JoueurGold.cc personnages/Coach.cc Random/fonctions_random.cc Equipe.cc Evenements/Effet.cc Evenements/evenement.cc


clean:
	rm -f *.o
mproper:
	rm -f main