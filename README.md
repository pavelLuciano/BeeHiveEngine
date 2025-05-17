# BeeHiveEngine
Archivos para el motor
GitHub: ![Aquí](https://github.com/pavelLuciano/BeeHiveEngine)
### Clases y Arquitectura
![Diagrama de Clases](images/classDiag.png)

## Entidades

### Entity:
Clase abstracta que representa cualquier cosa en el juego. Todas las clases que se utilizan en el juego deben heredar de esta clase. 

Cuenta con arreglo vacío de atributos de entidad. Las clases que heredan a esta clase se diferencian por el tipo de atributo que agregan a este arreglo.

### Prop:
Clase que representa un objeto cualesquiera. Es una __Entidad__ que tiene posicion y un modelo asociado.


## Atributos de Entidad

### Transform:
Clase que representa la transformación de una entidad en el espacio. Cuenta con atributos de posisión, rotación y escalado.

### Model:

WIP


