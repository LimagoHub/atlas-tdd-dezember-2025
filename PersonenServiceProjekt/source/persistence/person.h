//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once


#include <string>
#include <ostream>

class person {
    std::string id;
    std::string vorname;
    std::string nachname;

public:
    person(const std::string &vorname="John", const std::string &nachname="Doe") : vorname(vorname), nachname(nachname) {}

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        person::id = id;
    }

    const std::string &getNachname() const {
        return nachname;
    }

    void setNachname(const std::string &nachname) {
        person::nachname = nachname;
    }

    const std::string &getVorname() const {
        return vorname;
    }

    void setVorname(const std::string &vorname) {
        person::vorname = vorname;
    }

    friend std::ostream &operator<<(std::ostream &os, const person &person) {
        os << "id: " << person.id << " vorname: " << person.vorname << " nachname: " << person.nachname;
        return os;
    }

    bool operator==(const person &rhs) const {
        return id == rhs.id &&
               vorname == rhs.vorname &&
               nachname == rhs.nachname;
    }

    bool operator!=(const person &rhs) const {
        return !(rhs == *this);
    }

};
