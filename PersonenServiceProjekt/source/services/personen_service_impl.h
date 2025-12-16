//
// Created by JoachimWagner on 15.12.2025.
//

#pragma once
#include "personen_service.h"
#include "personen_service_exception.h"
#include "blacklist_service.h"
#include "../persistence/personen_repository.h"

class personen_service_impl: public personen_service {

public:
    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService) :
        repo(repo),blacklistService(blacklistService) {}


    /*
 *	Vorname < 2 -> PSE
 *	Nachname < 2 -> PSE
 *
 *	Attila -> PSE
 *
 *	Alle technische Exceptions -> PSE
 *
 *	Happy Day -> person an Save_or_update Methode uebergeben
 *
 */

    void speichern(person &person_) override {
        try {
            speichernImpl(person_);

        } catch (const  personen_service_exception & ex) {
            throw ex;
        } catch(const std::exception & ex) {
            throw personen_service_exception{"Ein Fehler ist aufgetreten"};
        }
    }
    void speichern(std::string vorname, std::string nachname) override {
        person p{vorname, nachname};
        speichern(p);
    }

private:
    personen_repository &repo;
    blacklist_service &blacklistService;

    void speichernImpl(const person &person_) const {

        if (person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz!"};
        if (person_.getNachname().length() < 2)
            throw personen_service_exception{"Nachname zu kurz!"};
        if (blacklistService.isBlacklisted(person_))
            throw personen_service_exception{"person is blacklisted"};
        repo.save_or_update(person_);
    }

};
