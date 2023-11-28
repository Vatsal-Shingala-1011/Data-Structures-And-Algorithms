#include <iostream>
using namespace std;

void floodFill(int** image, int rows, int columns, int sr, int sc, int newColor, int originalColor) {
    // Check if the pixel is out of bounds or not the original color.
    if (sr < 0 || sr >= rows || sc < 0 || sc >= columns || 
        image[sr][sc] != originalColor) {
        return;
    }

    // Fill the current pixel
    image[sr][sc] = newColor;

    // Recursively fill the adjacent pixels (up, down, left, right)
    floodFill(image, rows, columns, sr + 1, sc, newColor, originalColor);
    floodFill(image, rows, columns, sr - 1, sc, newColor, originalColor);
    floodFill(image, rows, columns, sr, sc + 1, newColor, originalColor);
    floodFill(image, rows, columns, sr, sc - 1, newColor, originalColor);
}

void floodFill(int** image, int rows, int columns, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    floodFill(image, rows, columns, sr, sc, newColor, originalColor);
}

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    int** image = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        image[i] = new int[columns];
    }

    cout << "Enter the image pixels:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cout << "Enter the source row: ";
    cin >> sr;
    cout << "Enter the source column: ";
    cin >> sc;
    cout << "Enter the new color: ";
    cin >> newColor;
    sc--;
    sr--;

    floodFill(image, rows, columns, sr, sc, newColor);

    cout << "\nModified Image:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* 
m = number of row
n= number of column
m*n = total number of grid
Time Complexity:O(m*n)
Space Complexity:O(m*n)

*/