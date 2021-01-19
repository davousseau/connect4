# Puissance 4
```
Player X action: 

  1 2 3 4 5 6 7 
|               |
|               |
|       X       |
|     X O       |
| O X O X       |
| X X O O       |
-----------------

Player X wins!
```

## Auteur
[David Brousseau](mailto:dbrsseau@gmail.com)

## Contexte académique
Projet effectué dans le cadre du cours **INF3135 Construction et maintenance de logiciels**, remis à l'enseignant **Alexandre Terrasa** à l'[Université du Québec à Montréal](https://etudier.uqam.ca/) le 26 septembre 2018. Ce projet a été retranscris en janvier 2021 pour le rendre public et l'insérer dans mon porte-folio.

## Description
Adaptation du jeu [Puissance 4](https://fr.wikipedia.org/wiki/Puissance_4) en C pour y jouer dans un terminal linux. À noter que l'implémentation est à sa forme la plus simple et que les deux joueurs doivent se partager le même clavier.

## Environnement suggéré
- [VS Code](https://code.visualstudio.com/), éditeur de texte pour modifier le code.
- [C/C++ Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), extension du language C réservé à l'usage de VS Code.
- [TODO Highlight](https://marketplace.visualstudio.com/items?itemName=wayou.vscode-todo-highlight), extension d'affichage des TODOs réservé à l'usage de VS Code.
- [Doxygen](https://www.doxygen.nl/index.html), outil pour générer la documentation automatique.
- [Valgrind](https://www.valgrind.org/), outil pour vérifier qu'il n'y a pas de fuites de mémoire.

## Installation
`make`, compile le jeu.<br>
`make doc`, génère la documentation du projet. **(requiert Doxygen)**<br>
`make memcheck`, vérifie qu'il n'y a pas de fuites de mémoire. **(requiert Valgrind)**<br>
`make test`, exécute une série de tests.<br>
`make clean`, supprime les fichiers compilés.

## Compatibilité
Testé sous un environnement **Linux seulement**.

## Fonctionnement
TODO:

## Références
- [Bash Reference Manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)
- [Doxygen manual](http://cs.swan.ac.uk/~csoliver/ok-sat-library/internet_html/doc/doc/Doxygen/1.7.6.1/html/config.html)
- [Valgrind User Manual](https://www.valgrind.org/docs/manual/manual.html)