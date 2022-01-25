//
// Created by MinMinnn on 17/01/2022.
//
#ifndef __UCZESTNIK_H__
#define __UCZESTNIK_H__

struct Uczestnik {
    enum Plec {
        K, M, W
    };

    Uczestnik(Plec p) : plec(p) {}

    Plec plec;
};

#endif //BACA6_UCZESTNIK_H
