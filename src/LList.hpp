#pragma once

struct LList {
    struct LList* next;
    int payload;
    ~LList() {
        delete next;
    }
};