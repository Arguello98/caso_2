# caso_2
Quicksort
para el experimento del comportamiento logaritmico se recorrio un arreglo ordenado de menor a mayor eligiendo como pivote siempre el elemento que se encontraba en el medio
se realizo para diferentes tamaños de arreglos 2000,3000,4000,5000 y se tomaron los tiempos que duraba en ejecurtarse en mircosegundos usando la libreria de chrono

	-----------------------------------------
	| 	|   1	|   2	|   3 	|   4 	|
	-----------------------------------------
	| 2000	| 500.6	|   0	| 500.7	|   0	|
	-----------------------------------------
	| 3000	|   0	| 500.6	|   0	| 501.3	|
	-----------------------------------------
	| 4000	| 501.7	| 500.3	| 499.4	| 499.6	|
	-----------------------------------------
	| 5000	| 540.8	| 500.5	| 500.5	| 499.8	|
	-----------------------------------------

	se puede observar que el tiempo de ejecucion no varia mucho entre los tamaños del arreglo

Para el experimento del comportamiento cuadratico se recorrrio un arreglo ordenado de mayor a menor eligiendo como pivote el primer elemento del arreglo,
se realizo para diferentes tamaños de arreglos 2000,3000,4000,5000 y se tomaron los tiempos en microsegundos usando la libreria chrono

	-------------------------------------------------------------------------
	| 	|	1	|	2	|	3	|	4	|
	-------------------------------------------------------------------------
	| 2000	|    8506.6	|    8614.6	|    8007.5	|   8005.8	|
	-------------------------------------------------------------------------
	| 3000	|   18015.3	|   19409.2	|   18515.6	|  22519	|
	-------------------------------------------------------------------------
	| 4000	|   32027.5	|   33028.7	|   34028.2	|  33530.7	|
	-------------------------------------------------------------------------
	| 5000	|   49042.5	|   50543.2	|   70560.5	|  51543.2	|
	-------------------------------------------------------------------------

	Se puede observar que a medida que aumenta el tamaño de la entrada tambien incrementa rapidamente el tiempo de ejecucion

Para la ultima parte donde se comparan los tiempos de ejecucion entre el pivote fijo o aleatorio con arreglos de
tamaño 2000,3000,4000,5000 conteniendo numeros aleatorio se presentan los siguientes resultados.


	-------------------------------------------------------------------------
	| 	|	F1	|	A1	|	F2	|	A2	|
	-------------------------------------------------------------------------
	| 2000	|    500	|     500.5	|     500.2	|     398.7 	|
	-------------------------------------------------------------------------
	| 3000	|    500.3	|     500.4	|     500	|     1001	|
	-------------------------------------------------------------------------
	| 4000	|    500.3	|     1000.6	|     602.2	|    1000.4	|
	-------------------------------------------------------------------------
	Se puede observar que el tiempo de ejecucion del pivote fijo se mantiene cerca de los 500 micro segundos a lo largo de las ejecuciones
	pero en el caso del pivote aletario el tiempo de ejecuccion puede ser menor o mayor que el fijo

Insertion sort
para los casos del insertion sort lineal y cuadratico se realizo el experimento con arrelgos de tamaño 20000,30000,40000,50000
los cuales estaban en el caso del lineal ordenados de menor a mayor y en el caso del cuadratico de mayor a menor 

**Para el caso de la medio de tiempo en milli segundos del insertion sort la mayoria de resultados dan 0 por la velocidad a la que se hacen, pero teniendo en cuenta que la lista ya se encuentra ordenada el recorrido del for es se realiza por el tamaño del arreglo


	Lineal
	-----------------------------------------
	| 	|   1	|   2	|   3 	|   4 	|
	-----------------------------------------
	| 20000	|   0	|  0.500|   0 	|   0	|
	-----------------------------------------
	| 30000	|   0	|   0	|   0	| 0.501	|
	-----------------------------------------
	| 40000	| 0.500 |   0 	| 0.499	|   0	|
	-----------------------------------------
	| 50000	| 0	| 0.500	|   0	| 0.500 |
	-----------------------------------------
	
	Cuadratico
	-------------------------------------------------------------------------
	| 	|	1	|	2	|	3	|	4	|
	-------------------------------------------------------------------------
	| 2000	|    1145.98	|    1151.49	|    1148.49	|   1152.99	|
	-------------------------------------------------------------------------
	| 3000	|   2592.73	|   2578.21	|   3301.33	|   2567.7	|
	-------------------------------------------------------------------------
	| 4000	|   4539.9	|   4586.94	|   4529.39	|  5899.06	|
	-------------------------------------------------------------------------
	| 5000	|   7173.66	|   7094.59	|   7127.62	|  7119.61	|
	-------------------------------------------------------------------------

	Se puede observar que el tiempo de ejecucion del algoritmo en el caso lineal no crece mucho o a penas es notable el cambio en el tiempo de ejecucion
	En cambio en el de comportamiento cuadratico a medida que se aumentaba en 10000 el arreglo tambien aumentaba considerablemente el tiempo que tardaba en realizar el ordeamiento

Para el caso del free text search, se implemento un algoritmo encontrado en https://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
en el cual se hace un arbol de los sufijos de las palabras que aparecen en el texto y se tiene una lista de las apariciones de las palabras

un ejemplo ignorando donde los hijos son nulos para el dibujo, si se inserta la palabra "carro y casa"
		
  						  [a]     	          [c]          [r]  		   [s]	[o]
						  / \	           	 / 	       / \		  / 
						[s] [r]	              [a] 	     [r] [o]           [a]
						/   /\		      / \             \
					      [a] [r][o]	  [s]   [r]           [o]
   						  /              /     / \ 
						[o]            [a]   [r] [o]
						                     /
						                   [o]

	-------------------------------------------------------------------------
	| 	|	1	|	2	|	3	|	4	|
	-------------------------------------------------------------------------
	| Lorem	|      	0	|    0		|      0	|      0	|
	-------------------------------------------------------------------------
	| ipsum	|       0	|   0.5006	|      0	|      0	|
	-------------------------------------------------------------------------
	| dolor	|    0.5009	|   0		|      0	|      0	|
	-------------------------------------------------------------------------
	| algo	|      	 0	|   0		|      0	|  0.5004	|
	-------------------------------------------------------------------------

	en los casos donde el tiempo es 0 es por que el tiempo en el que se realiza la busqueda es menor que el que puede registrarse con la libreria chrono
	pero se puede apreciar que al ser un arbol indexado por las letras los tiempos de busqueda no varian mucho entre una palabra y otra 