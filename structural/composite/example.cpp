#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class FileSystemEntry {
public:
    explicit FileSystemEntry(std::string name) : name_(std::move(name)) {}
    virtual ~FileSystemEntry() = default;
    virtual std::size_t size() const = 0;
    virtual void print(std::size_t indent) const = 0;

protected:
    std::string name_;
};

class File final : public FileSystemEntry {
public:
    File(std::string name, std::size_t bytes)
        : FileSystemEntry(std::move(name)), bytes_(bytes) {}

    std::size_t size() const override {
        return bytes_;
    }

    void print(std::size_t indent) const override {
        std::cout << std::string(indent, ' ') << name_
                  << " (" << size() << " bytes)\n";
    }

private:
    std::size_t bytes_;
};

class Directory final : public FileSystemEntry {
public:
    explicit Directory(std::string name) : FileSystemEntry(std::move(name)) {}

    void add(std::unique_ptr<FileSystemEntry> entry) {
        children_.push_back(std::move(entry));
    }

    std::size_t size() const override {
        std::size_t total = 0;
        for (const auto& child : children_) {
            total += child->size();
        }
        return total;
    }

    void print(std::size_t indent) const override {
        std::cout << std::string(indent, ' ') << name_
                  << "/ (" << size() << " bytes)\n";
        for (const auto& child : children_) {
            child->print(indent + 2);
        }
    }

private:
    std::vector<std::unique_ptr<FileSystemEntry>> children_;
};

int main() {
    auto sources = std::make_unique<Directory>("src");
    sources->add(std::make_unique<File>("main.cpp", 200));
    sources->add(std::make_unique<File>("helper.cpp", 300));

    Directory project("project");
    project.add(std::make_unique<File>("README.md", 100));
    project.add(std::move(sources));

    const FileSystemEntry& entry = project;
    entry.print(0);
    std::cout << "Total size: " << entry.size() << " bytes\n";
}
