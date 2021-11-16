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

Clase DList

    add_student: Esta funcion recorre la lista para agrega un nuevo nodo, la posicion en donde sera insertado
    este nodo depende del valor de ID del estudiante. En su peor caso tiene que recorrer la lista completa
    para agregar un nodo al final, por lo que la funcion es de complejidad o(n). Esta funcion incluye otras 
    dos funciones: add_First y add_second cuya complejidad es de o(1).
    
    find: Esta funcion recorre la lista para checar si existe un valor especifico dentro de ella. En el peor
    de sus casos tiene que recorrer el arbol completo por lo que su complejidad es de o (n).
    
    update_calificacion: Esta funcion sirve para añadir una calificacion a un estudiante de la lista. El 
    usuario mande el ID del estudiante a consultar y esta funcion recorre la lista hasta encontrar a dicho
    estudiante para despues modificar sus calificaciones. En el peor de sus casos tiene que recorrer la lista 
    completa por lo que su complejidad es de o (n).
    
    DeleteAt: Esta funcion recibe un ID de estudiante y despues recorre la lista completa buscandolo para 
    despues eliminarlo. En el peor de sus casos tiene que recorrer la lista completa por lo que su complejidad 
    es de o (n). Esta funcion tambien incluye otra funcion llamada deleteFirst, que borra el primer elemento de 
    la lista, cuya complejidad es de o(1).
    
    toString: Recorre la lista completa imprimiendo los datos de cada uno de sus nodos. Esta funcion siempre 
    tiene que recorrer la lista completa por lo que su complejidad siempre es de o(n).
    
    check_info: Esta funcion recorre la lista para buscar a un estudiante en especifico y despues imprimir
    sus datos. En el peor de sus casos tiene que recorrer la lista completa por lo que su complejidad 
    es de o (n).
    
Class Calificaciones:

    update_calificacion: Recibe numero de posicion de un array en donde se encuentran las diferentes materias
    y tambien recibe la calificacion nueva que se guardara en dicha posicion. Esta funcion solo accesa a un
    array en la posicion especificada por lo que su complejidad es de o(1). (Esta funcion es llamada por:
    update_calificacion de la clase DList).
    
    peor_calif: Recorre el array completo en busca de la calificacion mas baja. Esta funcion siempre tiene 
    que recorrer todo el array por lo que su complejidad es de 0(n).
    
    to_string: Recorre el array completo de materias para imprimir las calificaciones. Esta funcion es de 
    complejidad O(n). (Esta funcion es llamada por el toString de la clase DList.).
    
Class Maestro (Node):

    add: Agrega un nodo al arbol. Esta funcion es un simple add de un BST, por lo que es de complejidad O(logn).
    
    find: Busca por un valor dentro del arbol. Esta funcion es un find de un BST, por lo ques de complejidad 
    O(logn).
    
    remove: Elimina nodo del arbol y hace las respecitvas conexiones. Esta funcion es un remove de un BST, 
    por lo ques de complejidad O(logn).
    
    removeChilds: Elimina los hijos de un nodo. Esta funcion no tiene que recorrer el arbol, simplemente
    elimina de memoria el hijo derecho y izquierdo, por lo que su complejidad es de o(1).
    
    toString: Recorre el arbol completo para imprimir todos los datos de todos los maestros. Como 
    tiene que recorrer el arbol esta funcion siempre es de complejidad O(n),
    
    check_info: Imprime los datos del nodo actual. Es de complejidad O(1).
    
    max_depth: recorre el arbol completo para checar cual es su profundidad maxima. Siempre tiene que recorrer
    el arbol completo por lo que su complejidad es de O(n).
    
    check_tree: recorre el arbol completo checando que todos sus nodos esten bien balanceados. Siempre tiene que 
    recorrer el arbol completo por lo que su complejidad es de O(n).
    
    Funciones de Balanceo y rotaciones: Estas funciones se encargan de balancear el arbol para que su estructura
    siempre sea correcta. Cada una de ellas solo una funcion y su complejidad es de O(1).
    
Class AVL

    empty: Devuelve un valor de verdadero o falso dependiendo de si la raiz del arbol es null. Esta funcion
    es de complejidad O(1).
    
    add: Esta funcion se encarga de añadir un nodo nuevo a su estructura por lo que su complejidad es de O(logn).
    Ademas de esto tambien verifica que el valor que estamos añadiendo no exita dentro del arbol, manda a sacar la 
    profundidad de cada uno de sus nodos y tambien lo balancea. Hace esto llamando a las respectivas funciones de la clase 
    Maestro.
    
    remove: Busca un valor dentro del arbol y despues lo elimina haciendo las repectivas conexiones por lo que su 
    complejidad es de O(logn), Ademas de esto tambien manda a llamar a las funciones de balanceo.
    
    removeAll: Esta funcion elimina a los hijos de la raiz del arbol y luego elimina la raiz. Esta funcion es de
    complejidad O(1).
    
    find: Recorre el arbol en busca de un nodo en particular, Esta funcion es un find de un BST, por lo ques de 
    complejidad O(logn).
    
    toString: Recorre el arbol completo para imprimir todos los datos de todos los maestros. Como 
    tiene que recorrer el arbol esta funcion siempre es de complejidad O(n),
    
    check_info: Recorre los nodos del arbol en busca de un nodo especifico y despues imprime su informacion. Este metodo 
    es similar a una busqueda dentro de un arbol por lo que su complejidad en el peor de sus casos de O(logn)
    
    
# SICT0303B: Implementa Acciones Cientificas

Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa:
En el programa utilizo una lista doblemente ligada e implemento sus respectivos metodos para agregar, eliminar,
imprimir y modificar datos en dichas estructuras.

# CORRECCIONES

No hice entregas de la parte de algoritmo de ordenamiento y tampoco de la arboles pero en este programa ya estan implementadas. 
Con este proyecto espero cumplir con las evidencias:

       Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa    
       Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes
       Selecciona y usa una estructura lineal adecuada al problema
       Selecciona un algoritmo de ordenamiento adecuado al problema
       Usa un árbol adecuado para resolver un problema
       Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa
       


