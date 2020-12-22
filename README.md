# Space Outvaders
Space Outvaders est un projet de première année donné a l'IUT Informatique d'Aix-en-Provence.  
Le but est d'améliorer un Space Invaders déjà existant en CLI afin de le rendre plus attractif auprès du joueur.

## Usage

### Pré-requis
Ce projet a été fait sur Qt Creator, il vous sera donc nécessaire de l'avoir installé avant toute chose.

**Attention**, la seule compatibilité de ce programme est avec Linux.
Il est possible de le compiler sous macOS en installant *freeglut* via brew, et en changeant l'emplacement des bibliothèques dans le fichier de projet.  
**Enfin**, il vous faudra GCC 8.2+ ou Clang 6.0+ pour compiler ce projet.

### Compilation
Il vous suffit simplement de cloner ce repo:
```sh
git clone git@github.com:Kuruyia/SpaceOutvaders.git
```
Puis, ouvrir le fichier *.pro* avec Qt Creator, configurer le projet et cliquer sur le bouton d'exécution du programme.

## Documentation
Toute la documentation du code peut être trouvée [dans ce lien](https://kuruyia.net/invaders/doc/).

## Fonctionnalités ajoutées
- **Passage d'une CLI vers une GUI**: Le jeu a été très fortement modifié afin d'intégrer une interface graphique en lieu et place de l'usage du terminal.
Pour ceci, nous utilisons la bibliothèque fournie par les professeurs, *minGL*, que nous avons fortement modifiée.
- **Système d'événements utiliasteur**: Un gestionnaire d'événement a été ajoutée sur minGL afin de pouvoir traiter
les entrées clavier et souris sans interrompre le cours du jeu.
Cela permet de faire des menus cliquables a la souris, ainsi que de déplacer le joueur dans le jeu.
- **Gestion d'images**: Un format d'image a été créé afin de stocker des pixels sous la forme RGBA,
afin de ne pas avoir a charger une grosse bibliothèque pour utiliser un format plus complexe et avoir des graphismes plus poussés.
- **Séparation des écrans**: Chaque écran est séparé dans le code afin de ne pas avoir un gros fichier qui gère tout les états du jeu.
- **Score et configuration**: Un système de score est en place, il dépend du nombre d'ennemis touchés et du nombre de vie lors d'une victoire.
La configuration permet de changer ses touches et la difficulté du jeu.
Ces deux propriétés sont persistantes entre deux lancement du programme car sauvegardées sur le disque.
- **Difficulté et vies**: Un système de difficulté a été ajouté afin de pouvoir rajouter du challenge.
Les difficultés peuvent multiplier les fréquences du jeu pour le modifier sa vitesse générale, mais aussi donner un bonus de score et changer le nombre de vies.
Un système de vie a aussi été ajouté, le joueur perd une vie a chaque fois qu'il est touché et perd si il n'en a plus.
- **Animation de l'interface**: Un moteur de transition est présent dans le jeu afin de pouvoir animer des éléments de l'interface utilisateur facilement.
Cela permet d'être plus attrayant a l'oeil du joueur. Un exemple flagrant de ce moteur est le titre principal du menu titre.

## Captures d'écran
![Menu titre](https://i.imgur.com/XCIUr71m.png)
![En jeu](https://i.imgur.com/QP9q7eym.png)

## Remerciements
- Les membres de mon équipe qui ont contribués a ce projet, leurs noms sont présents dans leurs fichiers respectifs
- Les professeurs de l'IUT pour la base de minGL ainsi que leur critique sur ce code
