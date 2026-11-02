#include <iostream>
#include <string_view>

class Logger {
public:
    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    void log(std::string_view message) const {
        std::cout << "[log] " << message << '\n';
    }

private:
    Logger() = default;
};

int main() {
    Logger& first = Logger::instance();
    Logger& second = Logger::instance();

    std::cout << "Same logger: " << std::boolalpha << (&first == &second) << '\n';
    first.log("Application started");
    second.log("Application finished");
}
