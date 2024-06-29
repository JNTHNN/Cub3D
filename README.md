# Cub3D

## Parsing

*To do*
1. Checker le format (.cub) de la map passée en argument
2. Map composée de 6 caracteres :
	1. 0 pour les espaces vides
	2. 1 pour les murs
	3. N, S, E, W pour representer la position de départ du joueur + orientation(vue)
3. La map doit etre fermée/entourée de murs sinon -> retourne erreur
4. Chaque type d'element peut etre séparée par une/plusieurs lignes vides
5. La description de la map est toujours en dernier, les reste des elements peuvent etre dans le désordre
6. Chaque element de la map peuvent etre séparées par un/plusieurs espaces
7. probleme de config ? -> Retourner "Error\n" + un message explicite au choix (dans STDERR)

### Exemple de map

```
NO ./path_to_the_north_texture // texture Nord | ID : NO | chemin vers la texture
SO ./path_to_the_south_texture // texture Sud | ID : SO | chemin vers la texture
WE ./path_to_the_west_texture // texture ouest | ID : WE | chemin vers la texture
EA ./path_to_the_east_textur // texture Est | ID : EA | chemin vers la texture
F 220,100,0 // Couleur Sol | ID : F | Couleur R,G,B range [0,255]
C 225,30,0 // Couleur Plafond | ID : C | Couleur R,G,B range [0,255]

Cub3D Mon premier RayCaster avec la minilibX
— Couleur du plafond :
C 225,30,0
— identifiant : C
— couleurs R,G,B range [0,255] : 0, 255, 255

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111 // position du joueur orienté au Nord
11110111 1110101 101111010001
11111111 1111111 111111111111
```

#### Fonctions autorisées

• open, close, read, write,
printf, malloc, free,
perror, strerror, exit
• Toutes les fonctions de
la lib math (-lm man man 3
math)
• Toutes les fonctions de la
MinilibX

### Conventions

y = ordonée / x = abscisse -> map[y][x]
Bug traduction ou de la mer*e -> "error\n" puis msg
A voir si error si plusieurs lignes de la meme info

## TO-DO

atoi uint8_t pour les couleurs + check wrong input -> DONE
erreur si une donnee en trop quand le reste est init ? -> DONE
atoi actuellement accepte les negatifs et les refacto entre 0 et 255 -> DONE
pb quand la 1ere ligne commence par 0 -> DONE
ajouter info dans data ?
verifier les .h
normer
check leaks
static

## Parsing

Checker la premiere ligne n'a que des 1(murs)
les lignes suivantes doivent commencer/finir par 1
Si la ligne est plus grande que prev et suiv -> verifier aux niveaux des 0 si au dessus/dessous il y a des murs ou 0
Remplacer les vides par 2 pour differencier avec les murs


## Liens utiles
https://harm-smits.github.io/42docs/projects/cub3d
http://www.proftnj.com/RGB3.htm