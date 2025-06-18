#include "bisectionmethod.h"
#include <cmath>
#include <QDebug>

BisectionMethod::BisectionMethod() {
}

BisectionMethod::Result BisectionMethod::solveEquation(const QString &equation, double a, double b, double epsilon, int maxIterations) {
    bool success;
    QString errorMessage;
    auto func = parseEquation(equation, success, errorMessage);
    
    if (!success) {
        return Result{false, 0.0, 0, 0.0, errorMessage};
    }
    
    return solve(func, a, b, epsilon, maxIterations);
}

BisectionMethod::Result BisectionMethod::solve(const std::function<double(double)> &func, double a, double b, double epsilon, int maxIterations) {
    Result result;
    result.success = false;
    result.iterations = 0;
    result.precision = epsilon;
    
    // Проверка на корректность интервала
    if (a >= b) {
        result.errorMessage = "Некорректный интервал: a должно быть меньше b";
        return result;
    }
    
    // Проверка на наличие корня на интервале
    double fa = func(a);
    double fb = func(b);
    
    if (fa * fb > 0) {
        result.errorMessage = "На заданном интервале нет корня или их четное количество";
        return result;
    }
    
    // Основной цикл метода деления пополам
    double c;
    for (int i = 0; i < maxIterations; i++) {
        c = (a + b) / 2.0;
        double fc = func(c);
        
        if (std::abs(fc) < epsilon) {
            result.success = true;
            result.root = c;
            result.iterations = i + 1;
            return result;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        
        if (std::abs(b - a) < epsilon) {
            result.success = true;
            result.root = c;
            result.iterations = i + 1;
            return result;
        }
    }
    
    result.errorMessage = "Достигнуто максимальное количество итераций";
    result.root = c;
    result.iterations = maxIterations;
    return result;
}

std::function<double(double)> BisectionMethod::parseEquation(const QString &equation, bool &success, QString &errorMessage) {
    // TODO: Реализовать парсинг уравнения
    // Временная реализация для тестирования
    success = true;
    errorMessage = "";
    return [equation](double x) -> double {
        // Простой пример: x^2 - 4
        return x * x - 4;
    };
} 