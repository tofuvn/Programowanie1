// Van The Ho


// Function 1
void przeksztalc(char *s, char (*f)(char)) {

    if (!f or !s) return;

    while (*s != '\0') {
        *s = f(*s);
        ++s;
    }
}

// Function 2
// We check every element in array
//			 if the element is sastified condition we add it to new array 
//			 if not, check another elemet
// Add '\0' to new array.
void filtruj(char *s, bool (*f)(char)) {
    if (!f or !s) return;

    char *temp = s;
    while (*temp != '\0') {
        if (!f(*temp)) {
            *s = *temp;
            ++s;
        }
        ++temp;
    }
    *s = '\0';
}

// Function 3
// The ideal is the same function above , but we need to go through every element in array k.
void filtruj(char *s, char *k) {
    if (!s or !k) return;

    char *p = s;
    while (*p != '\0') {
        char *tempKey = k;
        bool isExistInSource = false;
        while (*tempKey != '\0') {
            if (*p == *tempKey) {
                isExistInSource = true;
                break;
            }
            ++tempKey;
        }
        if (!isExistInSource) {
            *s = *p;
            ++s;
        }
        ++p;
    }
    *s = '\0';
}


// Function 4
bool filtruj(char **first, char **last, bool (*f)(char)) {
    if (!first or !last or !f) return false;

    char *currentRow = *first;

    bool check = false;

    while (currentRow != *last) {
        char *temp = currentRow;
        if (!temp) {
            currentRow = *(++first);
            continue;
        }
        while (*temp != '\0') {
            if (f(*temp)) {
                check = true;
            } else {
                *currentRow = *temp;
                ++currentRow;
            }
            ++temp;
        }
        *currentRow = '\0';
        currentRow = *(++first);
    }

    return check;
}

bool isCapitalized(char c) {
    return c >= 'A' and c <= 'Z';
}

bool isNonCapitalized(char c) {
    return c >= 'a' and c <= 'z';
}

bool isAlphabet(char c) {
    return (isCapitalized(c) or isNonCapitalized(c));
}

// Function 5
void szyfruj(char *s, char *key) {
    if (!s or !key) return;

    char *temp = key;
    while (*s != '\0') {
        if (*temp == '\0') {
            temp = key;
        }

        if (isAlphabet(*temp)) {
            if (isCapitalized(*s)) {
                char k;
                k = ((*s - 'A' + *temp - 'A') % 26) + 'A';
                *s = k;
                ++temp;
            } else if (isNonCapitalized(*s)) {
                char k;
                k = ((*s - 'a' + *temp - 'A') % 26) + 'a';
                *s = k;
                ++temp;
            }
        } else {
            ++temp;
        }
        ++s;
    }
}

// Function 6
void przetwarzaj(char *type, ...) {
    va_list arguments;

    va_start(arguments, type);
    char c = *type;

    while (c != '\0') {
        switch (c) {
            case 'f': {
                char *s = va_arg(arguments, char*);
                bool (*f)(char);
                f = va_arg(arguments, bool(*) (char));
                filtruj(s, f);
                break;
            }

            case 'p': {
                char *s = va_arg(arguments, char*);
                char (*f)(char);
                f = va_arg(arguments, char(*) (char));
                przeksztalc(s, f);
                break;
            }

            case 's': {
                char *s = va_arg(arguments, char*);
                char *k = va_arg(arguments, char*);
                szyfruj(s, k);
                break;
            }
            default:
                break;
        }

        ++type;
        c = *type;
    }
    va_end(arguments);

}
