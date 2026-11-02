#include <iostream>
#include <memory>

class Button {
public:
    virtual ~Button() = default;
    virtual void render() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void render() const = 0;
};

class WindowsButton final : public Button {
public:
    void render() const override {
        std::cout << "Windows button\n";
    }
};

class WindowsCheckbox final : public Checkbox {
public:
    void render() const override {
        std::cout << "Windows checkbox\n";
    }
};

class MacOSButton final : public Button {
public:
    void render() const override {
        std::cout << "macOS button\n";
    }
};

class MacOSCheckbox final : public Checkbox {
public:
    void render() const override {
        std::cout << "macOS checkbox\n";
    }
};

class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

class WindowsFactory final : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

class MacOSFactory final : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacOSButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacOSCheckbox>();
    }
};

void renderInterface(const GUIFactory& factory) {
    auto button = factory.createButton();
    auto checkbox = factory.createCheckbox();

    button->render();
    checkbox->render();
}

int main() {
    WindowsFactory windows;
    MacOSFactory macOS;

    renderInterface(windows);
    renderInterface(macOS);
}
