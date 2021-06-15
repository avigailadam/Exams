
#ifndef GAME_EXCEPTIONS_H
#define GAME_EXCEPTIONS_H

#include <exception>

namespace mtm {
    class Exception : public std::exception {
    };

    class IllegalArgument : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class IllegalCell : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class CellEmpty : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class MoveTooFar : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class CellOccupied : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class OutOfRange : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class OutOfAmmo : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };

    class IllegalTarget : public mtm::Exception {
    public:
        const char *what() const noexcept override;
    };
}
#endif //GAME_EXCEPTIONS_H
