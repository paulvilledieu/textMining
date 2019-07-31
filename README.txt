Some interesting text mining features like the tries data structures.

In order to run the code:

	$ mkdir build && cd build && cmake ..
	$ make

To execute the tests suite (at the root of the repo):
	$ test/test.sh


Notre programme fonctionne sur la majorité des tests, les seuls problèmes que nous avons rencontrés sont certaines lectures sur stdin.
Comme par exemple la redirection d'un fichier avec cat, dans notre programme produit un comportement indéfini la plupart du temps.


QUESTIONS:

	1 - On a décidé de créer une classe Trie pour faciliter l'utilisation des méthodes sur notre structures de données. On a aussi crée un fichier qui contient les algorithmes pour calculer des distances sur notre Trie. Enfin on a stocké les deux mains pour créer les deux binaires dans un dossier bin pour le séparer de notre logique.

	2 - Nous avons créé une tests suite comprenant des tests sur le mot testé, la distance et aussi sur le mode d'entrée des tests (echo, cat, ...)
	
	3 - Non
	
	4 - Nous avons utilisé une structure de type TRIE car elle était assez simple à mettre en place et elle permet d'avoir de bonnes performances pour tout
		ce qui est stockage de mot avec des fréquences données
	
	5 - En ajoutant des outils d'analyse contextuel, un réglage automatique de la distance pourrait être mise en place: un exemple simple serait de dire
		que des mots avec une distance importantes par rapport au mot testé mais avec une similarité importante pourrait être retourné par le programme
		avec des mots ayant une distance beaucoup moins importante mais avec une similarité bien inférieure.

	6 - Afin d'améliorer les performances de notre programme, nous pourrions dans un premier temps utiliser un Patricia Trie au lieu de notre Trie actuel. 
		Ensuite, nous pourrions nettement améliorer nos performances de (dé)serialisation en utilisant des transformation de Trie vers des structures de type
		Judy Array par exemple. Cela améliorerait d'une part la rapidité de notre programme, mais aussi la mémoire utilisée par celui-ci. 
	
	7 - Il faudrait que l'on prenne en compte le contexte avec par exemple des algorithmes de reinforcement learning ou des N-grams embedding.
	https://arxiv.org/pdf/1710.07045v1.pdf
