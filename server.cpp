#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    int iResult;

    // Inicializar Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    // Crear socket
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Configurar la dirección del servidor
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Escuchar en todas las interfaces
    serverAddr.sin_port = htons(9000); // Puerto 9000

    // Unir el socket a la dirección y puerto
    if (bind(listenSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    // Escuchar conexiones entrantes
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    printf("Servidor iniciado. Escuchando en el puerto 9000...\n");

    // Bucle de aceptación de conexiones
    while (true) {
        sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);

        SOCKET clientSocket = accept(listenSocket, (sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET) {
            printf("accept failed with error: %ld\n", WSAGetLastError());
            continue;
        }

        // Obtener la hora actual
        time_t now = time(0);
        char* dt = ctime(&now);

        // Enviar la hora al cliente
        send(clientSocket, dt, strlen(dt), 0);
        printf("Hora y fecha enviadas: %s\n", dt);

        // Cerrar la conexión con el cliente
        closesocket(clientSocket);
    }

    // Limpiar Winsock
    closesocket(listenSocket);
    WSACleanup();
    return 0;
}