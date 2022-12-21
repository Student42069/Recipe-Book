# TP3: Liste chainée, CUnit et modules


## Description

Le logiciel est lancé à la console en recevant en paramètre un nom de fichier.
Le fichier contiendra la banque de recettes dans laquelle nous effectuerons 
les recherches. Chaque ligne du fichier doit contenir une recette avec les 
catégories dans lesquelles elle doit apparaître. Une recette est obligatoirement 
dans une catégorie mais pourrait aussi apparaître dans plusieurs catégories. Les
catégories apparaissent entre crochets, après le nom de la recette.

Travail accompli dans le contexte du cours 
Construction et maintenance de logiciels (INF3135) donnee par Serge Dogny à
l'UQAM.

Le contenu du projet:

* `README.md`: ce fichier
* `Makefile`: permet d'automatiser la compilation
* `.gitignore`: ignorer certains fichiers lors de la gestion des version
* `.gitla-ci.yml`: instructions d'intégration continu avec GitLab CI/CD
* `sujet.pdf`: sujet du travail
* `/test_files`: dossier contenant des fichiers de recettes
* `central.h`: interface main()
* `main.h`: code source main()
* `main.h`: interface des methodes principales du programme
* `main.c`: code source es methodes principales du programme
* `linkedList.h`: interface liste chainée
* `linkedList.c`: code source liste chainée
* `stats.h`: interface gestion des statistiques
* `stats.c`: code source gestion des statistiques
* `tests.h`: interface des tests
* `tests.c`: code source des tests

[Contraintes du travail](sujet.pdf)

## Auteur

Leonid Glazyrin (GLAL77080105)

## Fonctionnement

Pour faire fonctionner le projet il vous faudra vous assurez d'avoir `git`
installé, ainsi que `make`. Referez vous à la section [Dépendances](#dépendances) 
pour les sites officiels.

Tout d'abord cloner le projet avec la commande :
```sh
git clone https://gitlab.info.uqam.ca/glazyrin.leonid/inf3135-automne2022-tp3.git
```
Si le projet n'est pas publique vous devrez vous authentifier.

Ensuite exécuté les commandes suivantes pour vous déplacer dans le répertoire, 
compiler le programme:
```sh
cd inf3135-aut2022-tp3
make
```

Pour exécuter le programme avec une des recette contenu dans un fichier :
```sh
./recherche <FICHIER_TEXTE>
Entrez votre critère de recherche : <CATEGORIE> [MOT-CLE]
```
`exit` pour arreter le programme normalement.

Pour exécuter le programme et generer des statistiques sur les recettes fournie en parametres :
```sh
./recherche <FICHIER_TEXTE> -S <FICHIER OU ECRIRE LES STATISTIQUES>
```

Les cas d'erreur gérés sont :

1. Fichier non trouvé

Les cas d'erreur non-gérés connus sont :

1. Si le fichier de recettes se termine par plus d'un '\n'
2. Si seulement '\n' est entree au clavier
3. Si le fichier est vide, la lettre la plus frequente sera 'a'

## Tests

Entrez `make test` pour exécuter la suite de tests automatiques.

Mes résultats:
```sh
Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      2      2    n/a      0        0
               tests     12     12     12      0        0
             asserts     41     41     41      0      n/a

Elapsed time =    0.000 seconds
```
Tout les  tests réussissent.

## Supprimer les fichiers generes

Entrez `make clean` pour supprimer tout fichier genere.

## Verifier les fuites de memoire

Entrez `make valgrind` pour executer un test qui verifiera les fuites de memoire,
l'interaction de l'utilisateur ne sera pas necessaire pour cette execution.

## Dépendances

* [GCC](https://gcc.gnu.org/)
* [Make](https://www.gnu.org/software/make/manual/make.html)
* [Valgrind](https://valgrind.org/)
* [CUnit](https://cunit.sourceforge.net/)

## Références

* [GitLab CI/CD](https://docs.gitlab.com/ee/ci/)
* [GitLab Flavored Markdown](https://docs.gitlab.com/ee/user/markdown.html)
* [Inclusion guards of standart libraries](https://stackoverflow.com/a/25361340)
* [Inclusion guards my modules](https://stackoverflow.com/a/5128719)
* [fopen()](hhttps://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm)
* [Linked list in C](https://www.scaler.com/topics/c/linked-list-in-c/)
* [Free nodes in linked list](https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list)
* [Read full line from command line](https://stackoverflow.com/a/6282236)