for (let i = 0; i < n; ++i) {
        for (let j = 0; j < 4; ++j) {
            if (i == 0) {
                prev[i][j] = -1;
            } else {
                prev[i][j] = prev[i - 1][j];
            }
        }
        prev[i][str[i].charCodeAt(0) - aCharCode] = i;
    }