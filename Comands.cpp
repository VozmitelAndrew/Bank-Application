#include <functional>
#include <unordered_map>
#include <vector>

//TODO - перенести всё в .h файлы
class Database {
private:
    std::map<std::string, double> accounts; // Карта с балансами пользователей
    std::mutex db_mutex;                    // Мьютекс для синхронизации доступа к базе данных
public:
    // Регистрация нового пользователя
    void registerUser(const std::string& username);

    // Добавление средств
    void deposit(const std::string& username, double amount);

    // Снятие средств
    void withdraw(const std::string& username, double amount);
};


class CommandDispatcher {
    std::unordered_map<std::string, std::function<void(std::istringstream&, std::string&)>> commandMap;
public:
    CommandDispatcher(Database& db){
        this->registerCommand("register", [&db](std::istringstream& ss, std::string& response) {
            std::string username;
            ss >> username;
            db.registerUser(username);
            response = "you have registered!";
        });

        this->registerCommand("deposit", [&db](std::istringstream& ss, std::string& response) {
            std::string username;
            double amount;
            ss >> username >> amount;
            db.deposit(username, amount);
            response = "you have deposited!";
        });

        this->registerCommand("withdraw", [&db](std::istringstream& ss, std::string& response) {
            std::string username;
            double amount;
            ss >> username >> amount;
            db.withdraw(username, amount);
            response = "you have withdrawn!";
        });
    }

    void registerCommand(const std::string& command, const std::function<void(std::istringstream&, std::string&)>& handler) {
        commandMap[command] = handler;
    }

    bool handleCommand(const std::string& command, std::istringstream& ss, std::string& response) {
        if (commandMap.find(command) != commandMap.end()) {
            try{
                commandMap[command](ss, response);
                return true;
            }
            catch(...){
                response = "sorry for your error in " + command;
            }
        }
        return false;
    }

    std::vector<std::string> getRegisteredCommands() const {
        std::vector<std::string> commands;
        for (const auto& entry : commandMap) {
            commands.push_back(entry.first);
        }
        return commands;
    }
};