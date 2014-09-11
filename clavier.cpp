// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Confidential and not for redistribution. See LICENSE.txt.
#include "clavier.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Clavier::Clavier(void){
}

void Clavier::generateKey(int vk, bool bExtended){

    KEYBDINPUT  kb = {0};
    INPUT       Input = {0};

    /* Generate a "key down" */
    if (bExtended) { kb.dwFlags  = KEYEVENTF_EXTENDEDKEY; }
    kb.wVk  = vk;
    Input.type  = INPUT_KEYBOARD;
    Input.ki  = kb;
    SendInput(1, &Input, sizeof(Input));

    /* Generate a "key up" */
    ZeroMemory(&kb, sizeof(KEYBDINPUT));
    ZeroMemory(&Input, sizeof(INPUT));
    kb.dwFlags  =  KEYEVENTF_KEYUP;
    if (bExtended) { kb.dwFlags |= KEYEVENTF_EXTENDEDKEY; }
    kb.wVk = vk;
    Input.type = INPUT_KEYBOARD;
    Input.ki = kb;
    SendInput(1, &Input, sizeof(Input));

    return;
}
