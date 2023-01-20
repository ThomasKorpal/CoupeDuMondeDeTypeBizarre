CC = gcc
CCFLAGS = -Wall
EXEC = main

all: $(EXEC)

main : Equipe.cc main_test.cc match.cc Random/fonctions_random.cc personnages/Coach.cc personnages/Joueur.cc personnages/JoueurGold.cc personnages/participant.cc Evenements/Effet.cc Evenements/evenement.cc
	g++ -Wall -o main main_test.cc match.cc personnages/participant.cc personnages/Joueur.cc personnages/JoueurGold.cc personnages/Coach.cc Random/fonctions_random.cc Equipe.cc Evenements/Effet.cc Evenements/evenement.cc


clean:
	rm -f *.o
mproper:
	rm -f main