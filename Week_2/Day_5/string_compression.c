int compress(char* chars, int charsSize) {
    int idx = 0;

    for (int i = 0; i < charsSize; i++) {
        char ch = chars[i];
        int count = 0;

        while (i < charsSize && chars[i] == ch) {
            count++;
            i++;
        }

        chars[idx++] = ch;

        if (count > 1) {
            char digits[12];
            int n = 0;

            while (count > 0) {
                digits[n++] = (count % 10) + '0';
                count /= 10;
            }

            for (int j = n - 1; j >= 0; j--) {
                chars[idx++] = digits[j];
            }
        }

        i--;
    }

    return idx;
}
