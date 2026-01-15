# TicTacToe

Programmed in C Terminal-version

3 options:

    player versus player
    player versus easy AI
    player versus impossible AI

For this project, I implemented a simple gameloop, with a display in the terminal. I used miniMax algorithm to create an impossible-to-beat AI (the player can either draw or lose, not win against it). MiniMax allowed to explore each and every move, evaluating them to select the best option on each turn. I decided to optimize it with alphabeta pruning. After comparing the number of operations for both algorithm, I found a significant difference. Alphabeta does not explore the branches that lead to moves that will not be selected anyway.


# Morpion

Programmé en C Jouable dans le terminal

3 possibilités :

    joueur contre joueur
    joueur contre ordinateur facile
    joueur contre ordinateur difficile

Ce projet m'a permis d'implémenter une boucle de jeu simple, en gérant l'affichage dans le terminal. Je me suis servie de l'algorithme miniMax pour créer une IA imbattable. Minimax me permet d'explorer chaque coup possible, d'évaluer ceux menant à une victoire et de choisir le meilleur coup, à chaque tour. C'est un algorithme gourmand, c'est pourquoi j'ai choisi de l'optimiser avec l'élagage. J'ai pu comparer le nombre d'opérations de chaque algorithme et constater une différence importante. Alphabeta n'explore pas les branches menant à des options qui ne seront de toute manière pas sélectionnées.
