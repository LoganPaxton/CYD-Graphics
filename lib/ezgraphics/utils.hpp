#pragma once

bool check_bounds(int &x, int &y, int width, int height)
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}