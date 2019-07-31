Some interesting text mining features like the tries data structures.

In order to run the code:

	$ mkdir build && cd build && cmake ..
	$ make

To lauch the tests suite (at the root of the repo):
	$ test/test.sh

QUESTIONS:
	1 - 

	2 - Nous avons créé une tests suite comprenant des tests sur le mot testé, la distance et aussi sur le mode d'entrée des tests (echo, cat , ...)
	
	3 - 
	
	4 - 
	
	5 - En ajoutant des outils d'analyse contextuel, un réglage automatique de la distance pourrait être mise en place: un exemple simple serait de dire
		que des mots avec une distance importantes par rapport au mot testé mais avec une similarité importante pourrait être retourné par le programme
		avec des mots ayant une distance beaucoup moins importante mais avec une similarité bien inférieure.

	6 - Afin d'améliorer les performances de notre programme, nous pourrions dans un premier temps utiliser un Patricia Trie au lieu de notre Trie actuel. 
		Ensuite, nous pourrions nettement améliorer nos performances de (dé)serialisation en utilisant des transformation de Trie vers des structures de type
		Judy Array par exemple. Cela améliorerait d'une part la rapidité de notre programme, mais aussi la mémoire utilisée par celui-ci. 
	
	7 -