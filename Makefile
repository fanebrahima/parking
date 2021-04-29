CC=gcc

executer: compiler
	./parking
	
compiler: camion.c vehicule-classic.c engin_deux_roues.c parking.c
	$(CC) camion.c vehicule-classic.c engin_deux_roues.c parking.c -o parking -lmysqlclient -lm


