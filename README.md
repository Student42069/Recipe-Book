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
* `main.h`: interface Le main
* `main.c`: code source Le main
* `linkedList.h`: interface La liste chainée
* `linkedList.c`: code source La liste chainée
* `stats.h`: interface La gestion des statistiques
* `stats.c`: code source La gestion des statistiques
* `tests.h`: interface Les tests
* `tests.c`: code source Les tests

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

Exemple de banque de données :
```sh
Poulet au romarin [poulet] [bbq]
Boeuf au satay [boeuf] [asiatique]
Salade du jardin [vegetarien]
Poulet crapaudine [poulet]
Pho [soupe] [asiatique]
Authentique gibelotte des iles de Sorel [soupe] [poisson] [terroir]
```

Pour exécuter le programme avec une des recette contenu dans un fichier :
```sh
./recherche <FICHIER_TEXTE>
Entrez votre critère de recherche : POULET
Poulet au romarin
Poulet crapaudine.
Entrez votre critère de recherche : poulet crapaud
Poulet crapaudine.
Entrez votre critère de recherche : Salami
Catégorie inexistante.
```

Les cas d'erreur gérés sont :

1. Fichier non trouvé

## Tests

Entrez `make test` pour exécuter la suite de tests automatiques.

Mes résultats:
```sh
```
Les  tests réussissent.

## Dépendances

* [GCC](https://gcc.gnu.org/)
* [Make](https://www.gnu.org/software/make/manual/make.html)

## Références

* [GitLab CI/CD](https://docs.gitlab.com/ee/ci/)
* [GitLab Flavored Markdown](https://docs.gitlab.com/ee/user/markdown.html)
* [Inclusion guards of standart libraries](https://stackoverflow.com/a/25361340)
* [Inclusion guards my modules](https://stackoverflow.com/a/5128719)
* [fopen()](hhttps://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm)