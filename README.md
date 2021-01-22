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

## Compatibilité
Testé sous un environnement **Linux seulement**.

## Dépendances
- [GCC, the GNU Compiler Collection](https://gcc.gnu.org/), compilateur pour le language C/C++.
- [Doxygen <sup>*</sup>](https://www.doxygen.nl/index.html), outil pour générer la documentation automatique.
- [Valgrind <sup>*</sup>](https://www.valgrind.org/), outil pour vérifier qu'il n'y a pas de fuites de mémoire.

_<sup>*</sup> Dépendances optionnelles selon votre utilisation._

## Environnement suggéré
- [VS Code](https://code.visualstudio.com/), éditeur de texte pour modifier le code.
    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), extension pour le language C/C++.
    - [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format), extension pour le formatage du code.
    - [Doxygen Documentation Generator](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen), extension pour générer la documentation.
    - [TODO Highlight](https://marketplace.visualstudio.com/items?itemName=wayou.vscode-todo-highlight), extension pour afficher les TODOs.

## Installation
`make`, compile le jeu.<br>
`make doc`, génère la documentation du projet.<br>
`make memcheck`, vérifie qu'il n'y a pas de fuites de mémoire.<br>
`make test`, exécute une série de tests.<br>
`make clean`, supprime les fichiers compilés.

## Fonctionnement
TODO:

## Références
- [Bash scripting cheatsheet](https://devhints.io/bash)
- [How to Change the Color of your Linux Prompt](https://linuxhostsupport.com/blog/how-to-change-the-color-of-your-linux-prompt/)
