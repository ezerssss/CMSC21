#include <stdio.h>
#include <math.h>

struct line {
    struct point {
        float x;
        float y;
    } point1, point2;
    float *midpoint;
    float slope;
    float distance;
};

float solveSlope(struct line line1);
void solveMidpoint(struct line* line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);

int main() {
    struct line line1;

    printf("Enter x and y for point1: ");
    scanf("%f %f", &line1.point1.x, &line1.point1.y);
    printf("Enter x and y for point2: ");
    scanf("%f %f", &line1.point2.x, &line1.point2.y);
    line1.slope = solveSlope(line1);
    printf("Slope: %f\n", line1.slope);
    // give address so that it automatically stores the values to the main variable
    solveMidpoint(&line1);
    printf("Midpoint: %f %f\n", line1.midpoint[0], line1.midpoint[1]);
    line1.distance = solveDistance(line1);
    printf("Distance between 2 points: %f\n", line1.distance);
    getSlopeInterceptForm(line1);

    return 0;
}

float solveSlope(struct line line1) {
    // y1 - y2
    float numerator = line1.point1.y - line1.point2.y;

    // x1 - x2
    float denominator = line1.point1.x - line1.point2.x;

    // (y1 - y2) / (x1 - x2)
    return numerator / denominator;
}

void solveMidpoint(struct line* line1){
    // (x1 + x2) / 2
    float x = (line1->point1.x + line1->point2.x) / 2;

    // (y1 + y2) / 2
    float y = (line1->point1.y + line1->point2.y) / 2;

    float midpoints[2] = {x, y};

    // store directly to main variable
    line1->midpoint = midpoints;
}

float squaredMinus(float a, float b) {
    // so that I dont have to always write the dot notation
    return pow((a - b), 2);
}

float solveDistance(struct line line1) {
    // (x1 - x2)^2
    float xSquared = squaredMinus(line1.point1.x, line1.point2.x);

    // (y1 - y2)^2
    float ySquared = squaredMinus(line1.point1.y, line1.point2.y);

    return sqrt(xSquared + ySquared);
}

void getSlopeInterceptForm(struct line line1) {
    // y = mx + b
    // b = y - mx
    float b = line1.point1.y - (line1.slope * line1.point1.x);
    printf("y = %fx + (%f)", line1.slope, b);
}
