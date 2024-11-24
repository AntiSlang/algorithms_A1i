#include <iostream>
#include <random>
#include <iomanip>

bool InsideCircle(const double x, const double y, const double cx, const double cy, const double r) {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}

bool InsideIntersection(const double x, const double y, const double x1, const double y1, const double r1, const double x2, const double y2, const double r2, const double x3, const double y3, const double r3) {
    return InsideCircle(x, y, x1, y1, r1) && InsideCircle(x, y, x2, y2, r2) && InsideCircle(x, y, x3, y3, r3);
}

double MonteCarloArea(const int points, const double x_min, const double x_max, const double y_min, const double y_max, const double x1, const double y1, const double r1, const double x2, const double y2, const double r2, const double x3, const double y3, const double r3) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution dist_x(x_min, x_max);
    std::uniform_real_distribution dist_y(y_min, y_max);
    int inside_count = 0;
    for (int i = 0; i < points; ++i) {
        const double x = dist_x(gen);
        const double y = dist_y(gen);
        if (InsideIntersection(x, y, x1, y1, r1, x2, y2, r2, x3, y3, r3)) {
            inside_count++;
        }
    }
    const double rect_area = (x_max - x_min) * (y_max - y_min);
    return (static_cast<double>(inside_count) / points) * rect_area;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double x1 = 0;
    double y1 = 0;
    double r1 = 0;
    double x2 = 0;
    double y2 = 0;
    double r2 = 0;
    double x3 = 0;
    double y3 = 0;
    double r3 = 0;
    std::cin >> x1 >> y1 >> r1;
    std::cin >> x2 >> y2 >> r2;
    std::cin >> x3 >> y3 >> r3;
    const double x_min = std::min(x1 - r1, std::min(x2 - r2, x3 - r3));
    const double x_max = std::max(x1 + r1, std::min(x2 + r2, x3 + r3));
    const double y_min = std::min(y1 - r1, std::min(y2 - r2, y3 - r3));
    const double y_max = std::max(y1 + r1, std::min(y2 + r2, y3 + r3));
    const double result = MonteCarloArea(1000000, x_min, x_max, y_min, y_max, x1, y1, r1, x2, y2, r2, x3, y3, r3);
    std::cout << std::fixed << std::setprecision(15) << result << std::endl;
    return 0;
}