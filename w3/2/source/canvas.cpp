#include "../headers/canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    canvas = new char*[height];
    for (int i = 0; i < height; ++i) {
        canvas[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] canvas[i];
    }
    delete[] canvas;
}

void Canvas::DrawCircle(int x, int y, int radius, char ch) {
    int centerX = x;
    int centerY = y;
    int r = radius;
    int x0 = r;
    int y0 = 0;
    int err = 0;

    while (x0 >= y0) {
        SetPoint(centerX + x0, centerY + y0, ch);
        SetPoint(centerX + y0, centerY + x0, ch);
        SetPoint(centerX - y0, centerY + x0, ch);
        SetPoint(centerX - x0, centerY + y0, ch);
        SetPoint(centerX - x0, centerY - y0, ch);
        SetPoint(centerX - y0, centerY - x0, ch);
        SetPoint(centerX + y0, centerY - x0, ch);
        SetPoint(centerX + x0, centerY - y0, ch);

        if (err <= 0) {
            y0 += 1;
            err += 2 * y0 + 1;
        }
        if (err > 0) {
            x0 -= 1;
            err -= 2 * x0 + 1;
        }
    }
}

void Canvas::FillCircle(int x, int y, int radius, char ch) {
    int centerX = x;
    int centerY = y;
    int r = radius;

    for (int dy = -r; dy <= r; dy++) {
        for (int dx = -r; dx <= r; dx++) {
            if (dx * dx + dy * dy <= r * r) {
                SetPoint(centerX + dx, centerY + dy, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; ++i) {
        canvas[top][i] = ch;
        canvas[bottom][i] = ch;
    }
    for (int i = top; i <= bottom; ++i) {
        canvas[i][left] = ch;
        canvas[i][right] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            canvas[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        canvas[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    if (dx < 0) dx1 = -1; else if (dx > 0) dx1 = 1;
    if (dy < 0) dy1 = -1; else if (dy > 0) dy1 = 1;
    if (dx < 0) dx2 = -1; else if (dx > 0) dx2 = 1;
    int longest = abs(dx);
    int shortest = abs(dy);
    if (!(longest > shortest)) {
        longest = abs(dy);
        shortest = abs(dx);
        if (dy < 0) dy2 = -1; else if (dy > 0) dy2 = 1;
        dx2 = 0;
    }
    int numerator = longest >> 1;
    for (int i = 0; i <= longest; i++) {
        SetPoint(x, y, ch);
        numerator += shortest;
        if (!(numerator < longest)) {
            numerator -= longest;
            x += dx1;
            y += dy1;
        } else {
            x += dx2;
            y += dy2;
        }
    }
}
void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }
}