# Practica7-m9

Servidor:
Inicialización: Se inicia la biblioteca Winsock para permitir la comunicación a través de sockets.
Creación del socket: Se crea un socket que escuchará las conexiones entrantes.
Vinculación del socket: Se asigna el socket a un puerto específico (en este caso, el 9000) para que los clientes sepan dónde conectarse.
Escucha de conexiones: El servidor entra en un bucle infinito esperando conexiones de clientes.
Aceptación de conexiones: Cuando un cliente se conecta, el servidor acepta la conexión y crea un nuevo socket para comunicarse con ese cliente específico.
Obtención de la hora: Se obtiene la hora actual del sistema.
Envío de la hora: La hora se envía al cliente conectado.
Cierre de la conexión: Se cierra la conexión con el cliente para liberar recursos.
Bucle: Se vuelve al paso 4 para esperar nuevas conexiones.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Cliente:
Inicialización: Se inicia la biblioteca Winsock.
Creación del socket: Se crea un socket para establecer la conexión con el servidor.
Conexión al servidor: Se intenta conectar al servidor en la dirección IP y puerto especificados.
Recepción de datos: Se recibe la hora enviada por el servidor.
Impresión de la hora: Se muestra la hora recibida en la consola.
Cierre del socket: Se cierra el socket.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

En resumen:
Servidor: Espera conexiones, acepta clientes, obtiene la hora actual y la envía a los clientes conectados.
Cliente: Se conecta al servidor, recibe la hora enviada por el servidor y la muestra en pantalla.
