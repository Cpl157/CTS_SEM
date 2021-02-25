#include <iostream>

struct Drona {
	float greutate;
	char* model;
};

struct nod {
	Drona info;
	nod* st;
	nod* dr;
};

Drona creareDrona(float g, char* m) {
	Drona d;
	d.greutate = g;
	d.model = (char*)malloc(sizeof(char)*(strlen(m) + 1));
	strcpy(d.model, m);

	return d;
}

void afisareDrona(Drona d) {
	printf("Drona %s are %5.2f kg\n", d.model, d.greutate);
}

nod* inserareInArbore(nod* root, Drona d) {
	if (root) {
		if (d.greutate < root->info.greutate) {
			root->st = inserareInArbore(root->st, d);
		}
		else if (d.greutate > root->info.greutate) {
			root->dr = inserareInArbore(root->dr, d);
		}
		return root;
	}
	else {
		nod* nou = (nod*)malloc(sizeof(nod));
		nou->info = d;
		nou->st = NULL;
		nou->dr = NULL;
		return nou;
	}
}


void afisareRSD(nod* root) {
	if (root) {
		afisareDrona(root->info);
		afisareRSD(root->st);
		afisareRSD(root->dr);
	}
}

Drona cautareDupaGreutate(nod* root, int g) {
	if (root) {
		if (g == root->info.greutate) {
			return root->info;
		}
		else if (g < root->info.greutate) {
			return cautareDupaGreutate(root->st, g);
		}
		else {
			return cautareDupaGreutate(root->dr, g);
		}
	}
	else {
		return creareDrona(-1, "");
	}
}

/*int inaltimeArbore(nod* root) {
	if (root) {
		int hS = inaltimeArbore(root->st);
		int hD = inaltimeArbore(root->dr);
		int h = (hS > hD) ? hS : hD;
		h++;
		return h;
	}
	else return 0;
}*/

int inaltimeArbore(nod* root) { 
    if (root == NULL) 
        return -1; 
    else
    { 
        int lArbore = inaltimeArbore(node->st); 
        int rArbore = inaltimeArbore(node->dr); 
     
        if (lArbore > rArbore) 
            return(lArbore + 1); 
        else return(rArbore + 1); 
    } 
} 


/*void stergereArbore(nod* *root) {
	if (*root) {
		stergereArbore(&(*root)->st);
		stergereArbore(&(*root)->dr);
		free((*root)->info.model);
		free(*root);
		*root = NULL;
	}
}*/

void stergereArbore(nod* *root){  
    if (*root == NULL) return;  
  
    stergereArbore(*root->st);  
    stergereArbore(*root->dr);  
      
    cout << "\n Deleting node: " << *root->info;  
    delete *root; 
}  



void afisareDePeNivel(nod* root, int nivelCautat) {
	if (root) {
		if (nivelCautat == 1) {
			afisareDrona(root->info);
		}
		else {
			nivelCautat--;
			afisareDePeNivel(root->st, nivelCautat);
			afisareDePeNivel(root->dr, nivelCautat);
		}
	}
}

/*nod* cautareMaxim(nod* root) {
	if (root) {
		while (root->dr) {
			root = root->dr;
		}
		return root;
	}
	else return NULL;
}*/

//Functia de a gasi nodul maxim

nod* cautareMaxim(nod* root)
{  
    root current = root; 
    while (current.dr != null)  
        current = current.dr; 
      
    return (current.info); 
} 



Drona extrageDrona(nod* *root, float g) {
	if (*root) {
		if (g == (*root)->info.greutate) {
			Drona rezultat = (*root)->info;
			if ((*root)->dr == NULL) {
				nod* temp = (*root)->st;
				free(*root);
				*root = temp;
			}
			else if ((*root)->st == NULL) {
				nod* temp = (*root)->dr;
				free(*root);
				*root = temp;
			}
			else {
				nod* temp = cautareMaxim((*root)->st);
				Drona aux = temp->info;
				temp->info = (*root)->info;
				(*root)->info = aux;
				return extrageDrona(&(*root)->st, g);
			}

			return rezultat;
		}
		else if (g < (*root)->info.greutate) {
			return extrageDrona(&(*root)->st, g);
		}
		else {
			return extrageDrona(&(*root)->dr, g);
		}
	}
	else {
		return creareDrona(-1, "");
	}
}

void main() {
	nod* root = NULL;

	root = inserareInArbore(root, creareDrona(7, "Phantom"));
	root = inserareInArbore(root, creareDrona(5, "Vampir"));
	root = inserareInArbore(root, creareDrona(3, "SkyDrive"));
	root = inserareInArbore(root, creareDrona(10, "SkyWalk"));
	root = inserareInArbore(root, creareDrona(8, "Phantom II"));
	root = inserareInArbore(root, creareDrona(9, "Drone Sky"));
	root = inserareInArbore(root, creareDrona(12, "OnTheSky"));

	afisareRSD(root);
	printf("\n");

	extrageDrona(&root, 10);
	afisareRSD(root);

	stergereArbore(&root);
}