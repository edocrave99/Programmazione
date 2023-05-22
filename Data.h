#ifndef ELABORATO_DATA_H
#define ELABORATO_DATA_H

#include <iostream>


class Data {
    private:

        int giorno, mese, anno;

        int giorniInMese(int mese, int anno) const {
            switch (mese) {
                case 2:
                    return isBisestile(anno) ? 29 : 28;
                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;
                default:
                    return 31;
            }
        }

        bool isBisestile(int anno) const {
            if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0)
                return true;
            else return false;
        }

    public:

        Data();

        Data(int giorno, int mese, int anno);

        int getGiorno() const;

        int getMese() const;

        int getAnno() const;

        bool isValid(int giorno, int mese, int anno) const;

        std::string toString() const;
};


#endif //ELABORATO_DATA_H
