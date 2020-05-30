# Ce makefile permet de gérer plus facilement l'execution d'un jeu réalisé avec la librairie SFML
# Usage : 
# 		make compile (Compile le jeu, ici une archive est réalisée) 
# 		make clean (Retire l'archive)
# 		make run (Compile le jeu puis l'execute)
# 		make all (Execute clean puis compile)
# 		make play(Execute compile, run)	


compile:
	# Compilation du code source C++
	@echo "Compilation des sources"
	g++ -c main.cpp
	
	# Création de l'executable 
	@echo "Création de l'executable"
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	
run:	compile
	# Pour l'executer il suffit ensuite de lancer la commande love en utilisant le nom de cette archive
	@echo "Lancement de l'application SFML"
	./sfml-app

play: 	run

clean:	
	# Lorsque l'on appelle le clean ce que l'on souhaite c'est retirer la dernière archive de jeu
	@echo "Retrait des fichiers compilés"
	rm -f main.o sfml-app


