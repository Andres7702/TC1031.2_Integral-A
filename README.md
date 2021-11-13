# TC1031.2_Integral-A

Este programa es un manejador del personal y estudiantes de una escuela. 
El usuario podra creear varias listas doblemente ligadas donde cada una tendra sus propios estudiantes. Los estudiantes se comportan como nodos de una lista, 
pero ademas de esto tambien tienen sus propios atributos como nombre, grado, ID y calificaciones. 
Ademas de esto el programa tambien tiene una estructura de un arbol AVL que guarda objetos de tipo Maestro. Los objetos Maestro se comportan como nodos de un
AVL pero ademas de esto tambien tienen atributos propios como nombre, ID, grado que enseñan y materia que enseñan.
El usuario podra agregar, eliminar y consultar los datos de cada una de las personas que se encuentren dentro de estas estructuras.


# SICT0302B: Toma decisiones

Selecciona y usa una estructura lineal adecuada al problema:
Para este problema utiliza un lista doblemente ligada, ya que esto me permitiria acceder a los elementos de una forma mas rapida, ademas que
me permite hacer un sort dentro de esta lista.

Selecciona un algoritmo de ordenamiento adecuado al problema:
Para el problema utiliza un algoritmo del tipo bubble sort. Escogi este algoritmo por que la lista se acomoda automaticamente cada vez que 
agregamos un estudiante nuevo, esto significa que el bubble sort solo tendra que recorrer la lista una vez ya que todo hasta ese nuevo elemento
ya esto ordenado.

Usa un árbol adecuado para resolver un problema: Escogi un arbol de tipo AVL para guardar mi estructura de maestros ya que, a diferencia de los estudiantes, 
los maestros no se dividen por grupos mas chicos. En caso de tener cientos de maestros, el guardarlos en una lista podria llegar a ser tardado, por lo que
mejor los implemente en un arbol AVL para tener un acceso mas rapido a ellos.


# SICT0301B: Evalúa los componentes

Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa:

Los casos de pruebas para todas las funciones se encuentran en "casos_de_prueba.hpp" donde se prueban las funciones de:

    El ordenamiento de los elementos en la lista doblemente ligada de estudiantes.

    La modificacion de un elemento de la lista de estudiantes (Calificaciones).
    
    Eliminar un elemento de la lista de estudiantes.
    
    Impresion de Lista de estudiantes completa.
    
    Impresion de un estudiante en particular, buscandolo en la lista por medio de su ID.
    
    Agregar un elemento al arbol de Maestros.
    
    Eliminar un elemento del arbol de Maestros. 
    
    Impresion de arbol de Maestros completo.
    
    Impresion de un Maestri en particular, buscandolo en el arbol por medio de su ID.
    
    
Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes:

    La lista doblemente ligada tendra una complejidad de 0(n) en su peor de los casos, ya que tendria que recorrer la lista completa para agregar
    un elemento al final. Y en el mejor de sus casos 0(1) ya que no tendria que recorrer ningun elemento de la lista si voy a agregar algo al
    inicio.
    
    El bubble sort igualmente tendra una complejidad de 0(n) en el peor de sus casos. Los elementos se organizan cada vez que agregamos otro elemento,
    esto significa que el bubble sort solo tendra que recorrer la lista una vez ya que todo hasta ese momento ya esta ordenado. En el mejor de los casos,
    este es de complejidad 0(1) si el elemento que queremos acomdar es el primero de la lista.


# NOTA

No hice entregas de la parte de algoritmo de ordenamiento y tampoco de la arboles pero en este programa ya estan implementadas. 
Con este proyecto espero cumplir con las evidencias:

       Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa    
       Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes
       Selecciona y usa una estructura lineal adecuada al problema
       Selecciona un algoritmo de ordenamiento adecuado al problema
       Usa un árbol adecuado para resolver un problema


