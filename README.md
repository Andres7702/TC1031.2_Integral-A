# TC1031.2_Integral-A

Este programa es un manejador de listas escolares. El usuario podra crear listas doblemente ligadas de objetos de tipo estudiante.
Cada estudiante tendra atributos individuales como su nombre, ID y grado que estan cursando.

# SICT0302B: Toma decisiones

Selecciona y usa una estructura lineal adecuada al problema:
Para este problema utiliza un lista doblemente ligada, ya que esto me permitiria acceder a los elementos de una forma mas rapida, ademas que
me permitiria acceder a la lista de una manera de atras hacia adelante (que es una opcion de visualizacion que me gustaria tener).

Selecciona un algoritmo de ordenamiento adecuado al problema:
Para el problema utiliza un algoritmo del tipo bubble sort. Escogi este algoritmo por que la lista se acomoda automaticamente cada vez que 
agregamos un estudiante nuevo, esto significa que el bubble sort solo tendra que recorrer la lista una vez ya que todo hasta ese nuevo elemento
ya esto ordenado.

# SICT0301B: Evalúa los componentes

Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa:

Los casos de pruebas para todas las funciones se encuentran en main.cpp donde se prueban las funciones de:

    El ordenamiento de los elementos en la lista doblemente ligada.

    La modificacion de un elemento de la lista.
    
    Eliminar un elemento de la lista.
    
Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes:

    La lista doblemente ligada tendra una complejidad de 0(n) en su peor de los casos, ya que tendria que recorrer la lista completa para agregar
    un elemento al final. Y en el mejor de sus casos 0(1) ya que no tendria que recorrer ningun elemento de la lista si voy a agregar algo al
    inicio.
    
    El bubble sort igualmente tendra una complejidad de 0(n) en el peor de sus casos. Los elementos se organizan cada vez que agregamos otro elemento,
    esto significa que el bubble sort solo tendra que recorrer la lista una vez ya que todo hasta ese momento ya esta ordenado. En el mejor de los casos,
    este es de complejidad 0(1) si el elemento que queremos acomdar es el primero de la lista.


# NOTA
No entregue el primer avance, pero aqui ya se esta implementando. Si pudiera chechar y correguir mi calificacion de esa parte del proyecto, estaria muy
agradecido porfe :)




