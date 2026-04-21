# Desarrollos adicionales implementados

1. Validación de placas repetidas

¿Para qué se implementó?
Se implementó para evitar que un mismo vehículo fuera registrado dos veces dentro del parqueadero.

¿Por qué se consideró necesario?  
Si el programa permitiera ingresar la misma placa más de una vez, se generaría información incorrecta sobre los espacios ocupados y sobre los vehículos que realmente están dentro del parqueadero.

¿Cómo se llevó a cabo su implementación?
Se creó una función que revisa el arreglo de placas y compara la placa ingresada con las que ya están registradas en espacios ocupados. Si encuentra una coincidencia, el programa muestra un mensaje y no permite registrar nuevamente el vehículo.

2. Validación de hora de entrada y salida

¿Para qué se implementó? 
Se implementó para verificar que la hora y los minutos digitados por el usuario estén dentro de un rango válido.

¿Por qué se consideró necesario?  
Sin esta validación, el usuario podría ingresar horas imposibles, por ejemplo 30 horas o 80 minutos, y eso dañaría el cálculo del tiempo de permanencia y del valor a pagar.

¿Cómo se llevó a cabo su implementación?
Después de pedir la hora y el minuto, el programa revisa que la hora esté entre 0 y 23 y que los minutos estén entre 0 y 59. Si los datos no cumplen esa condición, el sistema muestra un mensaje de error y detiene el registro.

4. Mensaje con número de espacio asignado

¿Para qué se implementó?
Se implementó para informar al usuario en qué espacio fue ubicado el vehículo.

¿Por qué se consideró necesario?
Esto mejora la interacción con el programa y hace más claro el resultado del registro de entrada.

¿Cómo se llevó a cabo su implementación?  
Después de registrar correctamente el vehículo, el sistema imprime en pantalla el número del espacio asignado según la posición encontrada en el arreglo.

5. Resumen de disponibilidad

¿Para qué se implementó? 
Se implementó para mostrar de manera rápida cuántos espacios están ocupados, cuántos están libres y cuántos existen en total.

¿Por qué se consideró necesario?  
Aunque el mapa ya permite ver visualmente el estado del parqueadero, el resumen facilita entender la disponibilidad general sin necesidad de revisar cada espacio uno por uno.

¿Cómo se llevó a cabo su implementación?  
Se creó una función que recorre el arreglo `occupied` y cuenta los espacios ocupados y libres. Al final muestra esos datos en consola junto con el total de espacios.

# Importante

Cabe aclarar que, para realizar cada una de estas partes, me apoyé bastante en videos de YouTube y en herramientas de inteligencia artificial, principalmente como guía para entender mejor la lógica y poder aplicarla en el desarrollo del programa
