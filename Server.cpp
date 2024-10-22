#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <mutex>
#include <netinet/in.h> // Для работы с сокетами
#include <unistd.h>     // Для функции close()
#include <sstream>

//#include "Comands.cpp"

#define dbg(obj) (std::cout << (obj) << std::endl)

class Database {
    std::map<std::string, double> accounts; // Карта с балансами пользователей
    std::mutex db_mutex; // Мьютекс для синхронизации доступа к базе данных

public:
    // Регистрация нового пользователя
    void registerUser(const std::string& username) {
        std::lock_guard<std::mutex> lock(db_mutex); // Автоматическая блокировка мьютекса
        if (accounts.find(username) == accounts.end()) {
            accounts[username] = 0.0; // Инициализируем баланс
            std::cout << "User " << username << " registered." << std::endl;
        } else {
            std::cout << "User " << username << " already exists!" << std::endl;
        }
    }

    // Добавление средств
    void deposit(const std::string& username, double amount) {
        std::lock_guard<std::mutex> lock(db_mutex);
        accounts[username] += amount;
        std::cout << "Deposited " << amount << " to " << username << ". Current balance: " << accounts[username] << std::endl;
    }

    // Снятие средств
    void withdraw(const std::string& username, double amount) {
        std::lock_guard<std::mutex> lock(db_mutex);
        if (accounts[username] >= amount) {
            accounts[username] -= amount;
            std::cout << "Withdrawn " << amount << " from " << username << ". Current balance: " << accounts[username] << std::endl;
        } else {
            std::cout << "Insufficient funds for " << username << "." << std::endl;
        }
    }
};


// Обработка клиента
void handleClient(int clientSocket, Database& db) {
    char buffer[1024] = {0}; // Буфер для приёма данных
    read(clientSocket, buffer, 1024); // Чтение данных из сокета

    std::string request(buffer); // Преобразуем буфер в строку

    //dbg(request);

    // Разделитель между заголовками HTTP и телом запроса
    std::string delimiter = "\r\n\r\n";
    size_t bodyPos = request.find(delimiter); // Поиск начала тела запроса

    std::string response = "OK, GOOD TO GO!\n"; // Ответ по умолчанию

    if (bodyPos != std::string::npos) {
        // Получение тела запроса (после заголовков)
        std::string body = request.substr(bodyPos + delimiter.length());
        std::istringstream ss(body);
        std::string command, username;
        double amount;

        ss >> command; // Чтение команды

        //dbg(command);

        // Обработка команд
        if (command == "register") {
            ss >> username;
            db.registerUser(username); // Регистрация пользователя
            response = "you have registered!";
        } else if (command == "deposit") {
            ss >> username >> amount;
            db.deposit(username, amount); // Депозит на счёт пользователя
            response = "you have deposit!";
        } else if (command == "withdraw") {
            ss >> username >> amount;
            db.withdraw(username, amount); // Снятие со счёта
            response = "you have withdraw!";
        } else {
            std::cout << "Unknown command: " << command << std::endl;
            response = "Unknown command: " + command; // Неизвестная команда
        }
    } else {
        std::cout << "Malformed HTTP request" << std::endl;
        response = "Malformed HTTP request"; // Некорректный запрос
    }

    // Формируем HTTP-ответ
    std::string httpResponse = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: text/plain\r\n"
                               "Content-Length: " + std::to_string(response.length()) + "\r\n"
                                                                                        "\r\n" + response;

    // Отправляем ответ клиенту
    send(clientSocket, httpResponse.c_str(), httpResponse.length(), 0);

    // Закрываем соединение с клиентом
    close(clientSocket);
}

// Основная функция
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    Database db; // Создаём объект базы данных

    // Создание сокета
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Настройка сокета (повторное использование адресов и портов)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Принимаем соединения на любой IP
    address.sin_port = htons(8080); // Порт 8080

    // Привязка сокета к адресу и порту
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Настройка слушателя (максимум 3 соединения в очереди)
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server started on port 8080!" << std::endl;

    // Главный цикл для обработки клиентов
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }


        std::thread clientThread(handleClient, new_socket, std::ref(db));
        clientThread.detach();
    }
}
