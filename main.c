#include <stdio.h>
#include <string.h>


int main (void) { 

  FILE *fp;
  int choix, id[10];
  char c, prenom[10], nom[10], email[30], tel[10];
  int count, i, codeId;
  
  fp = fopen("repertoire.txt", "a+");
  	
   if (fp == NULL) { 
    printf("[!] Erreur fichier introuvable"); 
    return 0; 
   } 

   for(c = getc(fp); c != EOF; c = getc(fp)) { 
   		if (c == '\n') { 
   			count = count++; 
   		}
   } 

  while(i != 1) {

  	printf("===================== MENU =========================\n (1) - Afficher le repertoire\n (2) - Ajouter une personne au repertoire\n (3) - Rechercher une personne dans le repertoire\n (4) - Supprimer une personne du repertoire\n (5) - Supprimer tout le repertoire\n (6) - Quitter\n====================================================\n");
  	scanf("%d", &choix);	

  	if(choix == 1) {
  		
  	  	printf("==================== REPERTOIRE ====================\n");
	  	
	  	for (i=0; i<count; i++) {
  		
			fscanf(fp, "%d %s %s %s %s", &id[i], &nom[i], &prenom[i], &tel[i], &email[i]); 
		
			printf("%d", id[i]);
  	  		printf(" %s", nom);
  	  		printf(" %s", prenom);
  	  		printf(" %s", tel);
  	  		printf(" %s\n", email);
  	  	
	  	}
	 
	 	printf("====================================================\n\n\n");
	 
  	}
  	   
  	if(choix == 2) {
  	
  		printf("============== AJOUT D\'UN UTILISATEUR ==============\nIdentifiant: ");
  		scanf("%d", &id);
  	
		printf("Nom : ");
  		scanf("%s", &nom);
  	
		printf("Prenom : ");
  		scanf("%s", &prenom);
  	
		printf("Telephone : ");
  		scanf("%s", &tel);
  	
		printf("Email : ");
  		scanf("%s", &email);
  		printf("====================================================\n\n\n");
  		
  		fprintf(fp, "%d    %s    %s    %s    %s", id, nom, prenom, tel, email);
	
  	}
  
  	if(choix == 3) {
  
  		for (i=0; i<count ; i=i++) {
			fscanf(fp, "%d %s %s %s %s", &id[i], &nom[i], &prenom[i], &tel[i], &email[i]); 
  		}
	  
		printf("Saisir un l\'identifiant d\'une personne : ");
		scanf("%d", &codeId);
	  
		printf(" %s\n\n\n", nom[codeId-1]);  
	  
  	}
  
  	if(choix == 4) {
  		i = 1;
 	}
 	
 	if(choix == 5) {
 		int c;
  		printf("[!] Etez-vous sure de vouloir vider le repertoire ? \n\n   - (1) -> OUI\n   - (0) -> NON\n\n");
  		scanf("%d", &c); 
  		if(c == 1) {
  			fclose(fopen("repertoire.txt", "w"));
		}
 	}
 	
 	if(choix == 6) {
  		i = 1;
 	}
  
  }
  
  fclose(fp);
  return 0;
  
}
