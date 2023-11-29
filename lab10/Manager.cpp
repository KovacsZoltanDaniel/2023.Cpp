//
// Created by Dani on 2023. 11. 29..
//

#include "Manager.h"
#include <algorithm>

const string Manager::MANAGER_MUNKAKOR = "manager"; //globalis valtozo

void Manager::addBeosztott(Alkalmazott *beosztott) {
    beosztottak.push_back(beosztott);

}

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor) {

}

void Manager::print(ostream &os) const{
    os << "Manager " << id << " " << vezetekNev << " " << keresztNev << " " << szuletesiEv << " " << munkakor << " beosztottjai : " << endl;
    for (auto b:beosztottak){
        b->print(os);
    }
//    for_each(beosztottak.begin(), beosztottak.end(), [&os](Alkalmazott *beosztott) {
//        beosztott->print(os);
//    });

}

void Manager::deleteBeosztott(int id) {
    auto item = find_if(beosztottak.begin(), beosztottak.end(), [id](Alkalmazott *beosztott) {
        return beosztott->getId() == id;
    });
    if (item == beosztottak.end()){
        return;
    }
    beosztottak.erase(item);
}

int Manager::getBeosztottakSzama() const {
    return beosztottak.size();
}
