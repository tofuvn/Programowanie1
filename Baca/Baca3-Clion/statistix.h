// Van The Ho

bool expval(unsigned int n, const double *x, const double *p, double (*f)(double), double &r) {

    double lastPn = 1;

    for (int i = 0; i < n; i++) {
        if (p[i] < 0) {
            return false;
        }

        lastPn -= p[i];
    }

    if (lastPn > 1 or lastPn <= 0) {
        return false;
    }

    r = 0;

    for (int i = 0; i < n; i++) {
        r += f(x[i]) * p[i];
    }

    r += f(x[n]) * lastPn;

    return true;
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool median(unsigned int n, const int *t, int (*f)(int), bool (*p)(int), double &r) {

    if (n == 0) {
        return false;
    }

    int *selectedArray = new int[n];

    int sizeOfArray = 0;

    for (int i = 0; i < n; i++) {
        if (p(t[i])) {
            selectedArray[sizeOfArray] = f(t[i]);
            sizeOfArray++;
        }
    }
    if (sizeOfArray == 0) {
        return false;
    }

    quickSort(selectedArray, 0, sizeOfArray - 1);

    int *uniqueArray = new int[sizeOfArray];

    int index = 0;

    int i = 0;
    while (i < sizeOfArray) {
        uniqueArray[index] = selectedArray[i];
        while (selectedArray[i] == selectedArray[i + 1]) {
            i = i + 1;
        }
        i++;

        index = index + 1;
    }

    if (index == 0) {
        return false;
    }

    r = 0;

    if (index % 2 == 1) {
        r = uniqueArray[(index - 1) / 2];
    } else {
        r = uniqueArray[(index - 1) / 2] + uniqueArray[(index) / 2];
        r /= 2;
    }

    delete[] selectedArray;
    delete[] uniqueArray;

    return true;
}


unsigned int gcdOfTwoNumber(int a, int b) {
    if (b < 0) b = -b;
    if (a < 0) a = -a;

    if (b == 0)
        return a;
    return gcdOfTwoNumber(b, a % b);
}

/*unsigned int gcd(unsigned int n, const int *t, int *r = nullptr) {


    unsigned int result = uniqueArray[0] > 0 ? uniqueArray[0] : -(uniqueArray[0]);

	for (int i = 1; i < index; i++) {
			result = gcdOfTwoNumber(result, uniqueArray[i]);
	}


	if (r != nullptr) {
		for (int i = 0 ; i < n; i++) {
			r[i] = tempArray[i] / result;
		}
	}

	return result;
}*/

unsigned int gcd(unsigned int n, const int *t, int *r = nullptr) {


    if (n == 0) {
        return 0;
    }

    int *tempArray = new int[n];

    for (int i = 0; i < n; i++) {
        tempArray[i] = t[i];
    }

    quickSort(tempArray, 0, n - 1);

    if ()




        r[0] = uniqueArray[0];
        return uniqueArray[0] > 0 ? uniqueArray[0] : -(uniqueArray[0]);


    unsigned int result = uniqueArray[0] > 0 ? uniqueArray[0] : -(uniqueArray[0]);

    for (int i = 1; i < index; i++) {
        if (tempArray[i] != 0)
            result = gcdOfTwoNumber(result, );
    }


    if (r != nullptr) {
        for (int i = 0; i < index; i++) {
            r[i] = uniqueArray[i];
        }
    }

    delete[] tempArray;
    return result;
}


unsigned int count(unsigned int n, const int *t, bool (*p)(int, int) = nullptr) {

    if (n == 0) {
        return 0;
    }
    int *tempArray = new int[n];
    for (int i = 0; i < n; i++) {
        tempArray[i] = t[i];
    }

    quickSort(tempArray, 0, n - 1);

    int *uniqueArray = new int[n];

    int index = 0;

    int iter = 0;
    while (iter < n) {
        uniqueArray[index] = tempArray[iter];
        while (tempArray[iter] == tempArray[iter + 1]) {
            iter = iter + 1;
        }
        iter++;

        index = index + 1;
    }


    if (!p) {
        return index * index;
    }


    unsigned int total = 0;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {

            if (p(uniqueArray[i], uniqueArray[j])) {
                total++;
            }
        }
    }

    delete[] uniqueArray;
    return total;
}

