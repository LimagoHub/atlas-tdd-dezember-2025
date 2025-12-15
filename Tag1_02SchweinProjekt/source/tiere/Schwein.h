//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once


#include <string>
#include <stdexcept>
#include <ostream>

class Schwein {
    std::string name;
    int gewicht;

    void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }
public:
    explicit Schwein(const std::string &name = "Nobody") :  gewicht{10}{
        setName(name);
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if(name == "Elsa") throw std::invalid_argument("Name verstoesst gegen die Schweinewuerde!");
        Schwein::name = name;
    }

    int getGewicht() const {
        return gewicht;
    }
    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }

    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }
};
